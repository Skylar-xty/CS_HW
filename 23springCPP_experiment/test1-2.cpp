//
// Created by Skylar_xty on 2023-03-08.
//
#include <iostream>
using namespace std;
const double zl1=1.0,zl2=5.0/3;
const int A_100=500000-100*1500,B_100=300000-100*1350;
const int A_zs=1500,B_zs=1350;
const int A_zb=1000,B_zb=1500;

class test1
{
protected:
    int d;
public:
    test1()
    {
        d=1;
    }
    test1(int dd)
    {
        d = dd;
    }
    double A_zl()
    {
        return A_100+(A_zb-A_zs)*d;
    }
    double B_zl()
    {
        int i;
        int n,n1,n2;
        double x;
        n=B_100;n1=n;n2=0;
        for(i=1;i<=d;i++)
        {
            x=(double)B_zs/n;
            n=n-1350+1500;
            n1=n_old(n1,x);
            n2=n_new(n2,x);
        }
        return n1*zl2+n2*zl1;
    }
    int n_old(int n1,double x){
        return n1-n1*x;
    }
    int n_new(int n2,double x){
        return n2-n2*x+1500;
    }
};
class test2:public test1
{
protected:
public:
    test2()
    {
    }
    test2(int dd):test1(dd){}
    int days()
    {
        int i;
        for(i=1;;i++)
        {
            test2* t = new test2(i);
            if(t->A_zl()<t->B_zl())break;
            delete t;
        }
        return i;
    }
};
int main(){
    test2 t;
    cout<<t.days()<<endl;
    return 0;
}
