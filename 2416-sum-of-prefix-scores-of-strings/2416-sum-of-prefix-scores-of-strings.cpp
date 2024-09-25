class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> child[32], leaf; // 26 for parent, 27 for value
        for(int i=0; i<=27; i++) child[i].push_back(i<27 ? -1 : 0);
        int nbnodes = 1;
        for(int i=0; i<words.size(); i++){
            int curnode = 0;
            for(int j=0; j<words[i].length(); j++){
                if(child[words[i][j] - 'a'][curnode] < 0){
                    child[words[i][j] - 'a'][curnode] = nbnodes;
                    for(int i=0; i<26; i++) child[i].push_back(-1);
                    child[26].push_back(curnode); child[27].push_back(0);
                    nbnodes++;
                }
                curnode = child[words[i][j] - 'a'][curnode];
                //cout << curnode << " < " << child[27].size() << endl;
                child[27][curnode]++;
            }
            leaf.push_back(curnode);
        }
        for(int i=0; i<leaf.size(); i++){
            int curnode = leaf[i]; leaf[i] = 0;
            while(curnode > 0){
                leaf[i] += child[27][curnode]; curnode = child[26][curnode];
            }
        }
        return leaf;
    }
};