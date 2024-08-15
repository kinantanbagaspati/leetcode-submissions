class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int freq[2] = {0, 0};
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                freq[0]++;
            }else if(bills[i] == 10){
                if(!freq[0]) return false;
                freq[0]--; freq[1]++;
            }else{
                if(!freq[1]){
                    if(freq[0] < 3) return false;
                    freq[0]-=3;
                }else{
                    if(!freq[0]) return false;
                    freq[0]--; freq[1]--;
                }
            }
        }
        return true;
    }
};