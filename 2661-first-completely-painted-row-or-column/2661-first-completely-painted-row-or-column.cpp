class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int colorInRow[n], colorInCol[m];
        pair<int, int> pos[n*m+1];
        for(int i=0; i<n; i++) colorInRow[i] = 0;
        for(int i=0; i<m; i++) colorInCol[i] = 0;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) pos[mat[i][j]] = {i, j}; // mapping posisi
        for(int i=0; i<n*m; i++){
            int x = pos[arr[i]].first, y = pos[arr[i]].second;
            // di barus x kolom y
            colorInRow[x]++;
            if(colorInRow[x] == m) return i;
            colorInCol[y]++;
            if(colorInCol[y] == n) return i;
        }
        return n*m;
    }
};