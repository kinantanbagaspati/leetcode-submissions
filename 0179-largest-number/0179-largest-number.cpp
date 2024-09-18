class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstr;
        string num, ch = "0", ans = "";
        for(int i=0; i<nums.size(); i++){
            num = (nums[i] ? "" : "0");
            while(nums[i]){
                ch[0] = '0' + nums[i] % 10;
                num += ch; nums[i] /= 10;
            }
            reverse(num.begin(), num.end());
            numstr.push_back(num);
            for(int j=numstr.size()-1; j>0 && num+numstr[j-1] > numstr[j-1]+num; j--){
                numstr[j] = numstr[j-1]; numstr[j-1] = num;
            }
        }
        //sort(numstr.begin(), numstr.end());
        for(int i=0; i<numstr.size(); i++) ans += numstr[i];
        int idx = 0;
        while(idx<ans.length()-1 && ans[idx] == '0') idx++;
        return ans.substr(idx, ans.length()-idx);
    }
};