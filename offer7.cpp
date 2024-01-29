// 面试题7：重建二叉树（经典题）
// 输入一棵二叉树前序遍历和中序遍历的结果，请重建该二叉树

/*
给定：
前序遍历是：[3, 9, 20, 15, 7]
中序遍历是：[9, 3, 15, 20, 7]

返回：[3, 9, 20, null, null, 15, 7, null, null, null, null]
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  map<int, int> index;  // 记录前序遍历根节点在中序遍历中的位置

  vector<int> preorder, inorder;
  TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
    preorder = _preorder;
    inorder = _inorder;
    for(int i = 0; i< inorder.size(); i++) index[inorder[i]] = i;
    // 按长度划分左右子树递归即可
    return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
  }

  TreeNode* dfs(int pre_left, int pre_right, int in_left, int in_right){
    if(pre_left > pre_right) return nullptr;
    auto root = new TreeNode(preorder[pre_left]); // 前序遍历的第一个节点就是根节点
    int k = index[root->val]; // 根节点在中序遍历中的位置
    root->left = dfs(pre_left+1, pre_left+k-in_left, in_left, k-1);
    root->right = dfs(pre_left+k-in_left+1,pre_right, k+1, in_right);
    return root;
  }
};

// 打印前序遍历
void pre_order(TreeNode * Node){
    if(Node == nullptr)
        return;
    cout << Node->val << " ";
    pre_order(Node->left);
    pre_order(Node->right);
}

int main(){
  vector<int> ppreorder = {3, 9, 20, 15, 7};
  vector<int> iinorder = {9, 3, 15, 20, 7};
  Solution s;
  auto ans = s.buildTree(ppreorder, iinorder);
  
  pre_order(ans);
  
  return 0;
}