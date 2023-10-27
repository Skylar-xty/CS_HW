//
// Created by Skylar_xty on 2023/4/27.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int n = 10;
int a[n+1];
int l,r;//快速排序的左边界和右边界
/*
 * 快速排序
 */
void quickSort(int arr[],int low,int high)
{
    if(low>=high){  // 递归终止条件
        return;
    }
    int mid = arr[(low+high)/2]; // 选取中间元素
    int i = low,j=high;
    while(i<=j){
        while(arr[i]<mid)i++; // 从左向右找到第一个
        while(arr[j]>mid)j--; // 从右向左找到第一个
        if(i<=j){             // 如果左指针小于等于右指针，交换
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    quickSort(arr,low,j);  //递归左子序列
    quickSort(arr,i,high); //递归右子序列
    //cout<<"finish"<<endl;
}
/*
 * 贪心算法实现
 * n：服务的总人数
 */
int Greedy(int n,int arr[])
{
    int time=0;
    int wait_time=0;
    for(int i=0;i<n;i++){
       wait_time= wait_time+a[i];
       time+=wait_time;
       cout<<"第"<<i+1<<"个顾客的服务时间为"<<a[i]<<","<<"等待时间为:"<<wait_time<<endl;
    }
    return time;
}
int main()
{
    int ans=0;
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=rand()%50+1;
    l=0,r=n-1;
    quickSort(a,l,r);
    ans=Greedy(n,a);
    cout<<ans;
    return 0;
}