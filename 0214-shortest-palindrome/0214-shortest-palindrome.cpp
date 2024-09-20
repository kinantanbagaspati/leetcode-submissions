class Solution {
public:
    long long mod = 1e9+7;
    long long pangkat(long long a, long long b){
        a %= mod; b %= (mod-1);
        long long ret = 1;
        while(b){
            if(b%2) ret = ret*a%mod;
            a = a*a%mod; b/=2;
        }
        return ret;
    }
    string shortestPalindrome(string s) {
        long long base = 101, inv = pangkat(base, mod-2);
        //cout << base << "*" << inv << " = " << base * inv % mod << endl;
        long long pb[65536], pi[65536];
        pb[0] = 1; pi[0] = 1;
        for(int i=1; i<65536; i++){
            pb[i] = pb[i-1]*base%mod; pi[i] = pi[i-1]*inv%mod;
        }
        int n = s.length(), ans=1;
        long long sumb[65536], sumi[65536];
        sumb[0] = 0; sumi[0] = 0;
        for(int i=0; i<s.length(); i++){
            sumb[i+1] = (sumb[i] + pb[i] * (s[i]-'a')) % mod;
            sumi[i+1] = (sumi[i] + pi[i] * (s[i]-'a')) % mod;
        }
        for(int i=2; i<=n; i++){
            /*if(i == 7){
                cout << sumi[i/2] << "*" << pb[i/2-1] % mod << endl;
                cout << (sumb[i] + mod - sumb[i-i/2]) << "*" << pi[i-i/2] % mod << endl;
            }*/
            if(sumi[i/2] * pb[i/2-1] % mod == (sumb[i] + mod - sumb[i-i/2]) * pi[i-i/2] % mod) ans = i;
        }
        string ret = "", ad = " ";
        for(int i=s.length()-1; i>=ans; i--){
            ad[0] = s[i]; ret += ad;
        }
        return ret + s;
    }
};