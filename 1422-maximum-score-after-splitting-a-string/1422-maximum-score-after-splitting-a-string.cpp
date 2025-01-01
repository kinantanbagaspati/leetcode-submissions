class Solution {
public:
    int maxScore(string s) {
        int ans = 0, zeros = 0,  ones = 0;
        for(int i=0; i<s.length(); i++) ones += (s[i] == '1');
        //ans = ones;
        for(int i=0; i+1<s.length(); i++){
            zeros += (s[i] == '0');
            ones -= (s[i] == '1');
            ans = max(zeros + ones, ans);
        }
        return ans;
    }
};