# python内置堆排序，默认小顶堆
from heapq import heappop, heappush

def heap_sort(array):
    heap = []
    for element in array:
        heappush(heap, element)

    ordered = []
    while heap:
      ordered.append(heappop(heap))

    return ordered

nums = [4,5,3,2,1,7]

hep = heap_sort(nums)
print(hep)