class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        int rightBorder[sz];
        stack<int> lisIdx;
        lisIdx.push(sz);
        for(int i=sz-1; i>=0; i--){
            while(lisIdx.size()>1 && heights[lisIdx.top()] >= heights[i]) lisIdx.pop();
            rightBorder[i] = lisIdx.top();
            lisIdx.push(i);
        }
        while(lisIdx.size()>0) lisIdx.pop();
        lisIdx.push(-1);
        int ans = 0;
        for(int i=0; i<sz; i++){
            while(lisIdx.size()>1 && heights[lisIdx.top()] >= heights[i]) lisIdx.pop();
            //cout << i << ": " << lisIdx.top() << "-" << rightBorder[i] << endl;
            ans = max(heights[i]*(rightBorder[i]-lisIdx.top()-1), ans);
            lisIdx.push(i);
        }
        return ans;
    }
};