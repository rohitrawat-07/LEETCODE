class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int idx = 0;
        vector<int> vec;
        if(low > 123456789){
            return {};
        }
        
        vector<int> ans = {
            12,      23,      34,      45,       56,       67,
            78,      89,      123,     234,      345,      456,
            567,     678,     789,     1234,     2345,     3456,
            4567,    5678,    6789,    12345,    23456,    34567,
            45678,   56789,   123456,  234567,   345678,   456789,
            1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
            for(int i = 0; i < ans.size(); i++){
                if(low <= ans[i]){
                    idx = i;
                    break;
                }
            }
            for(int i = idx; i < ans.size(); i++){
                if(ans[i] <= high ){
                    vec.push_back(ans[i]);
                }
            }
       return vec;
    }
};