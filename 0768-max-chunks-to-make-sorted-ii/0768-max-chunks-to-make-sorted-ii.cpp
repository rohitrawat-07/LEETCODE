class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> mn;
        int count = 0;
        int mnn = INT_MAX;
        for (int i = n - 1; i >= 1; i--) {
            mnn = min(arr[i], mnn);
            mn.push_back(mnn);
        }
        reverse(mn.begin(), mn.end());
        int mxx = INT_MIN;
        for (int i = 0; i < mn.size(); i++) {
            mxx = max(arr[i], mxx);
             if (mxx <= mn[i]) {
                 count++; 
                 }
        }
        return count+1;
    }
};
