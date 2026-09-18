class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
         sort(prices.begin() , prices.end() , greater<int>());
         sort(discounts.begin() , discounts.end() , greater<int>());
         int j = 0;
         double sum = 0;
         while(j < min(prices.size() , discounts.size())){
          sum += prices[j] * (100.0-discounts[j])/100.0;
          j++;
         }
         for(int i = j; i < prices.size(); i++){
            sum += prices[i];
         }
         return sum;
    }
};