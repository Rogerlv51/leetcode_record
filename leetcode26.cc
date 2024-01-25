/*
    
    26. 删除有序数组中的重复项
    给你一个升序排列的数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度。
    元素的相对顺序应该保持一致。然后返回nums中唯一元素的个数。

*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int l = 0;
        for(int r = 1; r < len; r++){
            if(nums[l] != nums[r]){
                nums[l+1] = nums[r];
                l++;
            }
        }
        return l+1;
    }
};

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int res = s.removeDuplicates(nums);
    cout << res << endl;
    return 0;
}