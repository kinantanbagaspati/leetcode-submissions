class Solution {
public:
    int q[131072], qhead, qtail, cur;
    int minKBitFlips(vector<int>& nums, int k) {
        qhead=0; qtail=0; cur=0;
        bool bisa = true;
        for(int i=0; i<nums.size(); i++){
            // hapus q
            if(qtail > qhead && q[qhead] == i){
                cur--; qhead++;
            }
            // upd nums
            nums[i] = (nums[i]+cur)%2;
            // flip
            if(nums[i] == 0){
                if(i+k>nums.size()){
                    bisa = false;
                }else{
                    q[qtail]=i+k; qtail++;
                    cur++;
                }
            }
        }
        if(bisa){
            return qtail;
        }else{
            return -1;
        }
    }
};