//
// Created by Skylar_xty on 2023/11/30.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
using namespace std;

#define MaxNumber 100
int TrackOrder[MaxNumber];//��ʼ�ŵ�����
int MoveDistance[MaxNumber];//��ͷ�ƶ����루�ŵ�����
double AverageDistance;//��ͷƽ���ƶ�����
int direction;//ѡ���ͷ����
int TrackNum;//�ŵ���
int StartTrack;//��ʼ�ŵ���m
int VisitOrder[MaxNumber];//���ʴŵ�����
bool isVisit[MaxNumber];//����Ƿ񱻷��ʹ�
int SumDistance;//��ͷ�ƶ����ܾ���
int choose;

void input();//������ʼ�ŵ��š��ŵ�˳��
void initial();
void output();
void FCFS();//�����ȷ����Ƚ��ȳ�
void SSTF();//���Ѱ��ʱ������
void SCAN();//ɨ�裬�ӿ�ʼ�ŵ���ѡ����ɨ�裬ֱ��û��Ҫ���ʵĴŵ����ط�����ɨ��
void CSCAN();//ѭ��ɨ�裬�Կ�ʼ�ŵ�ʼ����һ������ɨ�裬ֱ��û��Ҫ���ʵĴŵ��ٴ�����Ȧ������Ȧɨ��
void chooseAlgorithm();

int main(){
    input();
    chooseAlgorithm();
    return 0;
}

void input(){
    ifstream readData;
    readData.open("F:\\hitwh1\\courses\\os\\Test\\codes\\data.txt");
    readData>>TrackNum;  //�ŵ�����
    for (int i=0;i<TrackNum;i++)
    {
        readData>>TrackOrder[i];   //�ŵ���������
    }
    readData>>StartTrack;  //��ʼ�ŵ���
    cout<<"�ŵ����� = "<<TrackNum<<endl;
    cout<<"�ŵ��������У�";
    for (int i=0;i<TrackNum;i++)
    {
        cout<<TrackOrder[i]<<" ";
    }
    cout<<endl;
    cout<<"��ʼ�ŵ���m= "<<StartTrack<<endl;
    cout<<"------------------------------------"<<endl;
}
void initial(){
    for (int i=0;i<TrackNum;i++){
        MoveDistance[i] = 0;
        VisitOrder[i] = TrackOrder[i];
        isVisit[i] = false;
    }
    SumDistance = 0;
    AverageDistance = 0;
}

void output(){
    cout<<"��"<<StartTrack<<"�Ŵŵ���ʼ"<<endl;
    cout<<"�����ʵ���һ���ŵ���"<<"\t"<<"�ƶ�����"<<"\t"<<endl;
    for (int i=0;i<TrackNum;i++){
        cout<<VisitOrder[i]<<"\t\t\t"<<MoveDistance[i]<<"\t"<<endl;
    }
    cout<<"ƽ��Ѱ������: "<<setprecision(4)<<AverageDistance<<endl;
    cout<<endl;
}

//�����ȷ����Ƚ��ȳ�
void FCFS(){
    cout<<endl;
    cout<<"FCFS"<<endl;
    initial();

    //��������˳�����η��ʴŵ�
    MoveDistance[0] = abs(TrackOrder[0]-StartTrack);
    SumDistance = MoveDistance[0];
    VisitOrder[0] = TrackOrder[0];

    for (int i=1;i<TrackNum;i++){
        MoveDistance[i] = abs(TrackOrder[i]-TrackOrder[i-1]);
        SumDistance += MoveDistance[i];
        VisitOrder[i] = TrackOrder[i];
    }

    AverageDistance = SumDistance*1.0/TrackNum;
    output();
}

//���Ѱ��ʱ������
void SSTF(){
    cout<<endl;
    cout<<"SSTF"<<endl;
    initial();
    int CurrentTrack = StartTrack;
    int i,j,pointMin;
    int distance[MaxNumber];

    for (i = 0;i<TrackNum;i++){
        for (j = 0;j<TrackNum;j++){
            if (!isVisit[j])
                distance[j] = abs(TrackOrder[j]-CurrentTrack);
            else
                distance[j] = 10000;  //��ʾ����Զ�������ʹ��Ĵŵ��Ͳ��ٷ���
        }
        pointMin = 0;
        for (j = 0;j<TrackNum;j++){
            if (distance[pointMin] > distance[j])
                pointMin = j;   //ָ����С��λ��
        }
        VisitOrder[i] = TrackOrder[pointMin];  //���������и�ֵ
        MoveDistance[i] = abs(TrackOrder[pointMin]-CurrentTrack);  //����ÿ�ε��ƶ�����
        SumDistance += MoveDistance[i];   //�ۼ��ƶ�����
        CurrentTrack = TrackOrder[pointMin];   //�ı䵱ǰ�Ĵŵ���
        isVisit[pointMin] = true;  //����ǰ�Ĵŵ�������Ϊ�ѷ���
    }
    AverageDistance = SumDistance*1.0/(TrackNum);
    output();
}

//ɨ�裬�ӿ�ʼ�ŵ���ѡ����ɨ�裬ֱ��û��Ҫ���ʵĴŵ����ط�����ɨ��
void SCAN(){
    cout<<endl;
    cout<<"SCAN"<<endl;
    cout<<"ѡ���ͷ�ƶ��ķ���,1-����,2-����: "<<endl;
    cin>>direction;
    initial();

    int i,j,temp;
    int SortTrackOrder[MaxNumber];
    for (i = 0;i<TrackNum;i++){//��ʼ��
        SortTrackOrder[i] = TrackOrder[i];
    }

    //ð������
    for (i = 0;i<TrackNum;i++){
        for (j = i;j<TrackNum;j++){
            if (SortTrackOrder[i]>=SortTrackOrder[j]){
                temp = SortTrackOrder[i];
                SortTrackOrder[i] = SortTrackOrder[j];
                SortTrackOrder[j] = temp;
            }
        }
    }

    //�ҵ����ڵ�ǰ�ŵ�֮�⣬���Ǿ�������Ĵŵ���
    int point = 0;
    while(StartTrack>=SortTrackOrder[point]){
        point++;
    }

    int count = 0;
    int currentTrack = StartTrack;

    if (direction == 1){  //��ŵ����ӵķ������
        cout<<"��ŵ����ӵķ������"<<endl;
        for (i = point;i<TrackNum;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
        for (i = point - 1;i>=0;i--){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }
    else if (direction == 2){  //��ŵ����ٵķ������
        cout<<"��ŵ����ٵķ������"<<endl;
        for (i = point-1;i>=0;i--){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
        for (i = point;i<TrackNum;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }
    for (i = 0;i<TrackNum;i++){
        SumDistance += MoveDistance[i];
    }
    AverageDistance = (SumDistance*1.0)/TrackNum;
    output();
}

//ѭ��ɨ�裬�Կ�ʼ�ŵ�ʼ����һ������ɨ�裬ֱ��û��Ҫ���ʵĴŵ��ٴ�����Ȧ������Ȧɨ��
void CSCAN(){

    initial();
    cout<<"CSCAN"<<endl;
    cout<<"ѡ���ͷ�ƶ��ķ���,1-����,2-����: "<<endl;
    cin>>direction;


    int SortTrackOrder[MaxNumber];
    int i,j,temp;
    for (i = 0;i<TrackNum;i++){
        SortTrackOrder[i] = TrackOrder[i];
    }

    //ð������
    for (i = TrackNum - 1;i>0;i--){
        for (j = 0;j<i;j++){
            if (SortTrackOrder[j]>=SortTrackOrder[j+1]){
                temp = SortTrackOrder[j];
                SortTrackOrder[j] = SortTrackOrder[j+1];
                SortTrackOrder[j+1] = temp;
            }
        }
    }

    //�ҵ����ڵ�ǰ�ŵ�֮�⣬���Ǿ�������Ĵŵ���
    int point = 0;
    while(StartTrack>=SortTrackOrder[point]){
        point++;
    }

    int count = 0;
    int currentTrack = StartTrack;
    if (direction == 1){
        cout<<"��ŵ����ӵķ������"<<endl;
        for (i = point;i<TrackNum;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }

        for (i =0;i<point;i++){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }
    else if (direction == 2){//��ŵ����ٵķ������
        cout<<"��ŵ����ٵķ������"<<endl;
        for (i = point-1;i>=0;i--){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
        for (i = TrackNum-1;i>point-1;i--){
            VisitOrder[count] = SortTrackOrder[i];
            MoveDistance[count] = abs(VisitOrder[count]-currentTrack);
            currentTrack = VisitOrder[count];
            count++;
        }
    }

    for (i = 0;i<TrackNum;i++){
        SumDistance += MoveDistance[i];
    }
    AverageDistance = (SumDistance*1.0)/TrackNum;
    output();
}


void chooseAlgorithm()
{
    cout<<"��ѡ���㷨��1-FCFS��2-SSTF��3-SCAN��4-ѭ��SCAN ,0-�˳���"<<endl;
    cin>>choose;
    if (choose==1)
    {
        FCFS();
        chooseAlgorithm();
    }
    else if(choose==2)
    {
        SSTF();
        chooseAlgorithm();
    }
    else if(choose==3){
        SCAN();
        chooseAlgorithm();
    }
    else if(choose==4){
        CSCAN();
        chooseAlgorithm();
    }
    else if(choose==0){
        exit(0);
    }
    else
    {
        cout<<"��������ȷ��ѡ��1-FCFS��2-SSTF��3-SCAN��4-ѭ��SCAN ,0-�˳���"<<endl;
        chooseAlgorithm();
    }
}
