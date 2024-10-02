class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return arr;
        vector<pair<int, int>> srt;
        for(int i=0; i<arr.size(); i++) srt.push_back({arr[i], i});
        sort(srt.begin(), srt.end());
        int cur = 1;
        arr[srt[0].second] = cur;
        for(int i=1; i<srt.size(); i++){
            cur += (srt[i].first != srt[i-1].first);
            arr[srt[i].second] = cur;
        }
        return arr;
    }
};