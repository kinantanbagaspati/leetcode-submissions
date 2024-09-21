class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        for(int i=1; i<=n; i++){
            int cpy = i;
            string s = "", ad = " ";
            while(cpy){
                ad[0] = '0' + cpy%10; 
                s += ad;
                cpy /= 10;
            }
            reverse(s.begin(), s.end());
            // cout << s << " ";
            v.push_back(s);
        } // cout << endl;
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i=0; i<n; i++){
            int x = 0;
            for(int j=0; j<v[i].length(); j++){
                x = x*10 + (v[i][j] - '0');
            }
            ans.push_back(x);
        }
        return ans;
    }
};