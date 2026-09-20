class Solution {
public:
    bool isSet(int& x , int bit){
        return x & (1 << bit);
    }
    bool setBit(int& x , int bit){
        return x |= ( 1 << bit);
    }
    bool unSetBit(int&x , int bit){
        return x &= ~(1 << bit);
    }
    int minimizeXor(int num1, int num2) {
      int setBits1 = 0;
      int setBits2 = 0;
      int org2 = num2;
      int org1 = num1;
      while(org1 != 0){
        int x = org1 & 1;
        if(x > 0) setBits1++;
        org1 = org1 >> 1;
        }
       while(org2 != 0){
        int x = org2 & 1;
        if(x > 0) setBits2++;
        org2 = org2 >> 1;
        }
        if(setBits1 == setBits2){
            return num1;
        }
        int x = num1;
        int bit = 0;
        if(setBits1 < setBits2){
          while(setBits1 < setBits2){
            if(!isSet(x , bit)){
                setBit(x , bit);
                setBits1++;
            }
            bit++;
          }
        }else if(setBits1 > setBits2){
          while(setBits1 > setBits2){
            if(isSet(x , bit)){
                unSetBit(x , bit);
                setBits1--;
            }
            bit++;
          }
        }
        return x;
    }
};