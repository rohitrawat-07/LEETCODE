class Solution {
public:
    int minRange(int a, int b, int c) {
        int mnn = INT_MAX;
        int x = min(a , min(b,c));
        int y = max(a , max(b,c));
        mnn = min(y-x , mnn);
        x = min(b+c , min(b , c));
        y = max(b+c , max(b , c));
        mnn = min(y-x , mnn);
        x = min(a+c , min(a , c));
        y = max(a+c , max(a, c));
        mnn = min(y-x , mnn);
        x = min(a+b , min(a , b));
        y = max(a+b , max(a , b));
        mnn = min(y-x , mnn);
        return mnn;
    }
};