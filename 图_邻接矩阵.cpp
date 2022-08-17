#include <iostream>
using namespace std;

#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex;

typedef struct ENode* PtrToENode;
typedef PtrToENode Edge;
struct ENode
{
	Vertex V1, V2;
};

typedef struct GNode* PtrToGNode;
typedef PtrToGNode MGraph;
struct GNode
{
	int Nv;
	int Ne;
	int G[MaxVertexNum][MaxVertexNum];
};

MGraph CreatGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
	{
		for  (W = 0; W < Graph->Nv; W++)
		{
			Graph->G[V][W] = INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = 1;
	Graph->G[E->V2][E->V1] = 1;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	cin >> Nv;
	Graph = CreatGraph(Nv);
	cin >> Graph->Ne;
	if (Graph->Ne != 0)
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for ( i = 0; i < Graph->Ne; i++)
		{
			cin >> E->V1 >> E->V2;
			InsertEdge(Graph, E);
		}
	}
}

int main()
{

	system("pause");
	return 0;
}