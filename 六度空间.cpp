#include <iostream>
#include <queue>
#include <iomanip>
#include <string.h>
using namespace std;

//通过输入N个节点，M条边（M的格式是两个节点编号）
//来判断每一个节点通过六条边可连通的节点数，占总变数的百分之多少，输出格式要有小数点后两位
//核心：先建立邻接表，再利用BFS算法
//需要实现的功能：建表（结构体数组） 插入边 DFS返回一个counter计数器 输出

#define MaxNum 1050

int N = 0, M = 0;
int Visted[MaxNum];

typedef struct AdjVNode* PtrToAdjVNode;
struct GNode
{
	PtrToAdjVNode FirstNode;
}G[MaxNum];

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
	PtrToAdjVNode Next;
	int AdjV;//邻接点下标
};

void BuildG()
{
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
	{
		G[i].FirstNode = NULL;
	}
}
void Insert()
{
	int V1, V2;
	for (int i = 0; i < M; i++)
	{
		cin >> V1 >> V2;//输入边一和边二
		PtrToAdjVNode NewNode;
		NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
		NewNode->Next = G[V1].FirstNode;
		G[V1].FirstNode = NewNode;
		NewNode->AdjV = V2;
		//无向图
		NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
		NewNode->Next = G[V2].FirstNode;
		G[V2].FirstNode = NewNode;
		NewNode->AdjV = V1;
	}
}

double BFS(int i)
{
	int counter = 1;
	int V = i;
	int level = 0;
	int last = i;
	int tail = 0;
	Visted[i] = 1;
	PtrToAdjVNode VNode;
	queue<int>Q;
	Q.push(i);
	while (!Q.empty())
	{
		V = Q.front();
		Q.pop();
		VNode = G[V].FirstNode;
		while (VNode != NULL)
		{
			if (Visted[VNode->AdjV] != 1)
			{
				Visted[VNode->AdjV] = 1;
				Q.push(VNode->AdjV);
				counter++;
				tail = VNode->AdjV;
			}
			VNode = VNode->Next;
		}
		if (last == V)
		{
			level++;
			last = tail;
		}
		if (level == 6)
		{
			break;
		}
	}
	return counter;
}


int main()
{
	double counter = 0;
	BuildG();
	Insert();
	memset(Visted, 0, N);
	for (int i = 1; i <= N; i++)//此处循环调用DFS算法
	{
		for (int i = 1; i <= N; i++)
		{
			Visted[i] = 0;
		}
		counter = BFS(i);
		cout << i << ": " << setiosflags(ios::fixed) << setprecision(2) << counter / N * 100 << "%" << endl;
	}
	system("pause");
	return 0;
}