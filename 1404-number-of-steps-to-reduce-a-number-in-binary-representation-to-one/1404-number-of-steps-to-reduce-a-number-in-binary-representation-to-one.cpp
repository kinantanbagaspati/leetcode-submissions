class Solution {
public:
    int numSteps(string s) {
        int ans = 0, idx = s.length()-1;
        while(idx > 0){
            if(s[idx] == '1'){
                int cur = idx;
                while(cur >= 0 && s[cur] == '1'){
                    s[cur] = '0'; cur--;
                } ans++;
                if(cur < 0){
                    s = "1" + s; idx++;
                }else{
                    s[cur] = '1';
                }
            }else{
                ans++; idx--;
            }
        }
        return ans;
    }
};