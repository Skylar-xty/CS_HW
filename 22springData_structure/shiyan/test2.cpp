//
// Created by Skylar_xty on 2022-10-08.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt=1;int depth=0;
int a[100];
int i=0,j=0;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int solve(vector<char> pre,vector<char> in,int&cnt,int& nodes){
    cout<<"enter"<<endl;
    while(pre[i]!=in[j])
    {
        i++;
        cnt++;
        if(i==(nodes-1)||j==(nodes-1))
        {
            cout<<"ok";
            return cnt;
        }
    }
    if(pre[i]==in[j]){
        depth=max(cnt,depth);
        cout<<depth;
        j++;
        while(pre[i]!=in[j]){
            i--;
            //cnt--;
        }
        j++;
        cnt=i;
    }
    solve(pre,in,cnt,nodes);
}
int main()
{
    int nodes;
    cin>>nodes;
    cout<<nodes;
    vector<char> preorder(nodes);
    vector<char> inorder(nodes);
    //auto pre_iter =preorder.begin();
    //auto in_iter = inorder.begin();

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
    //cout<<solve(preorder,inorder,cnt,nodes);
    int ans=solve(preorder,inorder,cnt,nodes);
    cout<<ans;
    return 0;

}
