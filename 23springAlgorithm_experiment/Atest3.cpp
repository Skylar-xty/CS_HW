//
// Created by Skylar_xty on 2023/4/27.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXN 20
//问题表示
///n个顶点，k条边，m种颜色
const int n = 7;
const int k = 11;
const int m = 3;
///G的邻接矩阵
int a[MAXN][MAXN];
//求解结果表示
///累计解个数
int count = 0;
///x[i]表示顶点i的着色
int x[MAXN];
/*
 * 判断顶点i是否与相邻顶点存在相同的着色
 */
bool is_Same(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(a[i][j]==1&&x[i]==x[j]) //数组a为G的邻接矩阵
            return false;
    }
    return true;
}
/*
 * 输出当前着色方案
 */
void Output()
{
    cout<<"第"<<count<<"种着色方案：";
    for(int j=1;j<=n;j++) cout<<x[j];
    cout<<endl;
}
/*
 * 采用递归框架，求解图的m着色问题
 */
void GraphColor(int i)
{
    if(i>n)             //到达叶子节点
    {
        count++;        //着色方案数+1
        Output();       //输出一种着色方案
    }
    else
    {
        for(int j=1;j<=m;j++)       //试探每一种着色
        {
            x[i]=j;                 //试探着色j，用第j个颜色涂第i个节点
            if(is_Same(i))          //可以着色，进入下一个顶点着色
                GraphColor(i+1);
            x[i]=0;                 //递归回溯时，将已着色的涂色清空，以免影响is_Same(i)的判断结果
        }
    }
}
/*
 * 算法设计（迭代回溯）
 */
void GraphColor_(int m)
{
    for(int j=1;j<=n;j++) x[j]=0;    //将x[n]初始化为0
    int i=1;                         //数组下标从0开始
    while(i>=1)
    {
        x[i]=x[i]+1;                 //取下一种颜色
        while(x[i]<=m)               //为顶点i搜索可行的着色
        {
            if(is_Same(i))           //如果可行，为顶点i着色x[i]
                break;
            else
                x[i]=x[i]+1;         //不可行，搜索下一个颜色
        }
        if(x[i]<=m&&i==n)            //搜索到叶节点，输出解
        {
            count++;
            Output();
        }
        else if(x[i]<=m&&i<n)             //继续为下一个顶点着色
            i++;
        else                         //回溯
        {
            x[i]=0;                  //还原顶点i的着色情况
            i--;
        }
    }
}
int main()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    int p,q;
//    cin>>n>>k>>m;
    for(int j=1;j<=k;j++)  //建立邻接矩阵
    {
        cin>>q>>p;         //输入一条边的两个顶点
        a[p][q]=1;
        a[q][p]=1;
    }
    //GraphColor(1);         //从顶点1开始搜索
    GraphColor_(m);
    if(count>0)
        cout<<count;
    else
        cout<<"no find!";
    return 0;
}