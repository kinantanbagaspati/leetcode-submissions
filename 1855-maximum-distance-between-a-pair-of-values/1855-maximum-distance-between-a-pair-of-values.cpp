class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        /*vector<pair<int, int>> srt1, srt2;
        for(int i=0; i<sz1; i++) srt1.push_back({nums1[i], i});
        sort(srt1.begin(), srt1.end());
        for(int i=0; i<sz2; i++) srt2.push_back({nums2[i], i});
        sort(srt2.begin(), srt2.end());*/
        int j=0, ans=0;
        for(int i=0; i<sz1; i++){
            while(j<sz2 && nums2[j]>=nums1[i]) j++;
            ans = max(j-1-i, ans);
        }
        return ans;
    }
};