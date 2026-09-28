class Solution {
public:
    int maxDepth(string s) {
        int mxx = 0;
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i]== '('){
                count++;
            }else if(s[i] == ')'){
                count--;
            }
            mxx = max(count , mxx);
        }

         return mxx; 
    }
};