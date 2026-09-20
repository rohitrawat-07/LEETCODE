class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
           int a = 26-(s[i]-'a');
           sum += a*(i+1);
        }
        return sum;
    }
};