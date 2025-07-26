class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0){
                ans.push_back(asteroids[i]); continue;
            }
            while(ans.size()>0 && 0<ans[ans.size()-1] && ans[ans.size()-1] < -asteroids[i]){
                ans.pop_back();
            }
            if(ans.size()==0 || ans[ans.size()-1] < 0){
                ans.push_back(asteroids[i]);
            }else if(ans[ans.size()-1] == -asteroids[i]){
                ans.pop_back();
            }
        }
        return ans;
    }
};