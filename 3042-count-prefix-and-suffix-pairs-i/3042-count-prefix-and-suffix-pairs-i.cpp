class Solution {
public:
    bool isPreSuf(string str1, string str2){
        return str2.length() >= str1.length() && str1 == str2.substr(0, str1.length()) 
        && str1 == str2.substr(str2.length()-str1.length(), str1.length());
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                ans += isPreSuf(words[i], words[j]);
            }
        }
        return ans;
    }
};