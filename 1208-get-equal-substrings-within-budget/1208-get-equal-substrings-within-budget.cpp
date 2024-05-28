class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0, lo=0, hi=0, cost=0;
        while(hi < s.length()){
            if(cost > maxCost){
                cost -= abs(s[lo]-t[lo]); lo++;
            }else{
                cost += abs(s[hi]-t[hi]); hi++;
            }
            if(cost <= maxCost) ans = max(hi-lo, ans);
        }
        return ans;
    }
};