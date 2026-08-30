class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int target = 0;

        while (s[i] != ' ' && i < n) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                target++;
            }
            i++;
        }
        i++;
        int j = i;
        int count = 0;
        while (j < n) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                s[j] == 'u') {
                count++;
            } else if (s[j] == ' ' && count == target) {

                int st = i;
                int end = j - 1;
                while (st <= end) {
                    swap(s[st], s[end]);
                    st++;
                    end--;
                }
                count = 0;
                i = j + 1;
            } else if (s[j] == ' ' && count != target) {
                count = 0;
                i = j + 1;
            }

            j++;
        }
        if (count == target) {
            int st = i;
            int end = j - 1;
            while (st <= end) {
                swap(s[st], s[end]);
                st++;
                end--;
            }
        }
        return s;
    }
};