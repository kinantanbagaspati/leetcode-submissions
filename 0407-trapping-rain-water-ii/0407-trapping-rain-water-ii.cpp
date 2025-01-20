class Solution {
public:
    bool kerendem[65536];
    int rows, cols, par[65536], card[65536];
    pair<int, int> srt[65536];
    
    int getAncestor(int x){
        while(par[x] != x){
            int nxt = par[x];
            par[x] = par[nxt];
            x = nxt;
        }
        return x;
    }
    void join(int a, int b){
        a = getAncestor(a); b = getAncestor(b);
        if(a == b){
            return;
        }else if(card[a] < card[b]){
            par[a] = b;
            card[b] += card[a];
        }else{
            par[b] = a;
            card[a] += card[b];
        }
    }
    bool isPojok(int i, int j){
        return i==0 || j==0 || i==rows-1 || j==cols-1;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        rows = heightMap.size(), cols = heightMap[0].size();
        //cout << "rc " << rows << " " << cols << endl;
        
        card[rows*cols] = 1;
        par[rows*cols] = rows*cols;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                // init dsu
                kerendem[cols*i + j] = false;
                card[cols*i + j] = 1;
                par[cols*i + j] = cols*i + j;
                srt[cols*i + j] = {heightMap[i][j], cols*i + j};
            }
        }
        sort(srt, srt + rows*cols);
        
        int idx = 0, ans = 0;
        for(int h=0; h<=20000; h++){
            while(idx < rows*cols && srt[idx].first == h){
                int k = srt[idx].second, i = k/cols, j = k%cols;
                kerendem[k] = true;
                if(i>0 && kerendem[k-cols]){
                    join(k, k-cols);
                }
                if(i<rows-1 && kerendem[k+cols]){
                    join(k, k+cols);
                }
                if(j>0 && kerendem[k-1]){
                    join(k, k-1);
                }
                if(j<cols-1 && kerendem[k+1]){
                    join(k, k+1);
                }
                if(isPojok(i, j)){
                    join(k, rows*cols);
                }
                idx++;
            }
            ans += idx - card[getAncestor(rows*cols)] + 1;
            //cout << h << ": " << ans << endl;
        }
        return ans;
    }
};

/*
12 13  1 12
13  4 13 12
13  8 10 12
12 13 12 12
13 13 13 13
*/