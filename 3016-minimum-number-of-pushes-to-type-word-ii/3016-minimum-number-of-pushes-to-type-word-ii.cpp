class Solution {
public:
    int minimumPushes(string word) {
        int freq[26], ans=0;
        for(int i=0; i<26; i++) freq[i] = 0;
        for(int i=0; i<word.length(); i++){
            freq[word[i]-'a']--;
        }
        sort(freq, freq+26);
        for(int i=0; i<26; i++) ans -= (i/8+1)*freq[i];
        return ans;
    }
};