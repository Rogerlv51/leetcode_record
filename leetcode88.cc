/*
    给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n，分别表示nums1和nums2中的元素数目。
    请你合并nums2到nums1中，使合并后的数组同样按非递减顺序排列。

    注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1的初始长度为m+n，
    其中前m个元素表示应合并的元素，后n个元素为0，应忽略。nums2的长度为n。

    输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    输出：[1,2,2,3,5,6]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- - 1;
        while(m >= 0 && n >= 0){
            nums1[pos--] = nums1[m] > nums2[n]? nums1[m--] : nums2[n--]; 
        }
        while(n >= 0){
            nums1[pos--] = nums2[n--];
        }
    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Solution s;
    s.merge(nums1,3,nums2,3);
    for(auto i:nums1) cout<<i<<" ";
    return 0;
}