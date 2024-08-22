class Solution {
public:
    int findComplement(int num) {
        int pw = 1;
        while(pw <= num){
            pw <<= 1;
        }
        //cout << pw << endl;
        return pw-1-num;
    }
};