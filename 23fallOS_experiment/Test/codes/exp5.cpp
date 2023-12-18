#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int trackNum = 8;//访问磁道数：8
struct List {
    int track;//访问磁道
    bool isVisited = false;//磁道状态
};
List list[8];

int path[8];//访问顺序
int totalTrack = 0; //磁头走过的总道数

void initList();//初始化

/*先来先服务*/
void FCFS(int start) {
    /*添加：初始化list  */
    initList();

    totalTrack = 0;//清空
    for (int i = 0; i < trackNum; i++) {
        if (i == 0) {
            totalTrack += abs(list[i].track - start);
        }
        else {
            totalTrack += abs(list[i].track - list[i-1].track);
        }
        list[i].isVisited = true;//修改状态为已被访问
        path[i] = i;//访问节点顺序
    }

    //输出顺序
    cout << "走道顺序：" << start << " → ";
    for (int i = 0; i < trackNum-1; i++) {
        cout<<list[path[i]].track<< " → ";
    }
    cout << list[path[trackNum-1]].track << endl;

    //输出移动总磁道数
    cout << "磁头移动总磁道数：" << totalTrack << endl;
    cout << endl;
}

/*最短寻道优先*/
int closest(int now);
void SSTF(int start) {
    /*添加：初始化list 的节点访问状态 */
    initList();

    totalTrack = 0;//清空
    for (int i = 0; i < trackNum; i++) {
        if (i == 0) {
            totalTrack += abs(list[closest(start)].track - start);
            path[i] = closest(start);
        }
        else {
            totalTrack += abs(list[closest(list[path[i - 1]].track)].track - list[path[i - 1]].track);
            path[i] = closest(list[path[i - 1]].track);
        }
        list[path[i]].isVisited = true;//修改状态为已被访问
    }

    //输出顺序
    cout << "走道顺序：" << start << " → ";
    for (int i = 0; i < trackNum - 1; i++) {
        cout << list[path[i]].track << " → ";
    }
    cout << list[path[trackNum-1]].track << endl;

    //输出移动总磁道数
    cout << "磁头移动总磁道数：" << totalTrack << endl << endl;

}
//寻找距离当前磁道最近的磁道，返回当前磁道的编号
int closest(int now) {
    int min = 0x7FFFFFFF;
    int flag = -1;
    for (int i = 0; i < trackNum; i++) {
        if (list[i].isVisited == false && abs(list[i].track - now) < min) {
            min = abs(list[i].track - now);
            flag = i;
        }
    }
    return flag;
}

/*扫描算法（电梯算法）*///direct：方向，左为0，右为其他；
void SCAN(int start,int direct) {
    /*添加：初始化list 的节点访问状态 */
    initList();

    //排序，从小到大
    for (int i = 0; i < trackNum; i++) {
        int flag = -1;
        int  min = 0x7FFFFFFF;

        for (int j = 0; j < trackNum; j++) {
            if (list[j].track < min &&list[j].isVisited == false) {
                min = list[j].track;
                flag = j;
            }
        }
        path[i] = flag;
        list[flag].isVisited = true;
    }

    totalTrack = 0;//清空

    //如果读写头起始位置比最小磁道还小
    if (start<=list[path[0]].track) {
        totalTrack = list[path[trackNum]].track - start;

        cout << "走道顺序：" << start << " → ";
        for (int i = 0; i < trackNum - 1; i++) {
            cout << list[path[i]].track << " → ";
        }
        cout << list[path[trackNum-1]].track << endl;
    }

        //如果读写头起始位置比最大磁道还大
    else if (start >= list[path[trackNum-1]].track) {
        totalTrack = start - list[path[0]].track;

        cout << "走道顺序：" << start << " → ";
        for (int i = trackNum - 1; i > 0; i--) {
            cout << list[path[i]].track << " → ";
        }
        cout << list[path[0]].track << endl;

    }
        //如果读写头起始位置 介于最小最大之间
    else{

        stack<int> tempstack;
        cout << "走道顺序：" << start << " → ";
        int flag = 0;
        for (int i = 0; i < trackNum; i++) {
            if (list[path[i]].track <= start) {
                tempstack.push(list[path[i]].track);
                flag = i;
            }
        }
        //先向左
        if (direct == 0) {
            totalTrack = start - list[path[0]].track + list[path[trackNum - 1]].track - list[path[0]].track;

            while (!tempstack.empty()){
                cout << tempstack.top() << " → ";
                tempstack.pop();
            }
            for (int i = flag + 1; i < trackNum-1; i++) {
                cout << list[path[i]].track << " → ";
            }
            cout << list[path[trackNum-1]].track << endl;
        }
            //向右走
        else {
            totalTrack = list[path[trackNum - 1]].track - list[path[0]].track + list[path[trackNum - 1]].track - start;

            for (int i = flag + 1; i < trackNum; i++) {
                cout << list[path[i]].track << " → ";
            }
            while (!tempstack.empty()) {
                cout << tempstack.top();
                tempstack.pop();
                if (!tempstack.empty())
                    cout<< " → ";
            }
            cout << endl;
        }
    }

    //输出移动总磁道数
    cout << "磁头移动总磁道数：" << totalTrack << endl << endl;
}

void initList() {
    for (int i = 0; i < trackNum; i++) {
        list[i].isVisited = false;
    }
}

int main() {

    cout << "请输入磁道访问请求序列：";
    for (int i = 0; i < trackNum; i++) {
        cin >> list[i].track;
    }
    cout << endl;
    while (1)	{
        cout << "　１：先来先服务算法\n　２：最短寻道时间优先算法\n　３：电梯算法\n其他：退出" << endl;
        cout << "请输入您选择的算法：";
        int choose, start, direct;
        cin >> choose;
        if (choose != 1 && choose != 2 && choose != 3)
            break;

        cout << "请输入初始磁头位置：";
        cin >> start;
        switch (choose)
        {
            case 1:
                FCFS(start);
                break;

            case 2:
                SSTF(start);
                break;

            case 3:
                cout << "０　：向左移动\n其他：向右移动\n请输入磁头移动方向：";
                cin >> direct;
                SCAN(start, direct);
                break;

            default:
                break;
        }
    }
}