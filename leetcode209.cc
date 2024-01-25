// 209. 长度最小的子数组 双指针维护滑动窗口
/*
  给定一个含有n个正整数的数组和一个正整数target
  找出该数组中满足其总和大于等于target的长度最小的连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
  并返回其长度。如果不存在符合条件的子数组，返回 0 。

  输入：target = 7, nums = [2,3,1,2,4,3]
  输出：2
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int s, vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
    {
      return 0;
    }
    int ans = INT_MAX;
    int start = 0, end = 0;
    int sum = 0;
    while (end < n)
    {
      sum += nums[end];
      while (sum >= s)
      {
        ans = min(ans, end - start + 1);
        sum -= nums[start];
        start++;
      }
      end++;
    }
    return ans == INT_MAX ? 0 : ans;
  }
};

int main()
{

  return 0;
}