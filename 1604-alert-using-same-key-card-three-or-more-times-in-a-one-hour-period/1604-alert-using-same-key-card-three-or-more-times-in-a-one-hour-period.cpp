class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        vector<string> ans;
        for(int i = 0; i < keyTime.size(); i++){
            string x = "";
            for(int j = 0; j < keyTime[i].size(); j++){
                if(keyTime[i][j] != ':'){
                    x += keyTime[i][j];
                }

            }
            keyTime[i] = x;
        }
        unordered_map<string , vector<string>> m;
        for(int i = 0; i < n; i++){
            m[keyName[i]].push_back(keyTime[i]);
        }
        for(auto& it : m){
            sort(it.second.begin(), it.second.end());
            for(int i = 0; i + 2 < it.second.size(); i++){
                int a = stoi(it.second[i]);
                int b = stoi(it.second[i+2]);  
                if(b - a <= 100){
                    ans.push_back(it.first);
                    break;                      
                }
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};