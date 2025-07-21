class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int batas = min(word1.length(), word2.length());
        for(int i=0; i<batas; i++){
            ans += word1[i]; ans += word2[i];
        }
        for(int i=batas; i<word1.length(); i++) ans += word1[i];
        for(int i=batas; i<word2.length(); i++) ans += word2[i];
        return ans;
    }
};