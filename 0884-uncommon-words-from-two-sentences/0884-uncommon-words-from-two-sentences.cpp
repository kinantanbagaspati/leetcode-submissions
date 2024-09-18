class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word = "", ch = " ";
        vector<string> temp, ans;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] == ' '){
                temp.push_back(word); word = "";
            }else{
                ch[0] = s1[i]; word += ch;
            }
        }
        temp.push_back(word); word = "";
        for(int i=0; i<s2.length(); i++){
            if(s2[i] == ' '){
                temp.push_back(word); word = "";
            }else{
                ch[0] = s2[i]; word += ch;
            }
        }
        temp.push_back(word);
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++){
            if((i==0 || temp[i-1] != temp[i]) && (i==temp.size()-1 || temp[i] != temp[i+1])) ans.push_back(temp[i]);
        }
        return ans;
    }
};