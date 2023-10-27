//
// Created by Skylar_xty on 2023/4/20.
// 实验二：完全背包问题
//
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

//struct S{
//    int w;
//    int v;
//};
//vector<S> a;
//vector<S>::iterator p;

//限重1000，100种物品
const int N = 1005;
const int M = 105;
int n,m;//限重，和物品个数
//int dp[M][N],w[M],v[M];

int dp[N],w[M],v[M];
int choose[M];
int main()
{
    srand(time(0));
    n = 1000,m=100;
    for(int i=1;i<=m;i++)
    {
        w[i]=rand()%50+1;
        v[i]=rand()%90+11;
    }
//
//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            if(j>=w[i])
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
//            else
//                dp[i][j]=dp[i-1][j];
//        }
//    }
//    cout<<"finish"<<endl;
//    cout<<dp[m][n]<<endl;
    int cnt=0;
    for(int i=1;i<=m;i++) {
        for (int j = n; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]); //继续上一种方案还是拿当前物品加上除去当前物品剩余背包容量所具有的最大价值后的总价值

        }
    }
    cout<<dp[n]<<endl;
    cout<<cnt<<endl;

    return 0;
}
