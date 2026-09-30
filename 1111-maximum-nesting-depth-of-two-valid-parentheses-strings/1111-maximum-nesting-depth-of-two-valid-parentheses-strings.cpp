class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int count = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                count++;
                if (count % 2 == 0) {
                    ans[i] = 0;
                } else {
                    ans[i] = 1;
                }
            } else {
                if (count % 2 == 0) {
                    ans[i] = 0;
                } else {
                    ans[i] = 1;
                }
                count--;
            }
        }
        return ans;
    }
};
