class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<int> coor; coor.push_back(rStart); coor.push_back(cStart);
        ans.push_back(coor);
        for(int i=1; ans.size() < rows * cols; i++){
            if(i%2){
                for(int j=0; j<i; j++){
                    coor[1]++;
                    if(0<=coor[0] && coor[0]<rows && 0<=coor[1] && coor[1]<cols) ans.push_back(coor);
                }
                for(int j=0; j<i; j++){
                    coor[0]++;
                    if(0<=coor[0] && coor[0]<rows && 0<=coor[1] && coor[1]<cols) ans.push_back(coor);
                }
            }else{
                for(int j=0; j<i; j++){
                    coor[1]--;
                    if(0<=coor[0] && coor[0]<rows && 0<=coor[1] && coor[1]<cols) ans.push_back(coor);
                }
                for(int j=0; j<i; j++){
                    coor[0]--;
                    if(0<=coor[0] && coor[0]<rows && 0<=coor[1] && coor[1]<cols) ans.push_back(coor);
                }
            }
        }
        return ans;
    }
};