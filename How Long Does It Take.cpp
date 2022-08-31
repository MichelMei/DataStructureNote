#include <iostream>
#include <queue>
using namespace std;

#define MaxSize 101
#define INFINITY 1000

int N, M, etime[MaxSize];
int G[MaxSize][MaxSize];
int Indegree[MaxSize];
queue<int>Q;

void CreatGraph()
{
	int i, j, k;
	cin >> N >> M;
	for ( i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = INFINITY;
			}
		}
	}
	for ( k = 0; k < M; k++)
	{
		cin >> i >> j;
		cin >> G[i][j];
	}
}

bool TopSort()
{
	int i, j, v, w;
	int count = 0;
	for ( i = 0; i < N; i++)
	{
		Indegree[i] = etime[i] = 0;
		for (j = 0; j < N; j++)
		{
			if (i != j && G[j][i] < INFINITY)
			{
				Indegree[i]++;
			}
		}
		if (Indegree[i] == 0)
		{
			Q.push(i);
		}
	}
	while (!Q.empty())
	{
		v = Q.front();
		Q.pop();
		count++;
		for (i = 0; i < N; i++)
		{
			if (v != i && G[v][i] != INFINITY)
			{
				Indegree[i]--;
				if (Indegree[i] == 0)
				{
					Q.push(i);
				}
				if (etime[v] + G[v][i] > etime[i])
				{
					etime[i] = etime[v] + G[v][i];
				}
			}
		}
	}
	if (count != N)
	{
		return false;
	}
	return true;
}

int MaxEtime()
{
	int i, MaxEtime = etime[N - 1];
	for ( i = 0; i < N; i++)
	{
		if (etime[i] > MaxEtime)
		{
			MaxEtime = etime[i];
		}
	}
	return MaxEtime;
}
int main()
{
	CreatGraph();
	if (!TopSort())
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << MaxEtime() << endl;
	}
	return 0;
}