#include <iostream>	
#include <queue>
using namespace std;

#define MaxNum 100
typedef int WeightType;
int TopOrder[MaxNum];
int N, M;

typedef struct GNode* PtrToGNode;
struct GNode
{
	PtrToAdjVNode FirstPtr;
}G[MaxNum];
typedef PtrToGNode LGraph;

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	int AdjV;
	PtrToAdjVNode Next;
	WeightType Weight;

};

void CreatGraph(int VertexNum)
{
	for (int i = 0; i < VertexNum; i++)
	{
		G[i].FirstPtr = NULL;
	}
}

void BuildGraph()
{
	int V1, V2;
	WeightType Weight;
	
	cin >> N >> M;
	CreatGraph(N);
	for (int i = 0; i < N; i++)
	{
		cin >> V1 >> V2 >> Weight;
		PtrToAdjVNode P;
		P = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
		P->Next = G[V1].FirstPtr;
		G[V1].FirstPtr = P;
		P->Weight = Weight;
		P->AdjV = V2;
	}
}

void TopSort()
{
	int Indegree[MaxNum], cnt = 0;
	int V;
	PtrToAdjVNode W;
	queue <int> Q;
	for (V = 0; V < N; V++)
	{
		Indegree[V] = 0;
	}
	for (V = 0; V < N; V++)
	{
		for (W = G[V].FirstPtr; W ; W = W->Next)
		{
			Indegree[W->AdjV]++;
		}
	}
	for (V = 0; V < N; V++)
	{
		if (Indegree[V] == 0)
		{
			Q.push(V);
		}
	}
	cnt = 0;
	while (!Q.empty())
	{
		V = Q.front();
		Q.pop();
		TopOrder[cnt++] = V;
		for (W = G[V].FirstPtr; W; W = W->Next)
		{
			if (--Indegree[W->AdjV] == 0)
			{
				Q.push(W->AdjV);
			}
		}
	}
	if (cnt != N)
	{
		cout << "Impossible" << endl;
		return;
	}
}

int main()
{


	system("pause");
	return 0;
}