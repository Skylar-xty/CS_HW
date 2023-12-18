//
// Created by Skylar_xty on 2023/11/30.
//
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 30
typedef struct PCB {
    char name[20];             // ��������(����)
    int  arrivetime;           //����ʱ�� (����)
    int  running_time;         //����ʱ��
    int  priority;             //���ȼ�
    int  start_time;           //��ʼʱ��
    int  done_time;            //����ʱ��
    int  copyRunning_time;     //����ʱ��Ƭ��ת
    float zztime;              //��¼�ý��̵���תʱ�䣨���ڸ����ã�
    float dqzztime;            //��¼�ý��̵Ĵ�Ȩ��תʱ�䣨���ڸ����ã�
    PCB* next;
} Program;
typedef struct PCBQueue {
    PCB* firstProg;
    PCB* LastProg;
    int size;
} PCBQueue;

// ��������
void print(PCB pro[], int num);//���ÿ�����̵ĵ���ʱ��

void inputProgram(PCB pro[], int num); //�������н��̵ľ�����Ϣ

void PrintRunningprogram(PCB *pro);//����������еĽ��̵���Ϣ

void PrintReadyqueue(PCBQueue *ready_queue);//������������е����н��̵���Ϣ

void PrintSortOfRunningprogram(PCB pro1[],int num);//������̵�����˳��

void CopyProgram(PCB *pro1,PCB *pro2);//������pro2����Ϣ���Ƶ�����pro1��

void Queueinit(PCBQueue* queue);//��ʼ����������

void EnterQueue(PCBQueue* queue, PCB* pro);//��һ�����̲��뵽����������

PCB* poll(PCBQueue* queue);//��һ�����̴Ӿ���������ɾ��

void sortWithEnterTime(PCB pro[], int num);//�����н��̰�����ʱ����������

void EnterQueueOfRuntime(PCBQueue *ready_queue,PCB *program);//��һ�����̰�����ʱ�䳤�̲����������

void EnterQueueOfPriority(PCBQueue *ready_queue,PCB *program);//��һ�����̰����ȼ������������

void FCFS(PCB pro[], int num);//�����ȷ�������㷨

void SJF(PCB pro[],int num);//����ҵ���ȵ����㷨

void HPF(PCB pro[],int num);//�����ȼ������㷨

void RR(PCB pro[], int num);//ʱ��Ƭ��ת�����㷨

//���庯��ʵ��
void print(PCB pro[], int num) {
    int i;

    for (i = 0; i < num; i++) {
        printf("%d ", pro[i].arrivetime);
    }
}

void inputProgram(PCB pro[], int num) {
    int i;

    for (i = 0; i < num; i++) {
        PCB prog;
        printf("\t\t\t\t\t�������%d�����̵����֣�����ʱ�䣬����ʱ�䣬���ȼ�\n\t\t\t\t\t", i + 1);
        scanf("%s", prog.name);
        scanf("%d", &prog.arrivetime);
        scanf("%d", &prog.running_time);
        prog.copyRunning_time = prog.running_time;
        scanf("%d", &prog.priority);
        pro[i] = prog;
    }
}

void PrintRunningprogram(PCB *pro) {
    printf("\t����ִ�С���������%s\n",pro->name);
    printf("\t������������������������������������������������������������������������������������������������\n");
    printf("\t��������  ����ʱ��  ����ʱ��  ���ȼ�  ��ʼʱ��  ����ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");
    printf("\t%s\t\t%d\t%d\t%d",pro->name,pro->arrivetime,pro->running_time,pro->priority);
    printf("\t%d\t%d\t   %5.2f\t%5.2f\n",pro->start_time,pro->done_time,pro->zztime,pro->dqzztime);
    printf("\t������������������������������������������������������������������������������������������������\n\n");
}

void PrintReadyqueue(PCBQueue *ready_queue) {
    PCB *p;

    p=ready_queue->firstProg->next;
    if(!p) {
        printf("\t�޽��̴��ھ���״̬��\n");
        printf("\t������������������������������������������������������������������������������������������������\n\n\n");
        return ;
    }
    printf("\t�������У�\n");
    printf("\t������������������������������������������������������������������������������������������������\n");
    printf("\t��������  ����ʱ��  ����ʱ��  ���ȼ�\n");
    while(p) {
        printf("\t%s\t\t%d\t%d\t%d\n",p->name,p->arrivetime,p->running_time,p->priority);
        p=p->next;
    }
    printf("\t������������������������������������������������������������������������������������������������\n");
    printf("\n\n\n");
}

void PrintSortOfRunningprogram(PCB pro1[],int num) {
    int i;

    printf("\t��������˳�����£�\n");
    printf("\t������������������������������������������������������������������������������������������������\n");
    printf("\t��������  ����ʱ��  ����ʱ��  ���ȼ�  ��ʼʱ��  ����ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");
    for(i=0; i<num; i++) {
        printf("\t%s\t\t%d\t%d\t%d",pro1[i].name,pro1[i].arrivetime,pro1[i].running_time,pro1[i].priority);
        printf("\t%d\t%d\t   %5.2f\t%5.2f\n",pro1[i].start_time,pro1[i].done_time,pro1[i].zztime,pro1[i].dqzztime);
    }
    printf("\t������������������������������������������������������������������������������������������������\n\n\n");
}

void CopyProgram(PCB *pro1,PCB *pro2) {
    memcpy(pro1->name,pro2->name,sizeof(pro2->name));
    pro1->arrivetime=pro2->arrivetime;
    pro1->running_time=pro2->running_time;
    pro1->priority=pro2->priority;
    pro1->start_time=pro2->start_time;
    pro1->done_time=pro2->done_time;
    pro1->zztime=pro2->zztime;
    pro1->dqzztime=pro2->dqzztime;
}

void Queueinit(PCBQueue* queue) {
    if (queue == NULL) {
        return;
    }
    queue->size = 0;
    queue->LastProg = (PCB*)malloc(sizeof(PCB));
    queue->LastProg->next=NULL;//ע����˴˾�
    queue->firstProg = queue->LastProg;
}

void EnterQueue(PCBQueue* queue, PCB* pro) {
    //������̶���
    queue->LastProg->next = (PCB*)malloc(sizeof(PCB));
    queue->LastProg = queue->LastProg->next;
    queue->LastProg->arrivetime = pro->arrivetime;
    memcpy(queue->LastProg->name, pro->name, sizeof(pro->name));
    queue->LastProg->priority = pro->priority;
    queue->LastProg->running_time = pro->running_time;
    queue->LastProg->copyRunning_time = pro->copyRunning_time;
    queue->LastProg->start_time = pro->start_time;
    queue->LastProg->next=NULL;//ע����˴˾�
    queue->size++;
}

PCB* poll(PCBQueue* queue) {
    PCB *temp;

    temp = queue->firstProg->next;
    if (temp == queue->LastProg) {
        queue->LastProg = queue->firstProg;
        queue->LastProg->next=NULL;//ע����˴˾�
        queue->size--;
        return temp;
    }
    queue->firstProg->next = queue->firstProg->next->next;
    queue->size--;

    return temp;
}

void sortWithEnterTime(PCB pro[], int num) { //�����̰�����ʱ�䣨arrivetime��ȫ������
    int i,j;
    PCB temp;

    for (i = 1; i < num; i++) {
        for (j = 0; j < num - i; j++) {
            if (pro[j].arrivetime > pro[j + 1].arrivetime) {
                temp = pro[j];
                pro[j] = pro[j + 1];
                pro[j + 1] = temp;
            }
        }
    }
}

void EnterQueueOfRuntime(PCBQueue *ready_queue,PCB *program) { //�����̵�����ʱ�䣬�ҵ����������е���Ӧλ�ò������ȥ
    PCB *p,*q;
    p=ready_queue->firstProg->next;
    q=ready_queue->firstProg;

    while(p) {
        if(p->running_time>program->running_time) {
            program->next=p;
            q->next=program;
            break;
        }
        q=p;
        p=p->next;
    }
    if(!p) { //�����������Ϊ�ջ�ý��̵�����ʱ�����������뵽��β
        ready_queue->LastProg->next=program;
        ready_queue->LastProg=program;
        program->next=NULL;
    }
    ready_queue->size++;
}

void EnterQueueOfPriority(PCBQueue *ready_queue,PCB *program) {
    PCB *p,*q;
    p=ready_queue->firstProg->next;
    q=ready_queue->firstProg;

    while(p) {
        if(p->priority<program->priority) { //���ȼ������ִ��
            program->next=p;
            q->next=program;
            break;
        }
        q=p;
        p=p->next;
    }
    if(!p) {
        ready_queue->LastProg->next=program;
        ready_queue->LastProg=program;
        program->next=NULL;
    }
    ready_queue->size++;
}

void FCFS(PCB pro[], int num) {
    int time,done_time;
    int i,count,tt,pronum;
    float sum_T_time,sum_QT_time;
    PCB *curpro,*temp_PCB;

    printf("\n\t\t\t\t\t�����ȷ����㷨���̵���ģ��\n\n");
    printf("\t������������������������������������������������������������������������������������������������\n");
    count=0;
    PCB pro2[100];
    sortWithEnterTime(pro, num);                              //���ս��뵽��ʱ��˳������
    PCBQueue* queue = (PCBQueue*)malloc(sizeof(PCBQueue));    //�����������
    Queueinit(queue);                                        //�������г�ʼ��
    EnterQueue(queue, &pro[0]);                              //����һ�������������������
    time = pro[0].arrivetime;                            //��¼��һ�����̵ĵ���ʱ��
    pronum = 1;                                          //��¼��ǰ�Ľ�������
    sum_T_time = 0, sum_QT_time = 0;                   // sum_T_time ��¼�ܵ���תʱ�� ��sum_QT_time ��¼�ܵļ�Ȩ��תʱ��
    while (queue->size > 0) {
        curpro = poll(queue);                           //�ӽ��̶�����ȡ��һ������
        if (time < curpro->arrivetime){
            time = curpro->arrivetime;
        }
        done_time = time + curpro->running_time;               //  done_time   Ϊ�ý��̵Ľ���ʱ�䣨��ʼʱ��+CPU����ʱ�䣩
        curpro->start_time=time;
        curpro->done_time=done_time;
        curpro->zztime = done_time - curpro->arrivetime;//��תʱ��
        curpro->dqzztime = curpro->zztime / curpro->running_time;//��Ȩ��תʱ��
        sum_T_time += curpro->zztime;                                      //  sum_T_time  �ܵ���תʱ�����
        sum_QT_time += curpro->dqzztime;                                     //  sum_T_time  �ܵĴ�Ȩ��תʱ�����
        for (tt = time; tt <= done_time && pronum < num; tt++) { //ģ����̵�ִ�й���
            if (tt >= pro[pronum].arrivetime) {
                EnterQueue(queue, &pro[pronum]);
                pronum++;
            }
        }
        CopyProgram(&pro2[count],curpro);
        PrintRunningprogram(&pro2[count]);
        count++;
        if(queue->size!=0) {
            printf("\t�������У�\n");
            printf("\t������������������������������������������������������������������������������������������������\n");
            printf("\t���� ����ʱ��  ����ʱ�� ���ȼ�\n");
            temp_PCB=queue->firstProg->next;
            for(i=queue->size; i>0; i--) {
                printf("\t%s\t%d\t%d\t%d\n",temp_PCB->name,temp_PCB->arrivetime,temp_PCB->running_time,temp_PCB->priority);
                temp_PCB=temp_PCB->next;
            }
            printf("\t������������������������������������������������������������������������������������������������\n");
            printf("\n\n\n");
        } else {
            printf("\t�޽��̴��ھ���״̬!\n");
            printf("\t������������������������������������������������������������������������������������������������\n\n\n");
        }
        time += curpro->running_time;
        if (queue->size == 0 && pronum < num) {
            //��ֹ����ǰһ������ִ���굽��һ�����̵���֮���޽��̽���
            EnterQueue(queue, &pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro2,count);
    //Print(pro2,count);
    printf("\tƽ����תʱ��Ϊ:%.2f\n", sum_T_time /num);
    printf("\tƽ����Ȩ��תʱ��Ϊ:%.2f\n",sum_QT_time/num);
}

void SJF(PCB pro[],int num) {
    int time,done_time;
    float sum_T_time,sum_QT_time;
    int i,pronum;
    PCBQueue *ready_queue;
    PCB *curpro,pro1[MAXSIZE];

    printf("\n\t\t\t\t\t����ҵ�����㷨���̵���ģ��\n\n");
    printf("\t������������������������������������������������������������������������������������������������\n");
    sortWithEnterTime(pro, num);
    ready_queue = (PCBQueue*)malloc(sizeof(PCBQueue));
    if(!ready_queue) {
        printf("�����������ͷ���ռ�ʧ�ܣ�");
        exit(1);
    }
    Queueinit(ready_queue);
    EnterQueueOfRuntime(ready_queue,&pro[0]);
    time = pro[0].arrivetime;
    pronum = 1;                     //��¼��ǰ�Ľ���
    sum_T_time = 0, sum_QT_time = 0;
    i=0;
    while(ready_queue->size>0) {
        curpro=poll(ready_queue);//���������еĶ�ͷ���̽���CPU������
        if(time<curpro->arrivetime) { //����ý�������һ�����еĽ��̽���ʱ��֮���м������CPU����ʱ���Ϊ�ý��̵���ʱ��
            time=curpro->arrivetime;
        }
        done_time=time+curpro->running_time;
        curpro->start_time=time;
        curpro->done_time=done_time;
        curpro->zztime = done_time - curpro->arrivetime;//��תʱ��
        curpro->dqzztime = curpro->zztime / curpro->running_time;//��Ȩ��תʱ��
        //��ӡ�������еĽ���
        PrintRunningprogram(curpro);
        //��curpro����Ϣ���Ƶ�pro1[i]��
        CopyProgram(&pro1[i],curpro);
        i++;
        sum_T_time += curpro->zztime;
        sum_QT_time += curpro->dqzztime;
        while(pronum<num) { //����CPU�еĽ������е�ʱ���ڵ���Ľ��̷����������
            if(pro[pronum].arrivetime<=done_time) {
                EnterQueueOfRuntime(ready_queue,&pro[pronum]);
                pronum++;
            } else {
                break;
            }
        }
        //��ӡ��������
        PrintReadyqueue(ready_queue);
        time=done_time;
        if(ready_queue->size==0&&pronum<num) { //��ֹ����ǰһ������ִ���굽��һ�����̵���֮���޽��̽���
            EnterQueueOfRuntime(ready_queue,&pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro1,num);
    printf("\tƽ����תʱ��Ϊ:%.2f\n", sum_T_time / num);
    printf("\tƽ����Ȩ��תʱ��Ϊ:%.2f\n",sum_QT_time/num);
}

void HPF(PCB pro[],int num) {
    int time,done_time;
    float sum_T_time,sum_QT_time;
    int i,pronum;
    PCBQueue *ready_queue;
    PCB *curpro,pro1[MAXSIZE];

    printf("\n\t\t\t\t\t�����ȼ��㷨���̵���ģ��\n\n");
    printf("\t������������������������������������������������������������������������������������������������\n");
    sortWithEnterTime(pro, num);
    ready_queue = (PCBQueue*)malloc(sizeof(PCBQueue));
    if(!ready_queue) {
        printf("�����������ͷ����ڴ�ʧ�ܣ�");
        exit(1);
    }
    Queueinit(ready_queue);
    EnterQueueOfPriority(ready_queue,&pro[0]);
    time = pro[0].arrivetime;
    pronum = 1;                   //��¼��ǰ�Ľ���
    sum_T_time = 0, sum_QT_time = 0;
    i=0;
    while(ready_queue->size>0) {
        curpro=poll(ready_queue);//���������еĶ�ͷ���̽���CPU������
        if(time<curpro->arrivetime) { //����ý�������һ�����еĽ��̽���ʱ��֮���м������CPU����ʱ���Ϊ�ý��̵���ʱ��
            time=curpro->arrivetime;
        }
        done_time=time+curpro->running_time;
        curpro->start_time=time;
        curpro->done_time=done_time;
        curpro->zztime = done_time - curpro->arrivetime;//��תʱ��
        curpro->dqzztime = curpro->zztime / (curpro->running_time + 0.0);//��Ȩ��תʱ��
        //��ӡ�������еĽ���
        PrintRunningprogram(curpro);
        //��curpro����Ϣ���Ƶ�pro1[i]��
        CopyProgram(&pro1[i],curpro);
        i++;
        sum_T_time += curpro->zztime;
        sum_QT_time += curpro->dqzztime;
        while(pronum<num) { //����CPU�еĽ������е�ʱ���ڵ���Ľ��̷����������
            if(pro[pronum].arrivetime<=done_time) {
                EnterQueueOfPriority(ready_queue,&pro[pronum]);
                pronum++;
            } else {
                break;
            }
        }
        //��ӡ��������
        PrintReadyqueue(ready_queue);
        time=done_time;
        if(ready_queue->size==0&&pronum<num) { //��ֹ����ǰһ������ִ���굽��һ�����̵���֮���޽��̽���
            EnterQueueOfPriority(ready_queue,&pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro1,num);
    printf("\tƽ����תʱ��Ϊ:%.2f\n", sum_T_time / num);
    printf("\tƽ����Ȩ��תʱ��Ϊ:%.2f\n",sum_QT_time/num);
}
void RR(PCB pro[], int num) { //ʱ��Ƭ��ת�㷨
    int time,done_time,T_time;
    int i,count,tt,timeslice,pronum;
    float QT_time,sum_T_time,sum_QT_time;
    PCB *curpro,*temp_PCB;

    printf("\n\t\t\t\t\tʱ��Ƭ��ת�㷨���̵���ģ��\n\n");
    printf("\t������������������������������������������������������������������������������������������������\n");
    count=0;
    PCB pro2[100];
    printf("\t������ʱ��Ƭ��С:");
    scanf("%d", &timeslice);
    sortWithEnterTime(pro, num);
    PCBQueue* queue = (PCBQueue*)malloc(sizeof(PCBQueue));
    Queueinit(queue);
    pro[0].start_time = pro[0].arrivetime;
    EnterQueue(queue, &pro[0]);
    time = 0;
    pronum = 1;
    sum_T_time = 0, sum_QT_time = 0;
    while (queue->size > 0) {
        curpro = poll(queue);                      // �Ӿ���������ȡ��һ������
        if (time < curpro->arrivetime) {
            time = curpro->arrivetime;                 // ���㿪ʼ����ʱ��
        }
        if (timeslice >= curpro->running_time) {        // ���ʣ��ʱ��С��ʱ��Ƭ  ����������
            for (tt = time; tt <= time + curpro->running_time && pronum < num; tt++) {  // ģ����̵�ִ�й���
                if (tt >= pro[pronum].arrivetime) {     // ͳ�ƴӴ�����ʼ������֮���м������̵���
                    pro[pronum].start_time = tt;
                    EnterQueue(queue, &pro[pronum]);
                    pronum++;
                }
            }
            time += curpro->running_time;
            curpro->running_time = 0;
            curpro->done_time = time;
            T_time = curpro->done_time - curpro->start_time;
            QT_time = T_time / (curpro->copyRunning_time + 0.0);
            sum_T_time += T_time;
            sum_QT_time += QT_time;

            strcpy(pro2[count].name, curpro->name) ;
            pro2[count].arrivetime=curpro->arrivetime;
            pro2[count].running_time= curpro->copyRunning_time;
            pro2[count].priority=curpro->priority;
            pro2[count].start_time=curpro->start_time;
            pro2[count].done_time=curpro->done_time;
            pro2[count].zztime=T_time;
            pro2[count].dqzztime=QT_time;
            count++;

            printf("\n\tִ����ɡ���������%s��\n",curpro->name);
            printf("\t������������������������������������������������������������������������������������������������\n");
            if(queue->size!=0) {
                printf("\t�������У�\n");
                printf("\t������������������������������������������������������������������������������������������������\n");
                printf("\t���� ����ʱ��  ����ʱ��  ���ȼ�\n");
                PCB* temp_PCB=queue->firstProg->next;
                for(i=queue->size; i>0; i--) {
                    printf("\t%s\t%d\t%d\t   %d\n",temp_PCB->name,temp_PCB->arrivetime,temp_PCB->running_time,temp_PCB->priority);
                    temp_PCB=temp_PCB->next;
                }
                printf("\t������������������������������������������������������������������������������������������������\n\n\n");
            } else {
                printf("\t �޽��̴��ھ���״̬��\n");
                printf("\t������������������������������������������������������������������������������������������������\n\n\n");
            }

            if (queue->size == 0 && pronum < num) {   //��ֹ����ǰһ������ִ���굽��һ�����̵���֮���޽��̽���
                pro[pronum].start_time = pro[pronum].arrivetime;
                EnterQueue(queue, &pro[pronum]);
                pronum++;
            }
            continue;
        }
        for (tt = time; tt <= time + timeslice && pronum < num; tt++) {    //ģ����̵�ִ�й���
            if (tt >= pro[pronum].arrivetime) { // ͳ�ƴӴ�����ʼ������֮���м������̵���
                pro[pronum].start_time = tt;
                EnterQueue(queue, &pro[pronum]);
                pronum++;
            }
        }

        printf("\n\t����ִ�С���������%s\n",curpro->name);
        printf("\t������������������������������������������������������������������������������������������������\n");
        if(queue->size!=0) {
            printf("\t�������У�\n");
            printf("\t������������������������������������������������������������������������������������������������\n");
            printf("\t���� ����ʱ��  ����ʱ��  ���ȼ�\n");
            temp_PCB=queue->firstProg->next;
            for(i=queue->size; i>0; i--) {
                printf("\t%s\t%d\t%d\t%d\n",temp_PCB->name,temp_PCB->arrivetime,temp_PCB->running_time,temp_PCB->priority);
                temp_PCB=temp_PCB->next;
            }
            printf("\t������������������������������������������������������������������������������������������������\n\n\n");
        } else {
            printf("\t �޽��̴��ھ���״̬��\n");
            printf("\t������������������������������������������������������������������������������������������������\n\n\n");
        }

        time += timeslice;
        curpro->running_time -= timeslice;
        EnterQueue(queue, curpro);    //��ǰ����δ���  ������ӵ�������

        if (queue->size == 0 && pronum < num) {   //��ֹ����ǰһ������ִ���굽��һ�����̵���֮���޽��̽���
            pro[pronum].start_time = pro[pronum].arrivetime;
            EnterQueue(queue, &pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro2,count);
    printf("\tƽ����תʱ��Ϊ:%.2f\n", sum_T_time / num);
    printf("\tƽ����Ȩ��תʱ��Ϊ:%.2f\n",sum_QT_time/num);
}

void menu() {
    printf("\t\t\t\t\t<<-------------����ϵͳ���̵����㷨ģ�����----------����>>\n");
    printf("\t\t\t\t\t1.�����ȷ����㷨\n");
    printf("\t\t\t\t\t2.�̽��������㷨\n");
    printf("\t\t\t\t\t3.�����ȼ��㷨\n");
    printf("\t\t\t\t\t4.ʱ��Ƭ��ת�㷨\n");
    printf("\t\t\t\t\t5.�˳�\n");
    printf("\t\t\t\t\t��ѡ����̵����㷨:");
}

int main() {
    int n, t = 1;
    int proNum,  choice;
    PCB pro[MAXSIZE],temp_pro[MAXSIZE];

    printf("\n\n\t\t\t\t\t<<-------------���̳�ʼ��----------����>>\n");
    printf("\t\t\t\t\t��������̵ĸ�����");
    scanf("%d", &proNum);
    inputProgram(pro, proNum);
    while (t) {
        menu();
        memcpy(temp_pro, pro, (sizeof(pro) / sizeof(pro[0])) * sizeof(PCB));
        scanf("%d", &n);
        while (n <= 0 || n > 5) {
            printf("\t\t\tָ���ȷ������������ָ� ");
            scanf("%d", &n);
        }
        system("cls");
        switch (n) {
            case 1: {
                FCFS(temp_pro, proNum);
                break;
            }
            case 2: {

                SJF(temp_pro, proNum);
                break;
            }
            case 3: {
                HPF(temp_pro, proNum);
                break;
            }
            case 4: {
                RR(temp_pro, proNum);
                break;
            }
            case 5: {
                t = 0;
                break;
            }
        }
        getchar();
        printf("\n\t�����������.......");
        getchar();
        system("cls");
    }
    system("cls");
    printf("\n\n\t\t\t\t\t���ѳɹ��˳�ϵͳ������\n");

    return 0;
}