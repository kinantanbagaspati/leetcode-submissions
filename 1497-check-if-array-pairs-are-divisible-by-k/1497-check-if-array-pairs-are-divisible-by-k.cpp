class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //if(arr.size() % 2 > 0) return false;
        int freq[k];
        for(int i=0; i<k; i++) freq[i] = 0;
        for(int i=0; i<arr.size(); i++) freq[(arr[i]%k+k)%k]++;;
        if(freq[0]%2) return false;
        for(int i=1; i*2<k; i++){
            if(freq[i] != freq[k-i]) return false;
        }
        if(k%2==0 && freq[k/2]%2) return false;
        return true;
    }
};