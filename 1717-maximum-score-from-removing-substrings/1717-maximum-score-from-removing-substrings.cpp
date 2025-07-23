class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length(), tunjuk[1<<17][2];
        bool vis[1<<17];
        multiset<pair<int, pair<int, int>>> ms;
        for(int i=0; i<n; i++){
            tunjuk[i][0] = i-1; tunjuk[i][1] = i+1;
            vis[i] = false;
            if(i<n-1){
                if(s[i]=='a' && s[i+1]=='b') ms.insert({-x, {i,i+1}});
                if(s[i]=='b' && s[i+1]=='a') ms.insert({-y, {i,i+1}});
            }
        }
        int ans = 0;
        while(ms.size()){
            int skor = ms.begin()->first;
            int kiri = ms.begin()->second.first;
            int kanan = ms.begin()->second.second;
            ms.erase(ms.begin());
            if(!vis[kiri] && !vis[kanan]){
                ans -= skor;
                vis[kiri] = true; vis[kanan] = true;
                int lo = tunjuk[kiri][0], hi = tunjuk[kanan][1];
                if(lo >= 0) tunjuk[lo][1] = hi;
                if(hi < n) tunjuk[hi][0] = lo;
                if(lo >= 0 && hi < n){
                    if(s[lo]=='a' && s[hi]=='b') ms.insert({-x, {lo,hi}});
                    if(s[lo]=='b' && s[hi]=='a') ms.insert({-y, {lo,hi}});
                }
            }
        }
        return ans;
    }
};