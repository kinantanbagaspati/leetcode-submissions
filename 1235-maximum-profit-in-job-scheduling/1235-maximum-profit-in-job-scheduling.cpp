class Solution {
public:
    vector<int> jobEnd[1<<17]; // jobEnd[i] isinya semua job id yg endTime[jobId] == i
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // bikin shg timevalue dicompress jadi bernilai 0..1e5
        int jobs = startTime.size(), nbmap=0;
        vector<int> srt;
        for(int i=0; i<jobs; i++){
            srt.push_back(startTime[i]); srt.push_back(endTime[i]);
        }
        sort(srt.begin(), srt.end());
        map<int, int> mapping;
        for(int i=0; i<jobs*2; i++){
            if(i==0 || srt[i]!=srt[i-1]){
                mapping[srt[i]] = nbmap; nbmap++;
            }
        }
        // compress by mapping
        for(int i=0; i<jobs; i++){
            startTime[i] = mapping[startTime[i]];
            endTime[i] = mapping[endTime[i]];
            jobEnd[endTime[i]].push_back(i);
        }

        int dp[1<<17]; // dp[i] menyatakan maxprofit dengan ambil2 job waktu dlm range[0..i] inklusif
        dp[0] = 0;
        for(int i=1; i<(1<<17); i++){
            dp[i] = dp[i-1];
            // iterate semua job yg berakhir saat itu
            for(int j=0; j<jobEnd[i].size(); j++){
                int k = jobEnd[i][j];
                dp[i] = max(dp[startTime[k]] + profit[k], dp[i]);
            }
        }
        return dp[(1<<17)-1];
    }
};