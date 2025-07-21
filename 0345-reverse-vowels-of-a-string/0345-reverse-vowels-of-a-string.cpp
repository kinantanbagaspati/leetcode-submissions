class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vIdx;
        for(int i=0; i<s.length(); i++){
            if((s[i]-'A')%32==0 || (s[i]-'I')%32==0 || (s[i]-'U')%32==0 || (s[i]-'E')%32==0 || (s[i]-'O')%32==0){
                vIdx.push_back(i);
            }
        }
        for(int i=0; i*2<vIdx.size(); i++){
            swap(s[vIdx[i]], s[vIdx[vIdx.size()-1-i]]);
        }
        return s;
    }
};