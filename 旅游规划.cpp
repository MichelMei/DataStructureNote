#include <iostream>
using namespace std;

#define MaxNum 500
#define INFINITE 65535
int S, D;//分别为起点终点
int Dist[MaxNum], Cost[MaxNum];
int Collected[MaxNum];
int C[MaxNum][MaxNum];
typedef struct GNode* PtrToGNode;
struct GNode
{
	int Nv, Ne;
	int G[MaxNum][MaxNum];
};
typedef PtrToGNode MGraph;

MGraph CreatGraph(int VertexNum)
{
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (int i = 0; i < Graph->Nv; i++)
	{
		for (int j = 0; j < Graph->Nv; j++)
		{
			Graph->G[i][j] = INFINITE;
			C[i][j] = INFINITE;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph)
{
	int E1, E2;
	int Len, Co;
	cin >> E1 >> E2 >> Len >> Co;
	Graph->G[E1][E2] = Len;
	Graph->G[E2][E1] = Len;
	C[E1][E2] = Co;
	C[E2][E1] = Co;
}

MGraph BuildGraph()
{
	MGraph Graph;
	int N;
	cin >> N;
	Graph = CreatGraph(N);
	cin >> Graph->Ne;
	cin >> S >> D;


	for (int i = 0; i < Graph->Ne; i++)
	{
		InsertEdge(Graph);
	}
	return Graph;
}

int FindMinDist(MGraph Graph)
{
	int MinV, V;
	int MinDist = INFINITE;
	for (V = 0; V < Graph->Nv; V++)
	{
		if (Collected[V] == 0 && Dist[V] < MinDist)
		{
			MinDist = Dist[V];
			MinV = V;
		}
	}
	if (MinDist < INFINITE)
	{
		return MinV;
	}
	return -1;
}
void Dijkstra(MGraph Graph)
{
	int V, W;
	for ( V = 0; V < Graph->Nv; V++)
	{
		Dist[V] = Graph->G[S][V];
		Cost[V] = C[S][V];
		Collected[V] = 0;
	}
	Dist[S] = 0;
	Collected[S] = 1;
	while (1)
	{
		V = FindMinDist(Graph);
		Collected[V] = 1;
		if (V == -1)
		{
			break;
		}
		for (W = 0; W < Graph->Nv; W++)
		{
			if (Collected[W] == 0 && Graph->G[V][W] < INFINITE)
			{
				if (Dist[V] + Graph->G[V][W] < Dist[W])
				{
					Dist[W] = Dist[V] + Graph->G[V][W];
					Cost[W] = Cost[V] + C[V][W];
				}
				else if ((Dist[V] + Graph->G[V][W] == Dist[W]) && (Cost[V] + C[V][W] < Cost[W]))
				{
					Cost[W] = Cost[V] + C[V][W];
				}
			}
		}
	}
	cout << Dist[D] << " " << Cost[D];
}



int main()
{
	MGraph Graph = BuildGraph();
	Dijkstra(Graph);
	system("pause");
	return 0;
}