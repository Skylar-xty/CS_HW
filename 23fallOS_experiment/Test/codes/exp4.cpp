
#include <iostream>
#include <string>
using namespace std;

int processNum = 0;//进程个数
int totalRAM = 0;	//给定的内存

//分区表
int partitionNum=0;	//分区个数
struct RAM{
    int processNo;			//进程编号
    int start=0;			//首址
    int length=0;			//长度大小
    int end=0;				//结束
    int status=0;	//分区状态
};
RAM ram[100];//下标i表示区号

//可用表
int freeNum=0;//空闲分区个数
struct FREERAM{
    int freePartNo=-1;	//空闲区号
    int freeLength=-1;	//空闲区长度
    int freeStart=-1;	//空闲区起址
};
FREERAM freePart[100];//空闲分区表，可用表

//请求表
int reqNum=0;//请求进程个数
struct REQUEST{
    string reqProcessNo;	//请求进程名
    int reqLength;			//请求进程长度
    int reqed=0;			//请求进程状态（即是否分配处理）
};
REQUEST request[100];

//分区表
struct RamNode {
    int partNo;				//每个节点都是一个分区，有一个区号，默认从0开始
    string processNo;		//如果被占用，则显示被占用的进程编号
    int start = 0;			//分区首址
    int length = 0;			//分区长度大小
    int end = 0;			//分区尾址
    int status = 0;			//分区状态
    RamNode *next;			//下一个分区
};
typedef RamNode *ramNode;
ramNode head = NULL, tail = NULL, p, q;

//输出分区表
void printDongtai();

//初始化
void InitDongtai() {
    cout<< "*******初始化******" <<endl;
    cout << "　请输入内存总大小：";
    cin >> totalRAM;
    cout << "　请输入进程个数：";
    cin >> processNum;
    cout << "　请输入进程 1到" << processNum << " 所需要的内存空间：";
    for (int i = 0; i < processNum; i++) {
        int tempRam = 0;
        cin >> tempRam;

        //看一下能不能放下第 i 个进程
        if (i==0 && tempRam < totalRAM) {
            p = new RamNode;
            p->partNo = i;						//节点区号
            p->processNo = to_string(i + 1);	//占用进行号
            p->start = 0;						//起址
            p->length = tempRam;				//长度
            p->end = p->start + p->length - 1;	//终址
            p->status = 1;						//状态
            p->next = NULL;

            partitionNum++;

            if (head == NULL) {
                head = p; q = p;
            }
            else {
                q->next = p;
                q = p;
            }
        }
        else if(tempRam+q->end<totalRAM){
            p = new RamNode;
            p->partNo = i;
            p->processNo =to_string(i + 1);
            p->start = q->end + 1;
            p->length = tempRam;
            p->end = p->start + p->length - 1;
            p->status = 1;
            p->next = NULL;

            partitionNum++;

            if (head == NULL) {
                head = p;
                q = p;
            }
            else {
                q->next = p;
                q = p;
            }
        }
            //放不下了o(╥﹏╥)o进入请求队列吧，等会儿写
        else {
            request[reqNum].reqProcessNo = to_string(i + 1);
            request[reqNum].reqLength = tempRam;
            reqNum++;
        }
    }
    //如果分配总内存有剩余，最后剩余空间也是一个分区
    if (q->end < totalRAM - 1) {
        p = new RamNode;
        p->partNo = q->partNo + 1;
        p->start = q->end + 1;
        p->end = totalRAM - 1;
        p->status = 0;
        p->next = NULL;
        p->length = totalRAM - p->start ;
        if (head == NULL) {
            head = p;
            q = p;
        }
        else {
            q->next = p;
            q = p;
        }

    }
    //尾指针，先放着，应该有用，(⊙o⊙)…最终没用到
    tail = p;
}

//初始化分区的区号，每次当改变链表结构的时候，都要运行一次。
void InitpartNo() {
    int i = 0;
    for (p = head; p != NULL; p=p->next) {
        p->partNo = i;
        i++;
    }
}

//给出第i个请求任务的插入点p，实现链表插入
void insert(ramNode &p,int i) {
    p->processNo = request[i].reqProcessNo;
    p->status = 1;
    //如果请求长度等于空闲长度，最好不过了
    if (request[i].reqLength == p->length) {}
        //请求＜空闲，需要分割了o(╥﹏╥)o
    else {
        q = new RamNode;
        q->end = p->end;
        p->end = p->start + request[i].reqLength - 1;
        p->length = request[i].reqLength;

        q->partNo = p->partNo + 1;
        q->start = p->end + 1;
        q->length = q->end - q->start + 1;
        q->status = 0;

        q->next = p->next;
        p->next = q;
    }
    //修改请求表请求进程状态为 已分配
    request[i].reqed = 1;
}

/*最先适应算法*/
void zuixianSuanfa(int &i) {
    for (i; i < reqNum; i++) {
        //按空闲分区首地址递增
        for (p = head; p != NULL; p = p->next) {
            //如果当前请求进程请求长度小于最先找到的空闲分区长度，则进行分配
            if (request[i].reqLength <= p->length && p->status == 0) {
                insert(p, i);
                break;
            }
        }
        //第1个请求进程，遍历完链表，仍然找不到内存去，直接返回。
        if (i == 0 && p == NULL) {
            return;
        }
        else if (p == NULL) {
            return;
        }
    }
}

/*更新请求表信息，已经分配的进程取出*/
void refeshReq(int i) {
    int temp = reqNum;
    reqNum = reqNum - i;
    for (int j = 0; j < temp; i++, j++) {
        request[j].reqProcessNo = request[i].reqProcessNo;
        request[j].reqLength = request[i].reqLength;
        request[j].reqed = request[i].reqed;
    }

}

/*最先适应算法*/
void zuixian() {
    cout<<"当前请求表信息如下："<<endl;
    cout<<"顺序\t进程名\t请求长度"<<endl;
    for (int i = 0; i < reqNum; i++) {
        cout << i+1 <<"\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
    }
    int i=0;
    zuixianSuanfa(i);
    //未做任何分配，直接返回
    if (i == 0) {
        cout << "该策略下空间不足，未做任何分配！" << endl;
        return;
    }
        //全部分配完毕
    else if (i == reqNum) {
        cout << "请求表中的进程全部分配完毕！" << endl;
    }
        //只完成部分分配
    else {
        cout << "请求表中的进程部分分配完毕！剩余未分配进程如下：" << endl;
        cout << "\t进程名\t请求长度" << endl;
        for (int i = 0; i < reqNum; i++) {
            if (request[i].reqed == 0) {
                cout << "\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
            }
        }
    }
    cout << "分配后内存使用情况如下：" << endl;
    printDongtai();
    InitpartNo();
    //对请求表数据更新（删除）
    refeshReq(i);
    return;
}

/*交换a和b的值*/
void change(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*找出所有的空闲分区，并放在空闲分区表中*/
void findFreePart() {
    InitpartNo();//初始化一下
    //初始化空闲表
    for (int i = 0; i <= freeNum; i++) {
        freePart[i].freePartNo = -1;
        freePart[i].freeStart = -1;
        freePart[i].freeLength = -1;
    }
    freeNum = 0;
    //先揪出那些空闲分区
    for (p = head; p != NULL; p = p->next) {
        //空闲状态分区，进入可用表
        if (p->status == 0) {
            freePart[freeNum].freePartNo = p->partNo;
            freePart[freeNum].freeStart = p->start;
            freePart[freeNum].freeLength = p->length;
            freeNum++;
        }
    }
}

/*对找出所有空闲区进行排序：递增*/
void InitZuijia() {
    findFreePart();
    //按空闲分区大小递增排序
    for (int i = 0; i < freeNum - 1; i++) {
        for (int j = 0; j < freeNum - i - 1; j++) {
            if (freePart[j].freeLength > freePart[j + 1].freeLength) {
                change(freePart[j].freePartNo, freePart[j + 1].freePartNo);
                change(freePart[j].freeStart, freePart[j + 1].freeStart);
                change(freePart[j].freeLength, freePart[j + 1].freeLength);
            }
        }
    }
}

/*找出当前i号请求进行能放得下的区号，并返回区号*/
int findInsertPartNo(int i) {
    //找到当前i能放得下的区号
    int partNo = -1;
    for (int j = 0; j < freeNum; j++) {
        if (request[i].reqLength <= freePart[j].freeLength) {
            partNo = freePart[j].freePartNo;
            //cout << "找到区号：" << partNo << endl;
            return partNo;
        }
    }
    return -1;
}

/*最佳使用算法*/
void zuijia() {
    cout << "当前请求表信息如下：" << endl;
    cout << "顺序\t进程名\t请求长度" << endl;
    for (int i = 0; i < reqNum; i++) {
        cout << i + 1 << "\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
    }

    InitZuijia();
    int i=0;
    for (i; i < reqNum; i++) {

        //找到当前i能放得下的区号
        int partNo = -1;
        partNo = findInsertPartNo(i);

        if (i==0 && partNo == -1) {
            cout << "该策略下空间不足，未做任何分配！" << endl;
            return;
        }
        else if (partNo == -1) {
            cout << "仅分配部分进程！剩余未分配进程如下：" << endl;
            cout << "\t进程名\t请求长度" << endl;
            for (int j = 0; j < reqNum; j++) {
                if (request[j].reqed == 0) {
                    cout << "\t" << request[j].reqProcessNo << "\t" << request[j].reqLength << endl;
                }
            }
            break;
        }

        //寻找插入点并放入
        for (p = head; p != NULL; p = p->next) {
            if (p->partNo == partNo) {
                //cout << "找到对应的插入点" << endl;
                insert(p,i);
            }
        }
        //初始化链表、空闲表
        InitZuijia();
    }
    if (i == reqNum)
        cout << "请求表中的进程全部分配完毕！" << endl;
    printDongtai();

    //对请求表数据更新（删除）
    refeshReq(i);
}

//最坏适应算法

/*对找出所有空闲区安装递减排序*/
void InitZuihuai() {
    findFreePart();
    //按空闲分区大小递减排序
    for (int i = 0; i < freeNum - 1; i++) {
        for (int j = 0; j < freeNum - i - 1; j++) {
            if (freePart[j].freeLength < freePart[j + 1].freeLength) {
                change(freePart[j].freePartNo, freePart[j + 1].freePartNo);
                change(freePart[j].freeStart, freePart[j + 1].freeStart);
                change(freePart[j].freeLength, freePart[j + 1].freeLength);
            }
        }
    }
}

/*最坏适应算法*/
void zuihuai() {
    cout << "当前请求表信息如下：" << endl;
    cout << "顺序\t进程名\t请求长度" << endl;
    for (int i = 0; i < reqNum; i++) {
        cout << i + 1 << "\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
    }

    InitZuihuai();
    int i = 0;
    for (i; i < reqNum; i++) {

        //找到当前i能放得下的区号
        int partNo = -1;
        partNo = findInsertPartNo(i);

        if (i == 0 && partNo == -1) {
            cout << "该策略下空间不足，未做任何分配！" << endl;
            return;
        }
        else if (partNo == -1) {
            cout << "仅分配部分进程！剩余未分配进程如下：" << endl;
            cout << "\t进程名\t请求长度" << endl;
            for (int j = 0; j < reqNum; j++) {
                if (request[j].reqed == 0) {
                    cout << "\t" << request[j].reqProcessNo << "\t" << request[j].reqLength << endl;
                }
            }
            break;
        }

        //寻找插入点并放入
        for (p = head; p != NULL; p = p->next) {
            if (p->partNo == partNo) {
                insert(p, i);
            }
        }
        //初始化链表、空闲表
        InitZuihuai();
    }
    if (i == reqNum)
        cout << "请求表中的进程全部分配完毕！" << endl;
    printDongtai();

    //对请求表数据更新（删除）
    refeshReq(i);
}

//分配一个分区
void feipeiFenqu() {
    if (reqNum == 0) {
        cout << "当前没有未分配空间的进程！" << endl << endl;
        return;
    }
    cout << "　　1、最先适应算法" << endl;
    cout << "　　2、最佳适应算法" << endl;
    cout << "　　3、最坏适应算法" << endl;
    cout << "　　请选择分配策略：";
    int choose;
    cin >> choose;


    switch (choose)	{
        case 1:
            zuixian();
            break;

        case 2:
            zuijia();
            break;

        case 3:
            zuihuai();
            break;

        default:
            break;
    }
}

void printDongtai() {
    cout << "区号\t首址\t长度\t尾址\t状态\t占用进程编号" << endl;
    int i = 0;
    for (p = head; p != NULL; p = p->next) {
        cout << " " << p->partNo << "\t" << p->start << "\t" << p->length << "\t" << p->end << "\t";
        if (p->status == 1)
            cout << "占用\t" << p->processNo << endl;
        else
            cout << "空闲" << endl;
        i++;
    }
    cout << endl;
}

//释放一个分区
void shifangFenqu() {
    cout << "请输入欲释放内存的区号：";
    int freePart;
    cin >> freePart;
    p = head;
    for (int i = 0; i <= freePart; i++) {
        if(i!=freePart)
            p = p->next;
    }
    if (p->status == 1) {
        p->status = 0;
        p->processNo = "";
        cout << freePart<<"号分区释放成功！" << endl;

        //分区合并·碎片整理
        for (p = head; p != NULL; ) {
            if (p->status == 0  && p->next!=NULL) {
                if (p->next->status == 0) {
                    p->end = p->next->end;
                    p->length = p->length + p->next->length;

                    q = p->next;
                    p->next = q->next;
                    delete q;
                }
                else {
                    p = p->next;
                }
            }
            else {
                p = p->next;
            }
        }//碎片整理结束

        InitpartNo();
    }
    else {
        cout << "当前分区空闲，无需释放！" << endl;
    }
    printDongtai();
    cout << endl;
}

//添加进程到请求队列中
void addProcess() {
    cout << "请输入进程编号和请求长度：";
    //如果进程编号不存在，则继续执行
    if (1) {
        cin >> request[reqNum].reqProcessNo >> request[reqNum].reqLength;
        reqNum++;
        cout<<"添加成功！"<<endl;
    }
    cout << endl;
}

int main(){
    InitDongtai();
    while (1) {
        cout << "********菜  单********" << endl;
        cout << "　1、显示分区状态" << endl;
        cout << "　2、释放分区" << endl;
        cout << "　3、分配分区" << endl;
        cout << "　4、添加进程（作业）" << endl;

        cout << "　请输入选项：";
        int choice;
        cin >> choice;

        switch (choice){
            case 1:
                printDongtai();
                break;

            case 2:
                shifangFenqu();
                break;

            case 3:
                feipeiFenqu();
                break;

            case 4:
                addProcess();
                break;

            default:
                break;
        }
    }
    return 0;
}