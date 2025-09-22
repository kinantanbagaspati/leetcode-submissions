class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long sum = 0;
        for(int i=0; i<n; i++) sum += piles[i];
        if(sum <= h) return 1;

        int lo=1, hi=1e9+7;
        while(hi-lo>1){
            int mid = (lo+hi)/2;
            long long g = 0;
            for(int i=0; i<n; i++){
                g += ((long long)piles[i] + mid - 1) / mid;
            }
            //cout << mid << " " << g << endl;
            if(g > h){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        return hi;
    }
};