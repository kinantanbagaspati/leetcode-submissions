class Solution {
public:
    int longestPalindrome(string s) {
        int freq[64];
        for(int i=0; i<64; i++) freq[i] = 0;
        for(int i=0; i<s.length(); i++){
            freq[s[i]-'A']++;
        }
        int ans = 0, mx = 0;
        for(int i=0; i<64; i++){
            ans += freq[i]/2; mx = max(freq[i]%2, mx);
        }
        return ans * 2 + mx;
    }
};