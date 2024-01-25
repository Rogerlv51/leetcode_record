def bubble_sort(nums:list) -> None: 
  n = len(nums)
  for i in range(n):
    flag = False
    for j in range(n-i-1):
      if nums[j] > nums[j+1]:
        nums[j+1], nums[j] = nums[j], nums[j+1]
      else:
        flag = True
    if not flag:
      break
  
def selected_sort(nums:list) -> None:
  n = len(nums)
  for i in range(n):
    min_index = i    # 记录最小值位置
    # 找最小值
    for j in range(i+1,n):
      if nums[j] < nums[min_index]:
        min_index = j
    
    if i != min_index:   # 如果最小值位置和当前插入位置一致就不变
      nums[i], nums[min_index] = nums[min_index], nums[i]

def insert_sort(nums:list) -> None:
  n = len(nums)
  for i in range(1,n):
    temp = nums[i]
    j = i
    while temp<nums[j-1] and j > 0:
      nums[j] = nums[j-1]   # 元素往后移，给temp的插入腾位置
      j-=1

    nums[j] = temp  # 最后把temp插入到指定位置即可

# 归并排序：采用经典的分治策略，先递归地将当前数组平均分成两半，然后将有序数组两两合并，最终合并成一个有序数组。
class Solution:
    # 合并过程
    def merge(self, left_nums, right_nums):
        nums = []
        left_i, right_i = 0, 0
        while left_i < len(left_nums) and right_i < len(right_nums):
            # 将两个有序子数组中较小元素依次插入到结果数组中
            if left_nums[left_i] < right_nums[right_i]:
                nums.append(left_nums[left_i])
                left_i += 1
            else:
                nums.append(right_nums[right_i])
                right_i += 1
        
        # 如果左子数组有剩余元素，则将其插入到结果数组中
        while left_i < len(left_nums):
            nums.append(left_nums[left_i])
            left_i += 1
        
        # 如果右子数组有剩余元素，则将其插入到结果数组中
        while right_i < len(right_nums):
            nums.append(right_nums[right_i])
            right_i += 1
        
        # 返回合并后的结果数组
        return nums

    # 分解过程
    def mergeSort(self, nums):
        # 数组元素个数小于等于 1 时，直接返回原数组
        if len(nums) <= 1:
            return nums
        
        mid = len(nums) // 2                        # 将数组从中间位置分为左右两个数组
        left_nums = self.mergeSort(nums[0: mid])    # 递归将左子数组进行分解和排序
        right_nums =  self.mergeSort(nums[mid:])    # 递归将右子数组进行分解和排序
        return self.merge(left_nums, right_nums)    # 把当前数组组中有序子数组逐层向上，进行两两合并

    def sortArray(self, nums):
        return self.mergeSort(nums)


# 希尔排序：本质上其实是根据间隔划分区间，然后在区间内做插入排序
def shellSort(nums):
    size = len(nums)
    gap = size // 2
    # 按照 gap 分组
    while gap > 0:
        # 对每组元素进行插入排序
        for i in range(gap, size):
            # temp 为每组中无序数组第 1 个元素
            temp = nums[i]
            j = i
            # 从右至左遍历每组中的有序数组元素
            while j >= gap and nums[j - gap] > temp:
                # 将每组有序数组中插入位置右侧的元素依次在组中右移一位
                nums[j] = nums[j - gap]
                j -= gap
            # 将该元素插入到适当位置
            nums[j] = temp
        # 每次更新，不断缩小 gap 间隔
        gap = gap // 2
    return nums

nums = [4,3,2,1,6,8,7]
shellSort(nums)
print(nums)