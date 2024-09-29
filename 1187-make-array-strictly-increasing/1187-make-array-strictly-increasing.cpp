class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // compact
        vector<int> srt;
        for(int i=0; i<arr1.size(); i++) srt.push_back(arr1[i]);
        for(int i=0; i<arr2.size(); i++) srt.push_back(arr2[i]);
        sort(srt.begin(), srt.end());
        map<int, int> mapping;
        int curmap = 1;
        for(int i=0; i<srt.size(); i++){
            if(i==0 || srt[i]!=srt[i-1]){
                mapping[srt[i]] = curmap; curmap++;
            }
        }
        // mapping
        for(int i=0; i<arr1.size(); i++) arr1[i] = mapping[arr1[i]];
        bool repvalue[4096]; // repvalue[i] = true kalo i merupakan salah satu value yg present di arr2
        for(int i=0; i<4096; i++) repvalue[i] = false;
        for(int i=0; i<arr2.size(); i++) repvalue[mapping[arr2[i]]] = true;

        int dp[arr1.size()][4096]; // dp[i][j] apakah operasi(arr1[0...i]) -> arrinc [-1] == j
        for(int i=0; i<4096; i++){
            if(i == arr1[0]){
                dp[0][i] = 0;
            }else if(repvalue[i]){
                dp[0][i] = 1;
            }else{
                dp[0][i] = -1;
            }
        }
        for(int i=1; i<arr1.size(); i++){
            int minrep = -1; // minrep menyatakan rep minimum yg diapp arr1[0..i-1] -> arrinc [-1] < j
            for(int j=0; j<4096; j++){
                if(minrep >= 0){
                    if(j == arr1[i]){
                        dp[i][j] = minrep;
                    }else if(repvalue[j]){
                        dp[i][j] = minrep+1;
                    }else{
                        dp[i][j] = -1;
                    }
                }else{
                    dp[i][j] = -1;
                }
                if(dp[i-1][j] >= 0 && (minrep < 0 || dp[i-1][j] < minrep)) minrep = dp[i-1][j];
            }
        }
        int ans = -1;
        for(int i=0; i<4096; i++){
            if(dp[arr1.size()-1][i] >= 0 && (ans < 0 || dp[arr1.size()-1][i] < ans)){
                ans = dp[arr1.size()-1][i];
            }
        }
        return ans;
    }
};