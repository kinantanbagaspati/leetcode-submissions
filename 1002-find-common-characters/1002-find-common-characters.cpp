class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> freqs;
        vector<int> freq;
        for(int i=0; i<words.size(); i++){
            freqs.push_back(freq);
            for(int j=0; j<26; j++) freqs[i].push_back(0);
            for(int j=0; j<words[i].size(); j++){
                freqs[i][words[i][j]-'a'] ++;
            }
        }
        for(int i=1; i<freqs.size(); i++){
            for(int j=0; j<26; j++){
                freqs[0][j] = min(freqs[0][j], freqs[i][j]);
            }
        }
        vector<string> ans;
        for(int i=0; i<26; i++){
            string ad = "a"; ad[0] += i;
            while(freqs[0][i] > 0){
                ans.push_back(ad);
                freqs[0][i]--;
            }   
        }
        return ans;
    }
};