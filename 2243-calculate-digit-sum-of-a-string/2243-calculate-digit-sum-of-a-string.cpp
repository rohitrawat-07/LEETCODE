class Solution {
public:
    string digitSum(string s, int k) {
        while (true) {
            if (s.size() <= k) {
                return s;
            }
            string temp = "";
            int sum = 0;
            int count = 0;
            for (int i = 0; i < s.size(); i++) {
                sum += s[i] - '0';
                count++;
                if (count == k || i == s.size() - 1) {
                    temp += to_string(sum);
                    count = 0;
                    sum = 0;
                }
            }
            s = temp;
        }
        return "";
    }
};