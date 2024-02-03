// 快速排序实现：每次先在数组（左右子数组）中随机选择一个数字，然后把数组分为左右两个区间，比选择数字小的放在左边，比选择数字大的放在右边
// 然后递归对左右两个区间进行排序即可

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>


using namespace std;

int GetRandNum(int m, int n) {
  srand(time(NULL));
  return rand() % (n - m + 1) + m;
}

int Partition(vector<int>& data, int len, int start, int end) {
  int index = GetRandNum(start, end);
  swap(data[index], data[end]);

  int small = start - 1;
  for (index = start; index < end; ++index) {
    if (data[index] < data[end]) {
      ++small;
      if (small != index) {
        swap(data[index], data[small]);
      }
    }
  }
  small++;
  swap(data[small], data[end]);
  return small;
}

void QuickSort(vector<int>& data, int len, int start, int end) {
  if (start == end) return;
  int index = Partition(data, len, start, end);
  if (index > start) {
    QuickSort(data, len, start, index - 1);
  }
  if (index < end) {
    QuickSort(data, len, index + 1, end);
  }
}

int main() {
  vector<int> nums = {3, 4, 1, 2, 5, 6, 10, 7, 9, 8};
  QuickSort(nums, nums.size(), 0, nums.size() - 1);

  for (auto num : nums) {
    cout << num << " ";
  }
  return 0;
}