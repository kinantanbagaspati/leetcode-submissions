class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n = grid[0].size(), atas = 0, bawah = 0, ans;
        for(int i=0; i<n-1; i++) bawah += grid[1][i];
        ans = bawah;
        for(int i=n-1; i>0; i--){
            atas += grid[0][i]; bawah -= grid[1][i-1];
            ans = min(max(atas, bawah), ans);
        } 
        return ans;
    }
};