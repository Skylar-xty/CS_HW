//
// Created by Skylar_xty on 2023/4/20.
//
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int num=10000;
const int RANDOM_NUM =100;
double a[num+101];
int b[10];

void bubbleSort(double arr[],int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>a[j+1]){
                double temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"bubble finish!"<<endl;
}
void quickSort(double arr[],int low,int high)
{
    if(low>=high){  // 递归终止条件
        return;
    }
    double mid = arr[(low+high)/2]; // 选取中间元素
    int i = low,j=high;
    while(i<=j){
        while(arr[i]<mid)i++; // 从左向右找到第一个
        while(arr[j]>mid)j--; // 从右向左找到第一个
        if(i<=j){             // 如果左指针小于等于右指针，交换
            double temp =arr[i];
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
int main()
{
    srand(time(NULL));
    for(int i=0;i<num;i++)
    {
        a[i]=(double)((rand()%1000+1)/100);
    }
    for(int i=0;i<10;i++)
    {
        int temp=rand()%100;
        for(int j=1;j<11;j++)
            a[num+10*i+j]=a[temp];
    }
    auto start_clock = high_resolution_clock::now();
//    bubbleSort(a,num);
    quickSort(a,0,num);
    auto end_clock = high_resolution_clock::now();
//    for(int i=0;i<num+100;i++)
//    {
//        cout<<a[i]<<",";
//    }
    cout<<endl;
    auto duration = duration_cast<microseconds>(end_clock - start_clock);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}