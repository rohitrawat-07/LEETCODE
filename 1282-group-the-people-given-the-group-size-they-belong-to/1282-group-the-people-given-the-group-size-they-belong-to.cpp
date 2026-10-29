class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++) {
            m[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto& it : m) {

            vector<int> temp;
            for (int i = 0; i < it.second.size(); i++) {
                if (temp.size() == it.first) {
                    ans.push_back(temp);
                    temp.clear();
                }
                temp.push_back(it.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};