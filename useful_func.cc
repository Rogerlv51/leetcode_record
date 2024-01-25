// 编程做题常用函数总结：
#include<bits/stdc++.h>   // 万能头文件
#include <string.h>
using namespace std;

char a = tolower('A');  // 转小写
char A = toupper('a');  // 转大写

bool t = isalnum('b');   // 判断字符是否是数字或者字母

int x = atoi("dsadasda");  // 字符串转整数，char[]
// int xx = stoi("dsdasdasda");  // 字符串转整数，string

int main(){
    vector<int> p = {1,2,5,4};                                                    
    sort(p.begin(), p.end()); // 数组或vector排序

    int res1 = *max_element(p.begin(), p.end()); //数组或vector的最大值, 不带*就是返回迭代器指针
    int res2 = *min_element(p.begin(), p.end()); //数组或vector的最小值
    

    int q[10];
    memset(q, 0, sizeof(q));  // 初始化为0

    
    string s = "abc edf ghq";
    stringstream ss(s);  // 把字符串传入流中，可以直接遍历字符串中的string
    string tmp;  // 用tmp接收字符串中的string
    while(ss>>tmp) cout << tmp << endl;
    return 0;
}
