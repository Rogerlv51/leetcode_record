# 快速排序
# 采用经典的分治策略，选择数组中某个元素作为基准数，通过一趟排序将数组分为独立的两个子数组，一个子数组中所有元素值都比基准数小，另一个子数组中所有元素值都比基准数大。
# 然后再按照同样的方式递归的对两个子数组分别进行快速排序，以达到整个数组有序。
# 平均时间复杂度：O(n×logn)

import random

class Solution:
    
    # 哨兵划分：以第 1 位元素 nums[low] 为基准数，然后将比基准数小的元素移动到基准数左侧，将比基准数大的元素移动到基准数右侧，最后将基准数放到正确位置上
    def partition(self, nums, low: int, high: int) -> int:        
        # 以第 1 位元素为基准数
        pivot = nums[low]
        i, j = low, high
        while i < j:
            # 从右向左找到第 1 个小于基准数的元素
            while i < j and nums[j] >= pivot:
                j -= 1
            # 从左向右找到第 1 个大于基准数的元素
            while i < j and nums[i] <= pivot:
                i += 1
            # 交换元素
            nums[i], nums[j] = nums[j], nums[i]
        
        # 将基准数放到正确位置上
        nums[j], nums[low] = nums[low], nums[j]
        return j

    def quickSort(self, nums, low: int, high: int):
        if low < high:
            # 按照基准数的位置，将数组划分为左右两个子数组
            pivot_i = self.partition(nums, low, high)
            # 对左右两个子数组分别进行递归快速排序
            self.quickSort(nums, low, pivot_i - 1)
            self.quickSort(nums, pivot_i + 1, high)

        return nums

    def sortArray(self, nums):
        return self.quickSort(nums, 0, len(nums) - 1)
    
print(Solution().sortArray([4, 7, 5, 2, 6, 1, 3]))
