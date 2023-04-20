//
// Created by Skylar_xty on 2023-03-02.
//
#include<iostream>
#include<cstdlib>

using namespace std;
class Army{
private:
    int a;
    double strength;
public:
    Army(){
        a=0;
        strength=0;
    }
    Army(int x){
        a=x;
        strength=(double)100000/a;
        cout<<"current stength:"<<strength<<endl;
    }
    void add(int num,double s_,int flag,double sum,int c){
        a+=num;
        if(flag == 0)//A
            strength = strength;
        else{   //B
            strength = (double)((sum+c*num*s_)/a);
        }
    }
    Army initialize(int x,int z){
        Army army(x);
        for(int i =0;i<100;i++)
        {
            army.a-=z;
        }
        cout<<"after 100days: "<<army.a<<endl;
        return army;
    }
    void output(){
        int cnt=0;
        Army A= initialize(500000,1500);
        Army B= initialize(300000,1350);
        cout<<A.a<<B.a<<endl;
        cout<<A.strength*A.a<<B.strength*B.a<<endl;
        double sumb = B.a*B.strength;
        double s=A.strength;
        while(1){
            cnt++;
            A.add(1000,s,0,0,cnt);
            B.add(1500,s,1,sumb,cnt);
            if((A.strength*A.a)<(B.strength*B.a))
            {
                cout<<"current A:"<<A.strength*A.a<<"current B:"<<B.strength*B.a<<endl;
                cout<<"B better!!!"<<cnt<<endl;
                break;
            }
        }
    }
};
int main()
{
    Army army;
    army.output();
    return 0;
}
