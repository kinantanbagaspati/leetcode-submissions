class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0, last[32], cur = 0;
        char vow[5] = {'a', 'i', 'u', 'e', 'o'};
        for(int i=0; i<32; i++) last[i] = (i>0 ? 1e9 : 0);
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<5; j++){
                if(vow[j] == s[i]) cur ^= (1<<j);
            }
            ans = max(i + 1 - last[cur], ans);
            last[cur] = min(i+1, last[cur]);
        }
        return ans;
    }
};