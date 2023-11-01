//
// Created by Skylar_xty on 2022-10-08.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class TreeNode{
public:
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); i++)
            dic[inorder[i]] = i;
        return recur(0, 0, inorder.size() - 1);
    }
    void preorder_1(TreeNode* root,vector<char> &res){
        if(root==nullptr){
            return;
        }
        res.push_back(root->val);
        preorder_1(root->left,res);
        preorder_1(root->right,res);
    }
    vector<char> preorderTraversal(TreeNode* root) {
        vector<char> res;
        preorder_1(root,res);
        return res;
    }
    int solve_depth(TreeNode* root){
        if(!root) return 0;
        int left_depth= solve_depth(root->left);
        int right_depth= solve_depth(root->right);
        return max(left_depth,right_depth)+1;
    }
private:
    vector<char> preorder;
    unordered_map<int, char> dic;
    TreeNode* recur(int root, int left, int right) {
        if(left > right) return nullptr;                        // 递归终止
        TreeNode* node = new TreeNode(preorder[root]);          // 建立根节点
        int i = dic[preorder[root]];                            // 划分根节点、左子树、右子树
        node->left = recur(root + 1, left, i - 1);              // 开启左子树递归
        node->right = recur(root + i - left + 1, i + 1, right); // 开启右子树递归
        return node;                                            // 回溯返回根节点
    }
};
int main()
{
    int nodes;int cnt=0;
    cin>>nodes;
    cout<<nodes;
    vector<char> preorder(nodes);
    vector<char> inorder(nodes);
    for(int i=0;i<nodes;i++)
    {
        cin>>preorder[i];
    }
    cin.get();
    for(int i=0;i<nodes;i++)
    {
        cin>>inorder[i];
    }
    for(int i=0;i<nodes;i++)
    {
        cout<<preorder[i];
    }
    cout<<endl;
    for(int i=0;i<nodes;i++)
    {
        cout<<inorder[i];
    }
    cout<<endl;
    Solution solve1;
    TreeNode* root=solve1.buildTree(preorder,inorder);
    vector<char> ans=solve1.preorderTraversal(root);
    for(int i=0;i<nodes;i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
    cout<<solve1.solve_depth(root);
    return 0;

}


