class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx0 = (arrays[0][arrays[0].size()-1] < arrays[1][arrays[1].size()-1]), mx1 = !mx0;
        int mn0 = (arrays[0][0] > arrays[1][0]), mn1 = !mn0;
        for(int i=2; i<arrays.size(); i++){
            if(arrays[i][arrays[i].size()-1] > arrays[mx0][arrays[mx0].size()-1]){
                mx1 = mx0; mx0 = i;
            }else if(arrays[i][arrays[i].size()-1] > arrays[mx1][arrays[mx1].size()-1]){
                mx1 = i;
            }
            if(arrays[i][0] < arrays[mn0][0]){
                mn1 = mn0; mn0 = i;
            }else if(arrays[i][0] < arrays[mn1][0]){
                mn1 = i;
            }
        }
        return (mn0 == mx0)? max(
            arrays[mx0][arrays[mx0].size()-1] - arrays[mn1][0],
            arrays[mx1][arrays[mx1].size()-1] - arrays[mn0][0]    
        ) : arrays[mx0][arrays[mx0].size()-1] - arrays[mn0][0];
    }
};