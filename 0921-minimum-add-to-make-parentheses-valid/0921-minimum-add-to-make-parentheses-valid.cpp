class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int count = 0;
        stack<char> c;
        c.push(s[0]);
        for(int i = 1; i < n; i++){
            if(c.empty()){
                c.push(s[i]);
                continue;
            }
           if(s[i] == ')' && c.top() == '(') {
            c.pop();
           }else{
            c.push(s[i]);
           }
        }
        while(!c.empty()){
            count++;
            c.pop();
        }
       return count;
    }
};