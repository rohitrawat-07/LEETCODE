class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        int count = 0;
        while(true){
          n = n-x;
          x--;
          if(n < 0){
             if(count % 2 == 0){
                return false;
             }else{
                return true;
             }
          }
          count++;
        }
        return true;
    }
};