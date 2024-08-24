class Solution {
public:
    string toStr(long long x){
        if(x == 0) return "0";
        string n = "";
        while(x > 0){
            n += "0";
            n[n.length()-1] += x%10;
            x /= 10;
        }
        reverse(n.begin(), n.end());
        return n;
    }
    string revStr(string n){
        string res = n;
        reverse(res.begin(), res.end());
        return res;
    }
    long long revInt(long long x){
        return toInt(revStr(toStr(x)));
    }
    long long toInt(string n){
        long long x = 0;
        for(int i=0; i<n.length(); i++) x = x*10 + (n[i]-'0');
        return x;
    }
    string nearestPalindromic(string n) {
        if(n.length() == 1){
            n[0]--; return n;
        }
        long long m = toInt(n), pw = 1;
        for(int i=0; i<n.length()/2; i++) pw *= 10;
        pair<long long, long long> ans = {1e18, 0}; 
        if(n.length() % 2){ // panjang n ganjil
            long long comp = m/pw*pw + revInt(m/pw/10);
            if(comp != m) ans = min(ans, {abs(comp-m), comp});
            if(m/pw == pw){
                comp = pw*pw-1;
            }else{
                comp = (m/pw-1)*pw + revInt((m/pw-1)/10);
            }
            ans = min(ans, {abs(comp-m), comp});
            if(m/pw+1 != pw*10){
                comp = (m/pw+1)*pw + revInt((m/pw+1)/10);
            }else{
                comp = pw*pw*10+1;
            }
            ans = min(ans, {abs(comp-m), comp});
        }else{ // panjang n genap
            long long comp = m/pw*pw + revInt(m/pw);
            if(comp != m) ans = min(ans, {abs(comp-m), comp});
            //cout << ans.first << "," << ans.second << endl;
            if(m/pw == pw/10){
                comp = pw*pw/10-1;
            }else{
                comp = (m/pw-1)*pw + revInt(m/pw-1);
            }
            ans = min(ans, {abs(comp-m), comp});
            //cout << ans.first << "," << ans.second << endl;
            if(m/pw+1 != pw){
                comp = (m/pw+1)*pw + revInt(m/pw+1);
            }else{
                comp = pw*pw+1;
            }
            ans = min(ans, {abs(comp-m), comp});
        }
        return toStr(ans.second);
    }
};