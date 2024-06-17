class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0; i*i<=c; i++){
            long long j=sqrt(c-i*i);
            for(int k=-1; k<=1; k++){
                if(i*i+(j+k)*(j+k) == c) return true;
            }
        }
        return false;
    }
};