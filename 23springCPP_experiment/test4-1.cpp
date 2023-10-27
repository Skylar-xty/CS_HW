//
// Created by Skylar_xty on 2023-03-23.
//
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
struct student{
    string number;
    string name;
    int score;
    bool operator==(student tt)
    {
        return score == tt.score;
    }
};
class test
{
private:
    string s,s1;
    string s2,s3,s4;
    string::size_type n,n1,n2,n3,n4;
    list<student> a;
    list<student>::iterator p;
public:
    test(){
        s="-01-王小二-66-02-李小三-89-03-张小四-53-";
//        s="-01-A-66-02-B-89-03-C-53";
        //s="-01-A-66-02-B-89-03-C-53";
        s1="-";
    }
    int str2int(string s)
    {
        int temp;
        stringstream ss;

        ss<<s;
        ss>>temp;
        return temp;
    }
    void Find()
    {
        cout<<"========================="<<endl;
        student temp;
        cout<<"input score:";
        cin>>temp.score;
        p=a.begin();
        while(true)
        {
            p=find(p,a.end(),temp);
            if(p!=a.end())
            {
                cout<<p->number<<"-"<<p->name<<"-"<<p->score<<endl;
                ++p;
            }
            else break;
        }
    }
    void browse()
    {
        int pos=0;
        student temp;
        while(true)
        {
            if(s.find(s1,pos)!=string::npos)
            {
                n1=s.find(s1,pos);

                n2=s.find("-",n1+2);  //for Chinese character: 2
                n3=s.find("-",n2+2);
                n4=s.find("-",n3+2);

                s2=s.substr(n1+1,n2-n1-1);
                s3=s.substr(n2+1,n3-n2-1);
                s4=s.substr(n3+1,n4-n3-1);

                temp.number = s2;
                temp.name = s3;
                temp.score = str2int(s4);

                a.push_back(temp);
                pos = n4;
                if(pos+1>=s.size())break; //！注意是大于等于
            }
            else break;
        }
        cout<<"==================="<<endl;
        for(p=a.begin();p!=a.end();p++)
            cout<<p->number<<"-"<<p->name<<"-"<<p->score<<endl;
    }
};


int main()
{
    test t;
    t.browse();
    t.Find();
    cout<<"你好";
    return 0;
}




