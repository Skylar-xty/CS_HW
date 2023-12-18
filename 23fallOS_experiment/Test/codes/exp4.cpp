
#include <iostream>
#include <string>
using namespace std;

int processNum = 0;//���̸���
int totalRAM = 0;	//�������ڴ�

//������
int partitionNum=0;	//��������
struct RAM{
    int processNo;			//���̱��
    int start=0;			//��ַ
    int length=0;			//���ȴ�С
    int end=0;				//����
    int status=0;	//����״̬
};
RAM ram[100];//�±�i��ʾ����

//���ñ�
int freeNum=0;//���з�������
struct FREERAM{
    int freePartNo=-1;	//��������
    int freeLength=-1;	//����������
    int freeStart=-1;	//��������ַ
};
FREERAM freePart[100];//���з��������ñ�

//�����
int reqNum=0;//������̸���
struct REQUEST{
    string reqProcessNo;	//���������
    int reqLength;			//������̳���
    int reqed=0;			//�������״̬�����Ƿ���䴦��
};
REQUEST request[100];

//������
struct RamNode {
    int partNo;				//ÿ���ڵ㶼��һ����������һ�����ţ�Ĭ�ϴ�0��ʼ
    string processNo;		//�����ռ�ã�����ʾ��ռ�õĽ��̱��
    int start = 0;			//������ַ
    int length = 0;			//�������ȴ�С
    int end = 0;			//����βַ
    int status = 0;			//����״̬
    RamNode *next;			//��һ������
};
typedef RamNode *ramNode;
ramNode head = NULL, tail = NULL, p, q;

//���������
void printDongtai();

//��ʼ��
void InitDongtai() {
    cout<< "*******��ʼ��******" <<endl;
    cout << "���������ڴ��ܴ�С��";
    cin >> totalRAM;
    cout << "����������̸�����";
    cin >> processNum;
    cout << "����������� 1��" << processNum << " ����Ҫ���ڴ�ռ䣺";
    for (int i = 0; i < processNum; i++) {
        int tempRam = 0;
        cin >> tempRam;

        //��һ���ܲ��ܷ��µ� i ������
        if (i==0 && tempRam < totalRAM) {
            p = new RamNode;
            p->partNo = i;						//�ڵ�����
            p->processNo = to_string(i + 1);	//ռ�ý��к�
            p->start = 0;						//��ַ
            p->length = tempRam;				//����
            p->end = p->start + p->length - 1;	//��ַ
            p->status = 1;						//״̬
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
            //�Ų�����o(�i�n�i)o����������аɣ��Ȼ��д
        else {
            request[reqNum].reqProcessNo = to_string(i + 1);
            request[reqNum].reqLength = tempRam;
            reqNum++;
        }
    }
    //����������ڴ���ʣ�࣬���ʣ��ռ�Ҳ��һ������
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
    //βָ�룬�ȷ��ţ�Ӧ�����ã�(��o��)������û�õ�
    tail = p;
}

//��ʼ�����������ţ�ÿ�ε��ı�����ṹ��ʱ�򣬶�Ҫ����һ�Ρ�
void InitpartNo() {
    int i = 0;
    for (p = head; p != NULL; p=p->next) {
        p->partNo = i;
        i++;
    }
}

//������i����������Ĳ����p��ʵ���������
void insert(ramNode &p,int i) {
    p->processNo = request[i].reqProcessNo;
    p->status = 1;
    //������󳤶ȵ��ڿ��г��ȣ���ò�����
    if (request[i].reqLength == p->length) {}
        //���󣼿��У���Ҫ�ָ���o(�i�n�i)o
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
    //�޸�������������״̬Ϊ �ѷ���
    request[i].reqed = 1;
}

/*������Ӧ�㷨*/
void zuixianSuanfa(int &i) {
    for (i; i < reqNum; i++) {
        //�����з����׵�ַ����
        for (p = head; p != NULL; p = p->next) {
            //�����ǰ����������󳤶�С�������ҵ��Ŀ��з������ȣ�����з���
            if (request[i].reqLength <= p->length && p->status == 0) {
                insert(p, i);
                break;
            }
        }
        //��1��������̣�������������Ȼ�Ҳ����ڴ�ȥ��ֱ�ӷ��ء�
        if (i == 0 && p == NULL) {
            return;
        }
        else if (p == NULL) {
            return;
        }
    }
}

/*�����������Ϣ���Ѿ�����Ľ���ȡ��*/
void refeshReq(int i) {
    int temp = reqNum;
    reqNum = reqNum - i;
    for (int j = 0; j < temp; i++, j++) {
        request[j].reqProcessNo = request[i].reqProcessNo;
        request[j].reqLength = request[i].reqLength;
        request[j].reqed = request[i].reqed;
    }

}

/*������Ӧ�㷨*/
void zuixian() {
    cout<<"��ǰ�������Ϣ���£�"<<endl;
    cout<<"˳��\t������\t���󳤶�"<<endl;
    for (int i = 0; i < reqNum; i++) {
        cout << i+1 <<"\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
    }
    int i=0;
    zuixianSuanfa(i);
    //δ���κη��䣬ֱ�ӷ���
    if (i == 0) {
        cout << "�ò����¿ռ䲻�㣬δ���κη��䣡" << endl;
        return;
    }
        //ȫ���������
    else if (i == reqNum) {
        cout << "������еĽ���ȫ��������ϣ�" << endl;
    }
        //ֻ��ɲ��ַ���
    else {
        cout << "������еĽ��̲��ַ�����ϣ�ʣ��δ����������£�" << endl;
        cout << "\t������\t���󳤶�" << endl;
        for (int i = 0; i < reqNum; i++) {
            if (request[i].reqed == 0) {
                cout << "\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
            }
        }
    }
    cout << "������ڴ�ʹ��������£�" << endl;
    printDongtai();
    InitpartNo();
    //����������ݸ��£�ɾ����
    refeshReq(i);
    return;
}

/*����a��b��ֵ*/
void change(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*�ҳ����еĿ��з����������ڿ��з�������*/
void findFreePart() {
    InitpartNo();//��ʼ��һ��
    //��ʼ�����б�
    for (int i = 0; i <= freeNum; i++) {
        freePart[i].freePartNo = -1;
        freePart[i].freeStart = -1;
        freePart[i].freeLength = -1;
    }
    freeNum = 0;
    //�Ⱦ�����Щ���з���
    for (p = head; p != NULL; p = p->next) {
        //����״̬������������ñ�
        if (p->status == 0) {
            freePart[freeNum].freePartNo = p->partNo;
            freePart[freeNum].freeStart = p->start;
            freePart[freeNum].freeLength = p->length;
            freeNum++;
        }
    }
}

/*���ҳ����п������������򣺵���*/
void InitZuijia() {
    findFreePart();
    //�����з�����С��������
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

/*�ҳ���ǰi����������ܷŵ��µ����ţ�����������*/
int findInsertPartNo(int i) {
    //�ҵ���ǰi�ܷŵ��µ�����
    int partNo = -1;
    for (int j = 0; j < freeNum; j++) {
        if (request[i].reqLength <= freePart[j].freeLength) {
            partNo = freePart[j].freePartNo;
            //cout << "�ҵ����ţ�" << partNo << endl;
            return partNo;
        }
    }
    return -1;
}

/*���ʹ���㷨*/
void zuijia() {
    cout << "��ǰ�������Ϣ���£�" << endl;
    cout << "˳��\t������\t���󳤶�" << endl;
    for (int i = 0; i < reqNum; i++) {
        cout << i + 1 << "\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
    }

    InitZuijia();
    int i=0;
    for (i; i < reqNum; i++) {

        //�ҵ���ǰi�ܷŵ��µ�����
        int partNo = -1;
        partNo = findInsertPartNo(i);

        if (i==0 && partNo == -1) {
            cout << "�ò����¿ռ䲻�㣬δ���κη��䣡" << endl;
            return;
        }
        else if (partNo == -1) {
            cout << "�����䲿�ֽ��̣�ʣ��δ����������£�" << endl;
            cout << "\t������\t���󳤶�" << endl;
            for (int j = 0; j < reqNum; j++) {
                if (request[j].reqed == 0) {
                    cout << "\t" << request[j].reqProcessNo << "\t" << request[j].reqLength << endl;
                }
            }
            break;
        }

        //Ѱ�Ҳ���㲢����
        for (p = head; p != NULL; p = p->next) {
            if (p->partNo == partNo) {
                //cout << "�ҵ���Ӧ�Ĳ����" << endl;
                insert(p,i);
            }
        }
        //��ʼ���������б�
        InitZuijia();
    }
    if (i == reqNum)
        cout << "������еĽ���ȫ��������ϣ�" << endl;
    printDongtai();

    //����������ݸ��£�ɾ����
    refeshReq(i);
}

//���Ӧ�㷨

/*���ҳ����п�������װ�ݼ�����*/
void InitZuihuai() {
    findFreePart();
    //�����з�����С�ݼ�����
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

/*���Ӧ�㷨*/
void zuihuai() {
    cout << "��ǰ�������Ϣ���£�" << endl;
    cout << "˳��\t������\t���󳤶�" << endl;
    for (int i = 0; i < reqNum; i++) {
        cout << i + 1 << "\t" << request[i].reqProcessNo << "\t" << request[i].reqLength << endl;
    }

    InitZuihuai();
    int i = 0;
    for (i; i < reqNum; i++) {

        //�ҵ���ǰi�ܷŵ��µ�����
        int partNo = -1;
        partNo = findInsertPartNo(i);

        if (i == 0 && partNo == -1) {
            cout << "�ò����¿ռ䲻�㣬δ���κη��䣡" << endl;
            return;
        }
        else if (partNo == -1) {
            cout << "�����䲿�ֽ��̣�ʣ��δ����������£�" << endl;
            cout << "\t������\t���󳤶�" << endl;
            for (int j = 0; j < reqNum; j++) {
                if (request[j].reqed == 0) {
                    cout << "\t" << request[j].reqProcessNo << "\t" << request[j].reqLength << endl;
                }
            }
            break;
        }

        //Ѱ�Ҳ���㲢����
        for (p = head; p != NULL; p = p->next) {
            if (p->partNo == partNo) {
                insert(p, i);
            }
        }
        //��ʼ���������б�
        InitZuihuai();
    }
    if (i == reqNum)
        cout << "������еĽ���ȫ��������ϣ�" << endl;
    printDongtai();

    //����������ݸ��£�ɾ����
    refeshReq(i);
}

//����һ������
void feipeiFenqu() {
    if (reqNum == 0) {
        cout << "��ǰû��δ����ռ�Ľ��̣�" << endl << endl;
        return;
    }
    cout << "����1��������Ӧ�㷨" << endl;
    cout << "����2�������Ӧ�㷨" << endl;
    cout << "����3�����Ӧ�㷨" << endl;
    cout << "������ѡ�������ԣ�";
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
    cout << "����\t��ַ\t����\tβַ\t״̬\tռ�ý��̱��" << endl;
    int i = 0;
    for (p = head; p != NULL; p = p->next) {
        cout << " " << p->partNo << "\t" << p->start << "\t" << p->length << "\t" << p->end << "\t";
        if (p->status == 1)
            cout << "ռ��\t" << p->processNo << endl;
        else
            cout << "����" << endl;
        i++;
    }
    cout << endl;
}

//�ͷ�һ������
void shifangFenqu() {
    cout << "���������ͷ��ڴ�����ţ�";
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
        cout << freePart<<"�ŷ����ͷųɹ���" << endl;

        //�����ϲ�����Ƭ����
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
        }//��Ƭ�������

        InitpartNo();
    }
    else {
        cout << "��ǰ�������У������ͷţ�" << endl;
    }
    printDongtai();
    cout << endl;
}

//��ӽ��̵����������
void addProcess() {
    cout << "��������̱�ź����󳤶ȣ�";
    //������̱�Ų����ڣ������ִ��
    if (1) {
        cin >> request[reqNum].reqProcessNo >> request[reqNum].reqLength;
        reqNum++;
        cout<<"��ӳɹ���"<<endl;
    }
    cout << endl;
}

int main(){
    InitDongtai();
    while (1) {
        cout << "********��  ��********" << endl;
        cout << "��1����ʾ����״̬" << endl;
        cout << "��2���ͷŷ���" << endl;
        cout << "��3���������" << endl;
        cout << "��4����ӽ��̣���ҵ��" << endl;

        cout << "��������ѡ�";
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