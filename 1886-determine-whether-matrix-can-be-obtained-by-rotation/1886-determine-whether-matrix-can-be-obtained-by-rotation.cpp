class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i=0; i<4; i++){
            bool bisa = true;
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    bisa = bisa && (mat[j][k] == target[j][k]);
                }
            }
            if(bisa) return true;
            for(int j=0; j<n/2; j++){
                for(int k=0; k<(n+1)/2; k++){
                    int temp = mat[j][k];
                    mat[j][k] = mat[k][n-1-j];
                    mat[k][n-1-j] = mat[n-1-j][n-1-k];
                    mat[n-1-j][n-1-k] = mat[n-1-k][j];
                    mat[n-1-k][j] = temp;
                }
            }
        }
        return false;
    }
};