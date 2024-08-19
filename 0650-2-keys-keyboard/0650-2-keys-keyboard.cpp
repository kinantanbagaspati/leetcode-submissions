class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int ans = 0;
        for(int i=2; i*i<=n; i++){
            while(n%i==0){
                ans += i; n /= i;
            }
        }
        return ans + n * (n>1);
    }
};