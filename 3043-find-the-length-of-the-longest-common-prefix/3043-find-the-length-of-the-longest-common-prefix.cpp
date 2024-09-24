class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<int> srt1, srt2;
        for(int i=0; i<arr1.size(); i++){
            while(arr1[i]){
                srt1.push_back(arr1[i]); arr1[i] /= 10;
            }
        }
        for(int i=0; i<arr2.size(); i++){
            while(arr2[i]){
                srt2.push_back(arr2[i]); arr2[i] /= 10;
            }
        }
        sort(srt1.begin(), srt1.end());
        sort(srt2.begin(), srt2.end());
        int idx = 0, mx = 0, ans = 0;
        for(int i=0; i<srt1.size(); i++){
            while(idx < srt2.size() && srt2[idx] < srt1[i]) idx++;
            if(idx < srt2.size() && srt2[idx] == srt1[i]) mx = srt1[i];
        }
        while(mx){
            mx /= 10; ans++;
        }
        return ans;
    }
};