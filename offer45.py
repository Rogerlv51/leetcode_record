# 剑指 Offer 45. 把数组排成最小的数
# 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
# 输出位数可能比较多，所以要求输出为字符串类型

# 这题的本质是一个排序问题，遵循规则如下：
# 若拼接字符串 x+y>y+x，则 x “大于” y ；
# 反之，若 x+y<y+x，则 x “小于” y ；
# x “小于” y 代表：排序完成后，数组中 x 应在 y 左边；“大于” 则反之


# python中functools的比较函数有如下定义：
# A comparison function is any callable that accept two arguments, compares them, 
# and returns a negative number for less-than, zero for equality, or a positive number for greater-than

import functools
class Solution:
    def minNumber(self, nums: list[int]) -> str:
      # 自定义比较规则
      def cmp(a,b):
        if a+b>b+a:
          return 1
        elif a+b==b+a:
          return 0
        else:
          return -1
      
      nums_str = list(map(str, nums))
      nums_str.sort(key=functools.cmp_to_key(cmp))  # 调用functools.cmp_to_key函数传入自定义规则
      return ''.join(nums_str)

nums = [4,3,5,4,6]
s = Solution()
res = s.minNumber(nums)
print(nums)
print(res)