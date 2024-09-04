class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int arah = 0, curx = 0, cury = 0, ans = 0;
        set<pair<int, int>> s;
        for(int i=0; i<obstacles.size(); i++) s.insert({obstacles[i][0], obstacles[i][1]});
        for(int i=0; i<commands.size(); i++){
            if(commands[i] == -2){
                arah = (arah+3)%4;
            }else if(commands[i] == -1){
                arah = (arah+1)%4;
            }else{
                while(commands[i]--){
                    int nx = curx + (arah == 1) - (arah == 3);
                    int ny = cury + (arah == 0) - (arah == 2);
                    if(s.lower_bound({nx, ny}) != s.end() &&
                    *(s.lower_bound({nx, ny})) == make_pair(nx, ny)){
                        break;
                    }else{
                        curx = nx; cury = ny;
                    }
                }
            }
            ans = max(curx*curx + cury*cury, ans);
            cout << curx << " " << cury << " " << arah << endl;
        }
        return ans;
    }
};