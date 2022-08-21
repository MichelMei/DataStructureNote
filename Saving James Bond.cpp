#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
#define MaxVertex 105
const double Diameter = 15;

struct Node
{
	int x;
	int y;
	bool Visted;
	bool Safe;
	bool Jump;
};

int N;//öùÓãÊıÄ¿
double D;//ÌøÔ¾¾àÀë
bool IsSafe;//ÄÜ·ñÉÏ°¶
Node G[MaxVertex];

double getLen(double x1, double x2, double y1, double y2)
{
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}
bool ashore(int x, int y)
{
	if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y - 50) <= D || abs(y + 50) <= D)
	{
		return true;
	}
	return false;
}
void getSafe()
{
	for (int i = 0; i < N; i++)
	{
		if (ashore(G[i].x, G[i].y))
		{
			G[i].Safe = true;
		}
		else
		{
			G[i].Safe = false;
		}
	}
}

void getFirstJump()
{
	for (int i = 0; i < N; i++)
	{
		if (getLen(G[i].x,0, G[i].y,0) <= Diameter / 2 + D)
		{
			G[i].Jump = true;
		}
		else
		{
			G[i].Jump = false;
		}
	}
}

void Init()
{
	cin >> N >> D;
	double x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		G[i].x = x;
		G[i].y = y;
		G[i].Visted = false;
	}
	getSafe();
	getFirstJump();
	IsSafe = false;
}

void DFS(int V)
{
	if (G[V].Safe)
	{
		IsSafe = true;
		return;
	}
	G[V].Visted = true;
	for (int i = 0; i < N; i++)
	{
		if (getLen(G[V].x, G[i].x, G[V].y, G[i].y) <= D && !G[i].Visted)
		{
			DFS(i);
		}
	}
}

void Listcompoment()
{
	for (int i = 0; i < N; i++)
	{
		if (G[i].Jump)
		{
			DFS(i);
		}
	}
	if (IsSafe)
	{
		cout << "Yse" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

}
int main()
{
	Init();
	Listcompoment();


	system("pause");
	return 0;
}