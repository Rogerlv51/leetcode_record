// 11. 盛最多水的容器 经典双指针问题，必会！
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int i = 0;
		int j = height.size() - 1;
		int res = 0;
		while (i < j)
		{
			res = max(res, (j-i) * min(height[i], height[j]));
			if(height[i]<=height[j]){
				i++;
			}
			else j--;
		}
		return res;
	}
};

int main(){
	vector<int> height = {1,1};
	Solution s;
	int res = s.maxArea(height);
	cout << res << endl;
	return 0;
}