class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if(ans < t.length() && s[i] == t[ans]) ans++;
        }
        return t.length() - ans;
    }
};