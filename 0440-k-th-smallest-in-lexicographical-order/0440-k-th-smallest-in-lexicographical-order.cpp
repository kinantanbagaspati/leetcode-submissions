class Solution {
public:
    int findKthNumber(int n, int k) {
        int pow10[10];
        pow10[0] = 1;
        for(int i=1; i<10; i++) pow10[i] = pow10[i-1]*10;
        string sn = "", ad = " ", ans = "1";
        for(int i=n; i>0; i/=10){
            ad[0] = '0' + i%10; sn += ad;   
        }
        reverse(sn.begin(), sn.end());
        string subn[sn.length()+1];
        for(int i=1; i<=sn.length(); i++){
            subn[i] = sn.substr(0, i);
        }
        k--;
        while(k > 0){
            //cout << k << ", ans = " << ans << endl;
            int sum = (pow10[sn.length() - ans.length()]) / 9;
            if(ans == subn[ans.length()]){
                sum += n % pow10[sn.length() - ans.length()] + 1;
            }else if(ans < subn[ans.length()]){
                sum += pow10[sn.length() - ans.length()];
            }
            // klo banyaknya str yg suffixnya ans masih kurg dari k
            if(sum <= k){
                k -= sum;
                ans[ans.length()-1]++;
            }else{
                k--;
                ans += "0";
            }
        }
        int ret = 0;
        for(int i=0; i<ans.length(); i++){
            ret = ret*10 + (ans[i]-'0');
        }
        return ret;
    }
};