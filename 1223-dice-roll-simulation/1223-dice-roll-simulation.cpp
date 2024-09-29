const int mod = 1e9+7;
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // bikin rollMax 1-index
        rollMax.push_back(rollMax[5]);
        for(int i=5; i>0; i--) rollMax[i] = rollMax[i-1];
        
        int dp[5050][8][16]; 
        // dp[i][j][k] merupakan banyak cara roll i kali shg roll terakhir nilainya j,
        // dan k roll terakhir itu j
        for(int i=0; i<5050; i++){
            for(int j=0; j<8; j++){
                for(int k=0; k<16; k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        for(int i=1; i<=6; i++) dp[1][i][1] = 1;
        for(int i=2; i<=n; i++){ //roll ke-i
            int sum[8]; // sum[j(1..6)] itu jumlah semua dp[i-1][j][1..15]
            sum[0] = 0; // sum[0] itu jumlah semua bil di dp sebelunmya
            for(int j=1; j<=6; j++){
                sum[j] = 0;
                for(int k=1; k<=rollMax[j]; k++){
                    sum[0] = (sum[0] + dp[i-1][j][k]) % mod;
                    sum[j] = (sum[j] + dp[i-1][j][k]) % mod;
                }
                //cout << sum[j] << " ";
            }
            //cout << " = " << sum[0] << endl;

            for(int j=1; j<=6; j++){ // roll ke-i bernilai j
                dp[i][j][1] = (sum[0] + mod - sum[j]) % mod;
                for(int k=2; k<= rollMax[j]; k++){
                    dp[i][j][k] = dp[i-1][j][k-1];
                }
            }
        }
        int ans = 0;
        for(int j=1; j<=6; j++){
            for(int k=1; k<=rollMax[j]; k++){
                ans = (ans + dp[n][j][k]) % mod;
            }
        }
        return ans;
    }
};