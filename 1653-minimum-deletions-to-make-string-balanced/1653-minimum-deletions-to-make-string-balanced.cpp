class Solution {
public:
    int minimumDeletions(string s) {
        int as=0, bs=0;
        for(int i=0; i<s.length(); i++) bs += (s[i]=='a');
        int ans=bs;
        for(int i=0; i<s.length(); i++){
            as += (s[i]=='b'); bs -= (s[i]=='a');
            ans=min(ans, as+bs);
        }
        return ans;
    }
};