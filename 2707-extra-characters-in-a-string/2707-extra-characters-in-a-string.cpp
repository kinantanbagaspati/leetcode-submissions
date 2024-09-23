class Solution {
public:
    const long long mod = 1e9+7;
    long long pangkat(long long a, long long b){
        a %= mod; b %= mod-1;
        long long ret = 1;
        while(b){
            if(b%2) ret = ret*a%mod;
            a = a*a%mod; b /= 2;
        }
        return ret;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        long long base = 101, ibase = pangkat(base, mod-2);
        long long dp[64], pb[64], pib[64]; 
        dp[0] = 0; pb[0] = 1; pib[0] = 1;
        for(int i=0; i<s.length(); i++){
            dp[i+1] = (dp[i] + pb[i] * (s[i]-'a')) % mod;
            pb[i+1] = pb[i] * base % mod;
            pib[i+1] = pib[i] * ibase % mod;
        }
        long long hash[dictionary.size()];
        for(int i=0; i<dictionary.size(); i++){
            hash[i] = 0;
            for(int j=0; j<dictionary[i].length(); j++){
                hash[i] = (pb[j] * (dictionary[i][j] - 'a') + hash[i]) % mod;
            }
        }
        long long ans[64]; ans[0] = 0;
        for(int i=0; i<s.length(); i++){
            ans[i+1] = ans[i] + 1;
            for(int j=0; j<dictionary.size(); j++){
                int len = dictionary[j].length();
                if(len <= i+1){
                    if((dp[i+1] + mod - dp[i+1-len]) * pib[i+1-len] % mod == hash[j]){
                        ans[i+1] = min(ans[i+1-len], ans[i+1]);
                    }
                }
            }
        }
        return ans[s.length()];
    }
};