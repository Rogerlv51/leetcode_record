// 剑指offer面试题4-二维数组中的查找

// 可以根据每次查找右上角元素为中间值，利用二分查找的思想即可（因为每行单调递增，每列也是单调递增）

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> num = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

class Solution{
public:
	bool SearchArray(vector<vector<int>> &num, int target) {
		int row = num.size();
		int col = num[0].size();
		int i = 0, j = col - 1;
		while(i<row && j>=0){
			if(num[i][j] == target) return true;
			if(num[i][j] < target) i++;
			else j--;
		}
		return false;
	}
};

int main() {
  Solution s;
	cout << s.SearchArray(num, 7) << endl;
  return 0;
}