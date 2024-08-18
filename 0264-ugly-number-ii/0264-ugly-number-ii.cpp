class Solution {
public:
    int nthUglyNumber(int n) {
        unsigned int lo = 0, hi = (1<<31);
        while(hi-lo > 1){
            unsigned int mid = (lo+hi)/2, cnt = 0;
            for(unsigned int i=mid; i>0; i/=5){
                for(unsigned int j=i; j>0; j/=3){
                    for(unsigned int k=j; k>0; k/=2) cnt++;
                }
            }
            if(cnt < n){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        return hi;
    }
};