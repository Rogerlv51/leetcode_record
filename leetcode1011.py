# 在 D 天内送达包裹的能力：将问题转化为二分问题

'''
  船最小的运载能力，最少也要等于或大于最重的那件包裹，即max(weights)。最多的话，可以一次性将所有包裹运完，即 
  sum(weights)。船的运载能力介于[max(weights),sum(weights)]之间。我们现在要做的就是从这个区间内，找到满足可以在 
  D天内运送完所有包裹的最小载重量。可以通过二分查找的方式，找到满足要求的最小载重量。
'''

class Solution:
    def shipWithinDays(self, weights: list, D: int) -> int:
        left = max(weights)
        right = sum(weights)

        while left < right:
            mid = (left + right) >> 1
            days = 1
            cur = 0
            for weight in weights:
                if cur + weight > mid:  # 如果说当前重量加上后一次的重量超过了现在的查找值，那么意味着需要新的一天，然后把cur清0
                    days += 1
                    cur = 0
                cur += weight  # 如果没超重那就可以继续用当前的天运送

            if days <= D:  # 如果天数超过了最大运输天数，那么就缩小范围
                right = mid
            else:
                left = mid + 1
        return left


weights, days = [1,2,3,4,5,6,7,8,9,10], 5
print(Solution().shipWithinDays(weights, days))