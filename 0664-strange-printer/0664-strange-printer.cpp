class Solution {
public:
    int strangePrinter(string s) {
        string coms = "";
        for(int i=0; i<s.length(); i++){
            if(i == 0 || s[i] != s[i-1]){
                coms += " "; coms[coms.length()-1] = s[i];
            }
        }
        int dp[coms.length()+1][coms.length()+1];
        cout << coms << endl;
        for(int i=0; i<=coms.length(); i++){
            dp[i][i] = 0;
            if(i) dp[i-1][i] = 1;
        }
        for(int i=2; i<=coms.length(); i++){
            for(int j=0; j+i <= coms.length(); j++){
                vector<int> idxs, vdp;
                for(int k=j; k<j+i; k++){
                    if(coms[k] != coms[j]) idxs.push_back(k);
                }
                /*cout << j << "," << j+i << ":";
                for(int k=0; k<idxs.size(); k++) cout << " " << idxs[k];
                cout << endl;*/
                vdp.push_back(0);
                for(int k=0; k<idxs.size(); k++){
                    vdp.push_back(dp[idxs[0]][idxs[k]+1]);
                    for(int m=1; m<=k; m++){
                        vdp[k+1] = min(vdp[m]+dp[idxs[m]][idxs[k]+1], vdp[k+1]);
                    }
                }
                dp[j][j+i] = vdp[idxs.size()]+1;
                //cout << "dp " << dp[j][j+i] << endl;
                idxs.clear(); vdp.clear();
                for(int k=j; k<j+i; k++){
                    if(coms[k] != coms[j+i-1]) idxs.push_back(k);
                }
                vdp.push_back(0);
                for(int k=0; k<idxs.size(); k++){
                    vdp.push_back(dp[idxs[0]][idxs[k]+1]);
                    for(int m=1; m<=k; m++){
                        vdp[k+1] = min(vdp[m]+dp[idxs[m]][idxs[k]+1], vdp[k+1]);
                    }
                }
                dp[j][j+i] = min(dp[j][j+i], vdp[idxs.size()]+1);
                //cout << "dp " << dp[j][j+i] << endl;
            }
        }
        return dp[0][coms.length()];
    }
};