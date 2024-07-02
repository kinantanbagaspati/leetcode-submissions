class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1024][2];
        for(int i=0; i<1024; i++){
            freq[i][0]=0; freq[i][1]=0;
        }
        for(int i=0; i<nums1.size(); i++) freq[nums1[i]][0]++;
        for(int i=0; i<nums2.size(); i++) freq[nums2[i]][1]++;
        vector<int> ans;
        for(int i=0; i<1024; i++){
            int cnt = min(freq[i][0], freq[i][1]);
            while(cnt--) ans.push_back(i);
        }
        return ans;
    }
};