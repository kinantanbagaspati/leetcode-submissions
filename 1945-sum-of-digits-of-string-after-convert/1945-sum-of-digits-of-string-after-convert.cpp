class Solution {
public:

    int getLucky(string s, int k) {
        k--;
        int ans = 0;
        for(int i=0; i<s.length(); i++) ans += (s[i]-'a'+1)/10 + (s[i]-'a'+1)%10;
        while(k--){
            int cur = ans; ans = 0;
            while(cur){ans += cur%10; cur /= 10;}
        }
        return ans;
    }
};