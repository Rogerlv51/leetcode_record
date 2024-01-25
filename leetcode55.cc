/*
    跳跃游戏：贪心
    给你一个非负整数数组nums，你最初位于数组的第一个下标。数组中的每个元素代表你在该位置可以跳跃的最大长度。
    判断你是否能够到达最后一个下标，如果可以，返回true ；否则返回false 。
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i = 0, maxPos = 0; i < nums.size(); ++i)
        {
            if(i > maxPos) return false;
            maxPos = max(maxPos, i + nums[i]);
        }
        return true;
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4};
    vector<int> nums2 = {3,2,1,0,4};
    Solution s;
    cout << s.canJump(nums) << endl;
    return 0;
}