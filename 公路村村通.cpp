#include <iostream>
using namespace std;

#define MaxNum 1000
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;

typedef struct GMNode* PtrToGMNode;
struct GMNode
{
	Vertex G[MaxNum][MaxNum];
	int Nv;
	int Ne;
};
typedef PtrToGMNode MGraph;



MGraph CreatMGraph(int VertexNum)
{
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GMNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (int i = 0; i < VertexNum; i++)
	{
		for (int j = 0; j < VertexNum; j++)
		{
			Graph->G[i][j] = INFINITY;
		}
	}
	return Graph;
}

MGraph BuildMGraph()
{
	int N, E;
	Vertex V1, V2;
	WeightType Weight;
	cin >> N >> E;
	MGraph Graph = CreatMGraph(N);
	Graph->Ne = E;
	for (int i = 0; i < E; i++)
	{
		cin >> V1 >> V2 >> Weight;
		Graph->G[V1 - 1][V2 - 1] = Weight;
		Graph->G[V2 - 1][V1 - 1] = Weight;
	}
	return Graph;
}

Vertex FindMinDist(MGraph Graph, WeightType Dist[])
{
	Vertex V, MinV;
	WeightType MinDist = INFINITY;
	for (V = 0; V < Graph->Nv; V++)
	{
		if (Dist[V] != 0 && Dist[V] < MinDist)
		{
			MinDist = Dist[V];
			MinV = V;
		}
	}
	if (MinDist < INFINITY)
	{
		return MinV;
	}
	else
	{
		return -1;
	}
}

int Prime(MGraph Graph)
{
	WeightType Dist[MaxNum];
	WeightType TotalWeight;
	int Vcount;
	Vertex Parent[MaxNum], V, W;
	for (V = 0; V < Graph->Nv; V++)
	{
		Dist[V] = Graph->G[0][V];
		Parent[V] = 0;
	}
	TotalWeight = 0;
	Vcount = 0;
	Dist[0] = 0;
	Vcount++;
	Parent[0] = -1;
	while (1)
	{
		V = FindMinDist(Graph, Dist);
		if (V == -1)
		{
			break;
		}
		TotalWeight += Dist[V];
		Dist[V] = 0;
		Vcount++;
		for (W = 0; W < Graph->Nv; W++)
		{
			if (Dist[W] != 0 && Graph->G[V][W] < INFINITY)
			{
				if (Graph->G[V][W] < Dist[W])
				{
					Dist[W] = Graph->G[V][W];
					Parent[W] = V;
				}
			}
		}
	}
	if (Vcount < Graph->Nv)
	{
		TotalWeight = -1;
	}
	return TotalWeight;
}


void check(MGraph Graph)
{
	int i, j;
	for ( i = 0; i < Graph->Nv; i++)
	{
		for ( j = 0; j < Graph->Nv; j++)
		{
			cout << Graph->G[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	MGraph Graph = BuildMGraph();
	WeightType Cost;
	Cost = Prime(Graph);
	cout << Cost << endl;
	//check(Graph);
}

