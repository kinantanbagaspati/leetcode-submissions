class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries[0].length();
        for(int i=0; i<queries.size(); i++){
            bool match = false;
            for(int j=0; j<dictionary.size(); j++){
                int diff = 0;
                for(int k=0; k<n; k++) diff += (queries[i][k] != dictionary[j][k]);
                match = match || (diff <= 2);
            }
            if(match) ans.push_back(queries[i]);
        }
        return ans;
    }
};