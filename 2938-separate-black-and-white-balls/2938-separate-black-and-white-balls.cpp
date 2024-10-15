class Solution {
public:
    long long minimumSteps(string s) {
        long long pos = 0, ans = 0;
        for(long long i=0; i<s.length(); i++){
            if(s[i] == '0'){
                ans += i-pos; pos++;
            }
        }
        return ans;
    }
};