l1 = [1,2, [3,4]]
# l2 = l1[:]
l2 = l1.copy()  # 浅拷贝，带来的问题是比如这里l1中嵌套list，那么当list有变化时，l2也会跟着变
l1[2].append(5)

print(l2)

# 所以有时候需要深拷贝
import copy

b = copy.deepcopy(l1)
l1[2].append(10)
print(b)   # 发现还是[1, 2, [3, 4, 5]]

# 当我们需要枚举一个数组并同时获得值与index的时候可以使用：enumerate
l = ["a", "b", "c"]

for i, v in enumerate(l):
    print(i, v)

# 使用zip组合数据（打包）
x = [1, 2, 3]
y = [4, 5, 6]
zipped = zip(x, y)
print(list(zipped))

# map函数可以对可迭代的参数对象进行一一隐射计算，第一个参数给定一个函数，比如我们经常在输入类型转换时使用
m = map(int, input().split(' '))
print(list(m))


# deque双端队列
from collections import deque, defaultdict  # 系统自带默认队列函数

dic = dict()
dic.setdefault('a', 0)   # 初始化字典的默认值
dd = defaultdict()   # 系统自带默认字典，初始化为空
print(dic)
print(dd)


# ord 返回单个字符的 unicode， chr根据ASCII码返回字符

#  int/ float 最大, 最小 number
inf = float('inf')
print(inf)


# 按下标遍历数组
def find(nums, val):
    for i in range(len(nums)):
        if nums[i] == val:
            return i
    return -1

# python中直接使用append，pop，insert,remove添加或删除list元素，可以直接指定位置都是O(1)


for x in range(10, 0, -1):   # 反向读取index
  print(x)