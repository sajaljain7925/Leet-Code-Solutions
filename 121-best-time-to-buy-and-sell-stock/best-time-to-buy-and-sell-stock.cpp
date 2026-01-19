class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;

         for( int n : prices){
            if(n< minPrice){
                minPrice = n;
            }else{
                profit = max(profit, n - minPrice);
            }
         }
         return profit;
    }
};