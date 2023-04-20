//
// Created by Skylar_xty on 2023-03-31.
//

//�ļ�
//���캯��������a��list����ѹ��n�����������
//browse����������Ϊlist������������
//Sort�����ɴ�С����
//Write�������������ݣ�ת��Ϊ�ַ��������ӷ��з�"\r\n"��
//���ӳ�һ���ַ����󰴶����Ʒ�ʽд���ı��ļ�"test.txt"�С�
//�򿪸��ı��ļ�����Է��в쿴��ÿ�ж�Ӧ������һ��Ԫ�ء�
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class test
{
private:
    int n,i;
    string s;
    fstream f;
    list<int>a;
    list<int>::iterator p;
public:
    test(int nn)
    {
        n=nn;
        f.open("test.txt",ios::out|ios::binary);
        if(!f)
        {
            cout<<"file error!"<<endl;
            exit(0);
        }
        srand(time(0));
        for(i=0;i<n;++i)
        {
            a.push_back(rand());
        }
    }
    ~test()
    {
        f.close();
    }
    void browse()
    {
        cout<<"========================"<<endl;
        for(p=a.begin();p!=a.end();++p)
        {
            cout<<*p<<endl;
        }
    }
    static bool sort1(int n1,int n2)
    {
        return n1>n2;
    }
    void Sort()
    {
        a.sort(sort1);
    }
    void Write()
    {
        s="";
        for(p=a.begin();p!=a.end();++p)
        {
            s=s+int2str(*p)+"\r\n";
        }
        f.seekp(0,ios::beg);
        f.write((char*)s.c_str(),s.size());
    }
    string int2str(int m)
    {
        string temp;
        stringstream ss;
        ss<<m;
        ss>>temp;
        return temp;
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

