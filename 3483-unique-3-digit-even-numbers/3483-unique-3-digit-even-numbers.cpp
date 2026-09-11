class Solution {
public:
    int totalNumbers(vector<int>& digits) { 
        int count = 0;
        int x = 100;
        while(x <= 999){
            bool flag = true;
            unordered_map<int , int> m;
             for(int i = 0; i < digits.size(); i++){
                m[digits[i]]++;
         }
           int n = x;
           while(n != 0){
            int a = n%10;
           if(m.count(a)){
             m[a]--;
             if(m[a] == 0){
                m.erase(a);
             }
           }else{
            flag = false;
            break;
           }
            n = n/10;
           }
           if(flag){
            count++;
           }
           x+=2;
        }
     
     return count;
    }
};