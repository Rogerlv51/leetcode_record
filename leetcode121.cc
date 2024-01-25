/*
    121. 买卖股票的最佳时机:
    给定一个数组 prices ，它的第i个元素 prices[i] 表示一支给定股票第 i 天的价格。
    你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设计一个算法来计算你所能获取的最大利润。
    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回0 。

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int min_profit = 1e9, max_profit = 0;
        for(int i = 0; i < len; i++){
            max_profit = max(max_profit, prices[i] - min_profit);
            min_profit = min(min_profit, prices[i]);
        }
        return max_profit;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}