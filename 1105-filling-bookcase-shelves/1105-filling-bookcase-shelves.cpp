class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int ans[books.size()+1];
        ans[0] = 0;
        for(int i=0; i<books.size(); i++){
            ans[i+1] = 2e9;
            int sumw = books[i][0], maxh = books[i][1];
            for(int j=i-1; j>=0 && sumw <= shelfWidth; j--){
                ans[i+1] = min(ans[j+1] + maxh, ans[i+1]);
                sumw += books[j][0]; maxh = max(books[j][1], maxh);
            }
            if(sumw <= shelfWidth) ans[i+1] = min(ans[0] + maxh, ans[i+1]);
        }
        return ans[books.size()];
    }
};