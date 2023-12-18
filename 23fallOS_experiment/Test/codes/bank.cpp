#include<iostream>
using namespace std;

const int p=5;//������
const int r=4;//��Դ����

int num = 1;//��Ҫ������Դ�Ľ������

void init_request(int request[r])
{
    //��ʼ��request����
    cout<<"Input the number of request:"<<endl;
    cin>>num;
    num-=1;//�±��1
    cout<<"Input the request vector:"<<endl;
    for(int i=0;i<r;i++)
        cin>>request[i];
}

void init_matrix(int maximum[p][r],int allocation[p][r],int need[p][r],int available[r],int request[r])
{
    //��ʼ������
    cout<<"Input the Allocation matrix:"<<endl;
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            cin>>allocation[i][j];
    cout<<"Input the Need matrix:"<<endl;
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            cin>>need[i][j];
    //cout<<"Input the Max matrix:"<<endl;
    //Max���������Need��Allocation�����Ƶ��ó�
    //Max[i,j]= Need[i,j]+Allocation[i,j]
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            maximum[i][j]=need[i][j]+allocation[i][j];
    cout<<"Input the available vector:"<<endl;
    for(int i=0;i<r;i++)
        cin>>available[i];
}

void output_func(int allocation[p][r],int need[p][r],int available[r])
{
    //�������
    cout<<endl<<"     "<<"Allocation"<<"     Need"<<"        Available"<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<"P"<<i+1<<"   :";
        for(int j=0;j<r;j++)
        {
            cout<<allocation[i][j]<<' ';

        }
        cout<<"     ";
        for(int j=0;j<r;j++)
            cout<<need[i][j]<<' ';
        if(i==0)
        {
            cout<<"     ";
            for(int k=0;k<r;k++)
                cout<<available[k]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

}

bool compare(int need[],int work[])
{
    bool flg = 1;
    for(int i=0;i<r;i++)
    {
        //����Ƿ��д��ڵ��������
        if(need[i]>work[i])
        {
            flg=0;
            break;
        }
    }
    return flg;
}

int check_security(int allocation[p][r],int need[p][r],int available[r])
{
    //��ȫ�Լ�麯��
    int finish[p] = {0};//��ʼ��finish����
    int work[r];  //����available
    int lis[p];//������¼��ȫʱ�Ķ���
    int cnt=0;
    for(int i=0;i<r;i++)
        work[i] = available[i];//��ʼ��work����
    //���з���
    //ѭ��p��
    for(int m=0;m<p;m++)
    {
        for(int i=0;i<p;i++)
        {
            //�����ǰ����ִ����ɣ�����
            if(finish[i] == 1)
                continue;
                //�ҵ�finish[i] = false
            else{
                //���Need[i,j]<=Work[j]
                if(compare(need[i],work))
                {
                    for(int j=0;j<r;j++)
                        work[j]+=allocation[i][j];
                    finish[i] = 1;
                    lis[cnt++] = i+1;//����״̬���밲ȫ״̬������
                    break;
                }
            }
        }
    }
    int flag=1;
    for(int i=0;i<r;i++)
    {
        if(finish[i]==0)
        {
            flag = 0;
            break; //�������F�Ľ��̣�����ϵͳ���ڲ���ȫ״̬
        }
        else
            continue;
    }
    if(flag)
    {
        cout<<"ϵͳ���ڰ�ȫ״̬��"<<endl;
        cout<<"��ȫ����Ϊ:";
        for(int i=0;i<p;i++)
            cout<<lis[i]<<' ';
        cout<<endl;
    }
    else cout<<"ϵͳ���ڲ���ȫ״̬��"<<endl;
    return flag;

}

void banker(int allocation[p][r],int need[p][r],int available[r],int request[r],int n)
{
    if(!compare(request,need[n]))
    {
        //�������Requesti[j]>Need[i][j],��Ϊ����
        cout<<"����������Դ�ѳ��������������ֵ��"<<endl;
        return ;
    }
    else{
        //���м��㷨(1)û�г���
        if(!compare(request,available))
        {
            //�������Requesti[j]>Available[j]����Ϊ����
            cout<<"�����㹻��Դ������ȴ���"<<endl;
            return ;
        }
        else{
            for(int j=0;j<r;j++)
            {
                available[j]-=request[j];
                allocation[n][j]+=request[j];
                need[n][j]-=request[j];
            }
            if(check_security(allocation,need,available))
            {
                cout<<"��ȫ������Դ��ʽ����"<<endl;
            }
            else
            {
                cout<<"����ȫ����Դ�������ϣ��ָ���ǰ״̬"<<endl;
                for(int j=0;j<r;j++)
                {
                    need[n][j]+=request[j];
                    allocation[n][j]-=request[j];
                    available[j]+=request[j];
                }
            }
        }
    }
    output_func(allocation,need,available);

}

int main()
{
    // maximum:����������allocation:�������need:�������
    // need[i][j]=maximum[i][j]-allocation[i][j];
    int maximum[p][r],allocation[p][r],need[p][r];
    int available[r],request[r];
    init_matrix(maximum,allocation,need,available,request);
    cout<<endl<<"���T0ʱ��ϵͳ�Ƿ��ڰ�ȫ״̬..."<<endl;
    check_security(allocation,need,available);
    int flag = 1;
    while(flag)
    {
        cout<<endl<<"��������Դ�������м��㷨���..."<<endl;
        init_request(request);//��ʼ��request����
        banker(allocation,need,available,request,num);
        cout<<"�Ƿ�������룿(����0�˳�):";
        cin>>flag;
    }

    return 0;
}
/*��������
0 0 3 2
1 0 0 0
1 3 5 4
0 3 3 2
0 0 1 4
0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
1 6 5 6
1 6 2 2
*/
/*
0 0 1 2
1 0 0 0
1 3 5 4
0 6 3 2
0 0 1 4

0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6

1 5 2 0


 */