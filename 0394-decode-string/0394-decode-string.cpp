class Solution {
public:
    string decodeString(string s) {
        vector<string> ss;
        ss.push_back("");
        vector<int> ms;
        for(int i=0; i<s.length(); i++){
            if('a' <= s[i] && s[i] <= 'z'){
                ss[ss.size()-1] += s[i];
            }else if(s[i] == '['){
                int mul = 0, pw10 = 1;
                for(int j=i-1; j>=0 && '0'<=s[j] && s[j]<='9'; j--){
                    mul += pw10 * (s[j]-'0'); pw10 *= 10;
                }
                ss.push_back(""); ms.push_back(mul);
            }else if(s[i] == ']'){
                for(int i=0; i<ms[ms.size()-1]; i++){
                    ss[ss.size()-2] += ss[ss.size()-1];
                }
                ss.pop_back(); ms.pop_back();
            }
        }
        return ss[0];
    }
};