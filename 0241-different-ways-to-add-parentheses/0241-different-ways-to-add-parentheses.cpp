class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0; i<expression.length(); i++){
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
                vector<int> kiri = diffWaysToCompute(expression.substr(0,i));
                vector<int> kanan = diffWaysToCompute(expression.substr(i+1, expression.length()-i-1));
                for(int j=0; j<kiri.size(); j++){
                    for(int k=0; k<kanan.size(); k++){
                        ans.push_back(expression[i]=='+' ? kiri[j]+kanan[k] : expression[i]=='-' 
                        ? kiri[j]-kanan[k] : kiri[j]*kanan[k]);
                    }
                }   
            }
        }
        if(ans.size() == 0){
            int num = 0;
            for(int i=0; i<expression.length(); i++) num = num*10 + (expression[i]-'0');
            ans.push_back(num);
        }
        return ans;
    }
};