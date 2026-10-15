class Solution {
public:
    int findMinDifference(vector<string>& time) {
        int n = time.size();
        for (int i = 0; i < n; i++) {
          int x = (time[i][0] * 10 + time[i][1]) * 60 + time[i][3] * 10 + time[i][4];
            time[i] = to_string(x);
        }
         int mnn = INT_MAX;
         sort(time.begin() , time.end());
         for(int i = 0; i < n-1; i++){
            int a = stoi(time[i]);
            int b = stoi(time[i+1]);
          mnn = min(b-a , mnn);
         }
        int min1 = min(mnn , 24*60-mnn);
        int a = stoi(time[n-1]);
        int b = stoi(time[0]);
        return min(min1 ,24*60 -(a-b));
    }
};