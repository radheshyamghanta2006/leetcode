class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0]; // Start with the first price as the minimum
        int maxProfit = 0;         // Initialize maximum profit to 0
         // Loop through the prices starting from the second day
        for(int j = 1; j < prices.size(); j++) {
            // If the current price yields a better profit, update maxProfit
            if(prices[j] - minPrice > maxProfit) {
                maxProfit = prices[j] - minPrice;
            }  
          // If the current price is lower than the minPrice, update minPrice
            if(prices[j] < minPrice) {
                minPrice = prices[j];
            }
        }
         return maxProfit; // Return the maximum profit found
    }
};