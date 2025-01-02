class Solution {
public:
    set<char> vowels;
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vowels.insert('a');  vowels.insert('i');  vowels.insert('u');  vowels.insert('e');  vowels.insert('o');
        vector<int> dp, ans;
        dp.push_back(0);
        for(int i=0; i<words.size(); i++){
            dp.push_back(dp[i] + 
                ((vowels.count(words[i][0]) > 0) 
                && (vowels.count(words[i][words[i].length()-1]) > 0))
            );
        }
        for(int i=0; i<queries.size(); i++){
            ans.push_back(dp[queries[i][1]+1] - dp[queries[i][0]]);
        }
        return ans;
    }
};