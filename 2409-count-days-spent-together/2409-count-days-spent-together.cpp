class Solution {
public:
    int countDaysTogether(string Aalice, string Lalice, string Abob,
                          string Lbob) {
        vector<int> vec{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < vec.size(); i++) {
            vec[i] = vec[i] + vec[i - 1];
        }
        string temp = Aalice.substr(0, 2);
        int aa = stoi(temp);
        temp = Lalice.substr(0, 2);
        int la = stoi(temp);

        temp = Abob.substr(0, 2);
        int ab = stoi(temp);
        temp = Lbob.substr(0, 2);
        int lb = stoi(temp);
        int alice = 0, alice2 = 0, bob = 0, bob2 = 0;

        if (aa == 1)
            alice = stoi(Aalice.substr(3, 2));
        else
            alice = vec[aa - 2] + stoi(Aalice.substr(3, 2));

        if (la == 1)
            alice2 = stoi(Lalice.substr(3, 2));
        else
            alice2 = vec[la - 2] + stoi(Lalice.substr(3, 2));

        if (ab == 1)
            bob = stoi(Abob.substr(3, 2));
        else
            bob = vec[ab - 2] + stoi(Abob.substr(3, 2));

        if (lb == 1)
            bob2 = stoi(Lbob.substr(3, 2));
        else
            bob2 = vec[lb - 2] + stoi(Lbob.substr(3, 2));

        int start = max(alice, bob);
        int end = min(alice2, bob2);
        if (start > end) {
            return 0;
        }
        return end - start + 1;
    }
};