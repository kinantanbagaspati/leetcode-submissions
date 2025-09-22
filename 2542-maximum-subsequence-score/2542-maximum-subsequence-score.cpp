class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        multiset<long long> gede;
        long long sumgede = 0;
        pair<long long, long long> srt[1<<17];
        for(int i=0; i<n; i++){
            srt[i] = {nums2[i], i};
        }
        sort(srt, srt+n);
        for(int i=1; i<=k; i++){
            gede.insert(nums1[srt[n-i].second]);
            sumgede += nums1[srt[n-i].second];
        }
        long long ans = nums2[srt[n-k].second] * sumgede;
        for(int i=n-k-1; i>=0; i--){
            if(nums1[srt[i].second] > *(gede.begin())){
                sumgede += nums1[srt[i].second] - *(gede.begin());
                gede.erase(gede.begin());
                gede.insert(nums1[srt[i].second]);
            }
            //cout << sumgede << " * " << nums2[i] << endl;
            ans = max(sumgede * nums2[srt[i].second], ans);
        }
        return ans;
    }
};