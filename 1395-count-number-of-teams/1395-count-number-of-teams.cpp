class Solution {
public:
    int segtree[2][2048];
    void update(int id, int idx, int val){
        idx += 1024;
        while(idx){
            segtree[id][idx] += val; idx /= 2;
        }
    }
    int query(int id, int lo, int hi){
        lo += 1024; hi += 1024;
        int ret = 0;
        while(lo <= hi){
            if(lo%2==1) ret += segtree[id][lo];
            lo = (lo+1)/2;
            if(hi%2==0) ret += segtree[id][hi];
            hi = (hi-1)/2;
        }
        return ret;
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        pair<int, int> srt[n];
        for(int i=0; i<n; i++) srt[i] = {rating[i], i};
        sort(srt, srt+n);
        for(int i=0; i<n; i++) rating[srt[i].second] = i;
        for(int i=0; i<n; i++) update(1, rating[i], 1);
        int ans = 0;
        for(int i=0; i<n; i++){
            update(1, rating[i], -1);
            ans += query(0, 0, rating[i]-1) * query(1, rating[i]+1, 1023);
            ans += query(1, 0, rating[i]-1) * query(0, rating[i]+1, 1023);
            update(0, rating[i], 1);
        }
        return ans;
    }
};