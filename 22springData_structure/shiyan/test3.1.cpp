//
// Created by Skylar_xty on 2022-10-15.
//

#include <iostream>
#include <vector>
#define INFINITY INT_MAX      //最大值
#define MAX_VERTEX_NUM 100    //最大顶点个数
#define VexType char
#define InfoType int
#define VertexType int
//vex:储存顶点
//arc:储存边
using namespace std;
typedef enum{DG,DN,UDG,UDN} GraphKind;

typedef struct{
    VexType Vex[MAX_VERTEX_NUM];
    int Arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = {0};
    int vexnum, arcnum;
    GraphKind kind;
}MGraph;
//链表的结点，整个链表的头结点存储在VNode中
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    int weight;
}ArcNode;
//VNode是顶点的结构体
//包含边链表的头结点，以及自己的数据元素data
typedef struct VNode{
    VexType data;
    ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
//整个图ALGraph
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
    GraphKind kind;
}ALGraph;
//给出顶点类型的数据 v，返回其在邻接矩阵中对应下标。
int LocateVex(MGraph G, VexType v){
    for(int i=0; i<G.vexnum; i++){
        if(G.Vex[i]==v) return i;
    }
    return -1;
}
//给出顶点 v，返回与其邻接（相邻）的第一个顶点。
int FirstAdjVex(MGraph G, int v){
    for(int j=0; j<G.vexnum; j++){
        if(G.Arc[v][j]!=0) return j;
    }
    return -1;
}
//给出顶点v，返回与其邻接的、在w之后的顶点
int NextAdjVex(MGraph G, int v, int w){
    for(int j=w+1; j<G.vexnum; j++){
        if(G.Arc[v][j]!=0) return j;
    }
    return -1;
}
//插入一个顶点v
//插入顶点不针对边，没有边的图也是一张图，后续通过对边的操作，使顶点连起来即可。
void InsertVex(MGraph &G, VexType v){
    G.Vex[G.vexnum++] = v;
}
//在顶点 v 和顶点 w 之间，插入一条边；如果是有向边，就是从 v 到 w。
//info 在该函数中的作用为边的权值，如果不需要权值，那么权值默认为 1，代表有边即可。
//无向图/网需要在 (v, w) 和 (w, v) 都插入一条边；
//有向图/网只需插入 <v, w> 一条边即可。
bool InsertArc(MGraph &G, VexType v, VexType w, int info=1){
    int i = LocateVex(G, v);
    int j = LocateVex(G, w);
    if(G.kind==UDG || G.kind==UDN){
        G.Arc[i][j] = info;
        G.Arc[j][i] = info;
    }
    else if(G.kind==DG || G.kind==DN){
        G.Arc[i][j] = info;
    }
}
//FirstPrior 函数的意义为，找到连着 w 的第一个顶点，有点像是找前驱；
//NextPrior 函数的意义为，找到连着 w 的、相对于 v 之后的顶点。
//这两个函数是逆拓扑排序用的，如果不需要逆拓扑可以不用管。
vector<int> visited(MAX_VERTEX_NUM);
void DFS(MGraph G, int v)
{
    visited[v]=1;
    cout<<G.Vex[v];
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.Arc[v][i]!=0&&!visited[i])
            DFS(G,i);
    }
}
void Creategraph(MGraph &G) {
    int i, j, k;
    float w;
    cin >> G.vexnum >> G.arcnum >> G.kind;
    for (i = 1; i <= G.vexnum; i++)
        G.Vex[i] = getchar(); //ABCDEF...
    for (i = 1; i <= G.vexnum; i++) {
        for (j = 1; j <= G.vexnum; j++) {
            //G.arcs[i][j].adj=INFINITY;
            //G.arcs[i][j].info=NULL;
            G.Arc[i][j] = 0;
        }
    }
    for (k = 1; k <= G.arcnum; k++) {
        cin >> i >> j >> w;
        G.Arc[i][j] = w;
    }
}
int main()
{
    MGraph G;


    return 0;
}
/*
void DFSTraverse(MGraph G, int v0=0){
    for(int v=0; v<G.vexnum; v++) visited[v] = false;
    DFS(G, v0);
    for(int v=0; v<G.vexnum; v++){
        if(!visited[v]) DFS(G, v);
    }
}

void DFS(MGraph G, int v){
    visit(G, v);
    visited[v] = true;
    for(int w=FirstAdjVex(G, v); w>=0; w=NextAdjVex(G, v, w)){
        if(!visited[w]){
            DFS(G, w);
        }
    }
}*/
