//
// Created by Skylar_xty on 2023-03-02.
//
#include<iostream>
#include<cstdlib>

using namespace std;
class Army{
private:
    int a,b;
    //double strengtha,strengthb;
    //int suma,sumb;
public:
    Army(){
        a=500000;
        b=300000;
        //suma=0;
        //sumb=0;
        strengtha=3;
        strengthb=5;
    }
    void add(){
        a+=1000;
        b+=1500;
        //suma+=1000*strengtha;
        //sumb+=1500*strengtha;
    }
    void initialize(){
        for(int i =0;i<100;i++)
        {
            a-=1500;
            b-=1350;
            //suma-=1500*strengtha;
            //sumb-=1350*strengthb;
        }
        cout<<"current a:"<<a<<endl;
        cout<<"current b:"<<b<<endl;
    }
    void output(){
        int cnt=0;
        while(1){
            cnt++;
            this->add();
            if((this->suma)<(this->sumb))
            {
                cout<<"B!!!"<<cnt<<endl;
                break;
            }
        }
    }
};
int main()
{
    Army army;
    army.initialize();
    army.output();
    return 0;
}
