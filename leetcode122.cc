/*
    买股票的最佳时机||，动态规划 & 贪心

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};