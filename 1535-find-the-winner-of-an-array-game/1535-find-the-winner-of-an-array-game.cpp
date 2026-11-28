class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> q;
        int n = arr.size();
        int mxx = INT_MIN;
        for(int i = 0; i < n; i++){
            mxx = max(arr[i] , mxx);
        }
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            q.push_back(arr[i]);
            m[arr[i]] = 0;
        }
        while (q.size() != 0) {
            int x = q.front();
            q.pop_front();
            int y = q.front();
            q.pop_front();
            if (x < y) {
                q.push_back(x);
                q.push_front(y);
                m[y]++;
            } else {
                q.push_back(y);
                q.push_front(x);
                m[x]++;
            }
            if (m[x] >= k || x == mxx) {
                return x;
            }
            if (m[y] >= k || y == mxx) {
                return y;
            }
            
        }
        return 0;
    }
};