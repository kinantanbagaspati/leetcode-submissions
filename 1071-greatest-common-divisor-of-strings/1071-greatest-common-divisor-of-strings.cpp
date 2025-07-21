class Solution {
public:
    bool isdiv(string s1, string s2){
        if(s2.length() % s1.length() > 0) return false;
        for(int i=0; i<s2.length(); i+=s1.length()){
            if(s2.substr(i, s1.length()) != s1) return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int len1 = str1.length(), len2 = str2.length();
        for(int i=1; i<=__gcd(len1, len2); i++){
            string div = str1.substr(0, i);
            if(isdiv(div, str1) && isdiv(div, str2)) ans = div;
        }
        return ans;
    }
};