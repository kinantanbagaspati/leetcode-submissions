class Solution {
public:
    vector<int> rs, ds;
    vector<bool> can;
    int rh = 0, dh = 0;
    string predictPartyVictory(string senate) {
        for(int i=0; i<senate.length(); i++){
            if(senate[i] == 'R'){
                rs.push_back(i);
            }else{
                ds.push_back(i);
            }
            can.push_back(true);
        }
        int prev = -1, n = senate.size();
        while(rh < rs.size() && dh < ds.size()){
            int rdif = (rs[rh] + n - prev) % n, ddif = (ds[dh] + n - prev) % n;
            if(rdif == 0) rdif = n;
            if(ddif == 0) ddif = n; 
            if(rdif < ddif){
                rs.push_back(rs[rh]); prev = rs[rh];
            }else{
                ds.push_back(ds[dh]); prev = ds[dh];
            }
            rh++; dh++;
        }
        return (rh < rs.size() ? "Radiant" : "Dire");
    }
};