class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
  
    int area1 = abs(ay2-ay1) * abs(ax2-ax1);
    int area2 = abs(by2-by1) * abs(bx2-bx1);
  
   if (ax2 <= bx1 || ay2 <= by1 || by2 <= ay1 || bx2 <= ax1) {     
     return area1 + area2;
    
}
     int w = min(ax2 , bx2) - max(ax1 , bx1);
     int h = min(ay2 , by2) - max(ay1 , by1);
      
     return area1 + area2 - w*h;

    }
};