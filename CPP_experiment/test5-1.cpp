//
// Created by Skylar_xty on 2023-03-30.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <ctime>
using namespace std;

class test
{
private:
    list<int> a;
    list<int>::iterator p;
    fstream f;
    string s,s1;
    string::size_type n1,n2;
    int n,i;
public:
    test(int nn){
        n = nn;
        s="\r\n";
        srand(time(0));
        int temp;
        for(i=0;i<n;i++){
            temp = rand();
            a.push_back(temp);
        }
        f.open("../test5-1.txt",ios::out|ios::binary);
        if(!f)
        {
            cout<<"file error!"<<endl;
            exit(0);
        }
    }
    ~test()
    {
        f.close();
    }
    string int2str(int x)
    {
        string temp;
        stringstream number;

        number<<x;
        number>>temp;
        return temp;
    }
    static bool compare(int x,int y)  //!
    {
        return x>y;
    }
    void Sort()
    {
//        sort(a.begin(),a.end(),true);
        a.sort(compare);
//        sort(a.begin(),a.end(),compare);
    }
    void browse(){
        cout<<"==========="<<endl;
        for(p=a.begin();p!=a.end();p++)
        {
            cout<<*p<<"  ";
        }
    }
    void Write(){
        string temp;
        for(p=a.begin();p!=a.end();p++){

            temp= int2str(*p);
            cout<<temp<<",";
            s = s+temp+"\r\n";
        }
        cout<<endl;
        cout<<s<<endl;

        //==============================
        int pos = 0;
        while(1)
        {
            if(s.find("\n",pos)!=string::npos){
                n1=s.find("\n",pos);
                n1=s.rfind("\n",n1);
                n2=s.find("\n",n1+1);
                s1=s.substr(n1+1,n2-n1);
                cout<<"substr:"<<s1<<endl;
                f.seekp(0,ios::end);
                f.write((char*)s1.c_str(),s1.size());
                pos=n1+1; //!
                if(pos+1>=s.size())break;
            }
            else cout<<"no find!"<<endl;
        }

        cout<<"finish write!"<<endl;
    }
};


int main()
{
    test t(5);
    t.Sort();
    t.browse();
    t.Write();
    return 0;
}
