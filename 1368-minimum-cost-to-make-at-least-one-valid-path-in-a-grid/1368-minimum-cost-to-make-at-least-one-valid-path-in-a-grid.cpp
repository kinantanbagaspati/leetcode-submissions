class Solution {
public:
    int dis[1<<7][1<<7];
    //queue<pair<int, int>> qs[1<<14]; 
    set<pair<int, pair<int, int> > > pq; // buat distance, absis, ordinat
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // inisiasi distance inf
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dis[i][j] = 1e9;
            }
        }
        dis[0][0] = 0;
        pq.insert({0, {0,0}});
        while(pq.size()){
            int curdis = pq.begin()->first;
            pair<int, int> head = pq.begin()->second;
            int x = head.first, y = head.second;
            cout << curdis << " " << x << "," << y << endl;
            pq.erase(pq.begin());
            // expand node head nya
            if(y < m-1){ // ada node di kanan
                if(curdis + (grid[x][y] != 1) < dis[x][y+1]){ // distance nya lebih kecil
                    pq.erase({dis[x][y+1], {x, y+1}});
                    dis[x][y+1] = curdis + (grid[x][y] != 1);
                    pq.insert({dis[x][y+1], {x, y+1}});
                }
            }
            if(y > 0){ // ada node di kiri
                if(curdis + (grid[x][y] != 2) < dis[x][y-1]){ // distance nya lebih kecil
                    pq.erase({dis[x][y-1], {x, y-1}});
                    dis[x][y-1] = curdis + (grid[x][y] != 2);
                    pq.insert({dis[x][y-1], {x, y-1}});
                }
            }
            if(x < n-1){ // bawah
                if(curdis + (grid[x][y] != 3) < dis[x+1][y]){ // distance nya lebih kecil
                    pq.erase({dis[x+1][y], {x+1, y}});
                    dis[x+1][y] = curdis + (grid[x][y] != 3);
                    pq.insert({dis[x+1][y], {x+1, y}});
                }
            }
            if(x > 0){ // ada node di atas
                if(curdis + (grid[x][y] != 4) < dis[x-1][y]){ // distance nya lebih kecil
                    pq.erase({dis[x-1][y], {x-1, y}});
                    dis[x-1][y] = curdis + (grid[x][y] != 4);
                    pq.insert({dis[x-1][y], {x-1, y}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};