class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i=prices.size()-1 ; i>0 ; --i) {            
            if (prices[i] - prices[i-1] > 0)
                sum += prices[i] - prices[i-1];
        }
        return sum;
    }
};