class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, diff = 0, pivot = prices[prices.size()-1];
        for (int i=prices.size()-1 ; i>0 ; --i) {            
            diff = pivot - prices[i-1];
            if (diff > 0) sum += diff;
            pivot = prices[i-1];
        }
        return sum;
    }
};