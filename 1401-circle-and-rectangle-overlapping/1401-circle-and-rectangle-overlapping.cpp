class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
       int x;
       int y;
       if(x1 > xc){
         x = x1;
       }else if(x2 < xc){
          x = x2;
       }else{
         x = xc;
       }


         if(y1 > yc){
         y = y1;
       }else if(y2 < yc){
          y = y2;
       }else{
         y = yc;
       }


     int d = sqrt((x-xc) * (x-xc) + (y-yc)*(y-yc));
     if(d <= radius){
        return true;
     }
       return false;
    }
};
         
        

