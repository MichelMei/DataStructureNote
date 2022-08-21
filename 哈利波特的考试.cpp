#include <iostream>
using namespace std;

#define MaxVertex 100
#define INFINITE 65535

typedef int Vertex;
typedef int WeightType;

typedef struct GNode* PtrToGNode;
struct GNode
{
	int Nv, Ne;
	WeightType G[MaxVertex][MaxVertex];
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
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph)
{
	int E1, E2;
	WeightType Weight;
	cin >> E1 >> E2 >> Weight;
	Graph->G[E1 - 1][E2 - 1] = Weight;
	Graph->G[E2 - 1][E1 - 1] = Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	int Nv, i;
	cin >> Nv;
	Graph = CreatGraph(Nv);
	cin >> Graph->Ne;
	for ( i = 0; i < Graph->Ne; i++)
	{
		InsertEdge(Graph);
	}
	return Graph;
}

void Floyd(MGraph Graph, WeightType D[][MaxVertex])
{
	Vertex i, j, k;
	for ( i = 0; i < Graph->Nv; i++)
	{
		for ( j = 0; j < Graph->Nv; j++)
		{
			D[i][j] = Graph->G[i][j];
		}
	}
	for ( k = 0; k < Graph->Nv; k++)
	{
		for (i = 0; i < Graph->Nv; i++)
		{
			for (j = 0; j < Graph->Nv; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

WeightType FindMaxDist(WeightType D[][MaxVertex], int N, Vertex i)
{
	WeightType MaxDist;
	Vertex j;
	MaxDist = 0;
	for ( j = 0; j < N; j++)
	{
		if (D[i][j] > MaxDist && i != j)
		{
			MaxDist = D[i][j];
		}
	}
	return MaxDist;
}

void FindAnimal(MGraph Graph)
{
	WeightType D[MaxVertex][MaxVertex], MaxDist, MinDist;
	Vertex Animal , i;
	Floyd(Graph, D);
	MinDist = INFINITE;
	//for (i = 0; i < Graph->Nv; i++)
	//{
	//	for (int j = 0; j < Graph->Nv; j++)
	//	{
	//		cout << D[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for ( i = 0; i < Graph->Nv; i++)
	{
		MaxDist = FindMaxDist(D, Graph->Nv, i);
		if (MaxDist == INFINITE)
		{
			cout << 0;
			return;
		}
		if (MinDist > MaxDist)
		{
			MinDist = MaxDist;
			Animal = i + 1;
		}
	}
	cout << Animal << " " << MinDist << endl;

}

int main()
{
	MGraph G = BuildGraph();
	FindAnimal(G);
	return 0;
}