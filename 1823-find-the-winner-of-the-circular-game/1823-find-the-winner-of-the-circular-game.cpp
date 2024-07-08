class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1) return 1;
        int ans = findTheWinner(n-1, k);
        return (k+ans+n-1) % n + 1;
    }
};