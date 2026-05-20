class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0]; //starting buying price
        int maxP = 0;
        for (int sell : prices){ //go through each price as a sell value
            int tmp = sell - minBuy; //calc temp profit based on lowest buying price and current sell value
            if (maxP < tmp) 
                maxP = tmp; //set max profit
            if (minBuy > sell){
                minBuy = sell; //set lowest buy price if found
            }
        }
        return maxP;
    }
};
