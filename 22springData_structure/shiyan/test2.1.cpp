//
// Created by Skylar_xty on 2022-10-08.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//class TreeNode{
//public:
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
vector<char> find_left(char x,vector<char> in){
    vector<char> res;
    auto in_iter = in.begin();
    while((*in_iter)!=x)
    {
        res.push_back(*in_iter);
        in_iter++;
    }
    cout<<"left";
    return res;
}
vector<char> find_right(char x,vector<char> in){
    vector<char> res;
    auto in_iter = in.begin();
    while(in_iter!=in.end())
    {
        if((*in_iter)!=x)
        {
            in_iter++;
        }
        else
        {
            res.push_back(*(in_iter+1));
            in_iter++;
        }
    }
    cout<<"right";
    return res;
}

int depth=0;
int solve(vector<char> preorder,vector<char> inorder,int cnt){
    if(preorder.empty())return depth;
    depth=max(cnt,depth);
    cout<<depth<<endl;
    char root=*preorder.begin();
    cout<<root<<endl;
    vector<char> temp_left= find_left(root,inorder);
    if(!temp_left.empty()) {
        cout << "1";
        preorder.erase(preorder.begin());
        solve(preorder, temp_left, cnt + 1);
    }
    else if(temp_left.empty())
    {
        cout<<"2";
        vector<char> temp_right= find_right(root,inorder);

    }
}
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

    int ans=solve(preorder,inorder,cnt);
    //cout<<solve(preorder,inorder,cnt,nodes);
    cout<<ans;
    return 0;

}

