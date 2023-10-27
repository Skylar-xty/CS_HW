//
// Created by Skylar_xty on 2023-03-09.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int a1=1;
class test1{
public:
    int n;
    int m; //公差
public:
    test1(){
        n = 5;
        m = 3;
    }
    test1(int nn,int mm){
        n = nn;
        m = mm;
    }
    int n_x(){
        return a1+(n-1)*m;
    }
    int n_sum(){
        int sum =0;
        sum = n*a1 + 0.5*n*(n-1)*m;
        return sum;
    }
};
class test2:public test1{
protected:
    int w;
public:
    test2(){
        w = 2;
    }
    test2(int nn,int mm,int ww):test1(nn,mm){
        w = ww;
    }
    void output(){
        for(int i = 0 ;i< w;i++){
            test1* tt = new test1(n,m+i);
            for(int j=1;j<=n;j++){
                tt->n = j;
                cout<<tt->n_x();
                if(j!=n)cout<<"+";
            }
            tt->n = n;
            cout<<"="<<tt->n_sum()<<endl;
            delete tt;
        }

    }
};
int main(){
    test2 t(5,2,3);
    t.output();
    return 0;
}