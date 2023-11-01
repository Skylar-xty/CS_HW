//
// Created by Skylar_xty on 2022-10-15.
//

#include <iostream>
#include <vector>
#define INFINITY INT_MAX      //最大值
#define MAX_VERTEX_NUM 100    //最大顶点个数
#define VRType int
#define InfoType int
#define VertexType int

using namespace std;
typedef enum{DG,DN,UDG,UDN} GraphKind;
//UDG，无向图，UnDirectedGraph，最普通最普通的图；
//DG，有向图，DirectedGraph，边是有向边；
//UDN，无向网，UnDirectedNet，即边有权值的无向图；
//DN，有向网，DirectedNet，即弧有权值的有向图；
//邻接矩阵
//typedef struct ArcCell    //弧的定义
//{
//    VRType adj;       //VRType是顶点关系类型
//    InfoType *info;   //该弧相关信息的指针
//}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
class Graph{
public:
//图的类型实现
    typedef struct{
        VertexType vexs[MAX_VERTEX_NUM];  //顶点信息
        //AdjMatrix arcs;                   //弧的信息
        int Arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
        int vexnum,arcnum;                //顶点数，弧数
        GraphKind kind;                   //图的种类标志
    }MGraph;
    void Creategraph(MGraph &G)
    {
        int i,j,k;float w;
        cin>>G.vexnum>>G.arcnum>> G.kind;
        for(i=1;i<=G.vexnum;i++)
            G.vexs[i] =getchar(); //ABCDEF...
        for(i=1;i<=G.vexnum;i++)
        {
            for(j=1;j<=G.vexnum;j++)
            {
                //G.arcs[i][j].adj=INFINITY;
                //G.arcs[i][j].info=NULL;
                G.A
            }
        }
        for(k=1;k<=G.arcnum;k++)
        {
            cin>>i>>j>>w;
            G.arcs[i][j].adj=w;
        }
    }
    int FirstAdjVex(MGraph G, int v){
        for(int j=0; j<G.vexnum; j++){
            if(G.arcs[v][j]!=0) return j;
        }
        return -1;
    }
};
vector<int> visited(MAX_VERTEX_NUM);

void DFS(Graph G,int v){
    //from 顶点v,dfs G
    visited[v]=1;

}
int main()
{

    return 0;
}