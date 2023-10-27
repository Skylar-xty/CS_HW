//
// Created by Skylar_xty on 2023-03-16.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;

class test{
private:
    list<int> a,b,c;
    int n;
    list<int>::iterator p;
public:
    test(int nn){
        n = nn;
        srand(time(0));
        for(int i = 0;i<nn;i++){
            a.push_back(rand()%10);
            b.push_back(rand()%10);
        }
    }
    void browse(list<int> aa){
        for(p=aa.begin();p!=aa.end();p++){
            cout<<*p<<" ";
        }
        cout<<"=========="<<endl;
    }
    void turn(){
        list<int>::iterator pp;
        for(p=a.begin();p!=a.end();p++){
            pp=c.begin();
            pp=find(pp,c.end(),*p);
            if(pp==c.end()){
                c.push_back(*p);
            }
        }

//        for(p=a.begin();p!=a.end();p++){
//            pp=a.begin();
//            pp=find(pp,a.end(),*p);
//            if(pp!=a.end()){
//                a.erase(pp);
//            }
//        }
        for(p=b.begin();p!=b.end();p++){
            pp=c.begin();
            pp=find(pp,c.end(),*p);
            if(pp==c.end()){
                c.push_back(*p);
            }
        }
        browse(a);
        browse(b);
        browse(c);
    }
};

int main(){
    test t(5);
    t.turn();
    return 0;
}