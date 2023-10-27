//
// Created by Skylar_xty on 2023/4/20.
//
#include<iostream>
#include<algorithm>
#include <ctime>
using namespace std;

const int max_weight = 1000;
const int n = 100;

int main() {
    srand(time(0));
    int i, j;
    int w[n] ; //重量
    int v[n] ; //价值
    int dp[n][max_weight+1];//辅助数组
    for(int k=0;k<n;k++)
    {
        w[k]=rand()%50+1;
        v[k]=rand()%90+11;
    }

    //初始化第0列（即背包容量为0）
    for (i = 0; i < n; i++)
        dp[i][0] = 0;
    //初始化第0行（即只有物品0）
    for (j = 1; j <= max_weight; j++) {
        if (w[0] <= j)
            dp[0][j] = v[0];
        else
            dp[0][j] = 0;
    }

    //状态转移
    //先遍历物品再遍历背包
    for (i = 1; i < n; i++) {                  //遍历物品
        for (j = 1; j <= max_weight; j++) {    //遍历背包
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    //输出
    cout << dp[n - 1][max_weight] << endl;

    //回溯法求解装入物品
    i--; j--;     //循环结束后,i=n,j=max_weight+1,故使用dp[n - 1][max_weight]须自减1
    cout << "MAx value" << endl;
    while (dp[i][j]&&i>=0) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << "item:" << i << ",";
            j -= w[i];  //装入物品i后背包的最大容量
        }
        i--;    //物品i已经处理完成，接下来讨论物品i-1
    }

    return 0;
}
