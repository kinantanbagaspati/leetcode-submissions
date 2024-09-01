class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        vector<int> row;
        if(original.size() != m*n) return ans;
        row.resize(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) row[j] = original[i*n+j];
            ans.push_back(row);
        }
        return ans;
    }
};