class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1024];
        for(int i=0; i<1024; i++) freq[i] = 0;
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++; freq[target[i]]--;
        }
        bool ans = true;
        for(int i=0; i<1024; i++) ans = ans && (freq[i] == 0);
        return ans;
    }
};