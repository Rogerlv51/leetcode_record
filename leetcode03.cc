#include <bits/stdc++.h>

// 给定一个字符串s，请你找出其中不含有重复字符的最长子串的长度。
/*
	输入: s = "abcabcbb"
	输出: 3 
	解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

*/
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
						// 当右指针移到字符串末尾，且set中不包含右指针+1位置的字符时才能右移
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

int main(){
	Solution s;
	string ss = "abcabcbb";
	cout << s.lengthOfLongestSubstring(ss) << endl;

  return 0;
}