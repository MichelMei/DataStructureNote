#include <iostream>
using namespace std;

#define MaxN 101
#define INFINITY 65535

int checkpoints, activities;
int G[MaxN][MaxN], totaltime = 0;

struct Point
{
	int Earlytime, Lasttime;
	int Indegree, Outdegree;
}Points[MaxN];

void Init()
{
	for (int i = 1; i <= checkpoints; i++)
	{
		for (int j = j; j <= checkpoints; j++)
		{
			G[i][j] = 0;
		}
		Points[i].Earlytime = Points[i].Indegree = Points[i].Outdegree = 0;
		Points[i].Lasttime = INFINITY;
	}
}

void InsertActivities()
{
	int i, time, point1, point2;
	for (i = 1; i <= activities; i++)
	{
		cin >> point1 >> point2 >> time;
		G[point1][point2] = time;
		Points[point1].Outdegree++;
		Points[point2].Indegree++;
	}
}

int EarlytimeCheck()
{
	int i, Queue[MaxN], top = 0, rear = 0, maxtime = 0, point;
	for (i = 1; i <= checkpoints; i++)
	{
		if (!Points[i].Indegree)
		{
			Points[i].Indegree--;
			Queue[++top] = i;
		}
	}
	while (top != rear)
	{
		point = Queue[++rear];
		for ( i = 1; i <= checkpoints; i++)
		{
			if (G[point][i])
			{
				Points[i].Indegree--;
				if (!Points[i].Indegree)
				{
					Queue[++top] = i;
				}
				if (Points[i].Earlytime < Points[point].Earlytime + G[point][i])
				{
					Points[i].Earlytime = Points[point].Earlytime + G[point][i];
					if (Points[i].Earlytime > maxtime)
					{
						maxtime = Points[i].Earlytime;
					}
				}
			}
		}
	}
	if (top != checkpoints)
	{
		return 0;
	}
	else
	{
		return maxtime;
	}
}

int LasttimeCheck()
{
	int i, Queue[MaxN], top = 0, rear = 0, maxtime = 0, point;
	for (i = 1; i <= checkpoints; i++)
	{
		if (!Points[i].Outdegree)
		{
			Points[i].Outdegree--;
			Queue[++top] = i;
			Points[i].Lasttime = totaltime;
		}
	}
	while (top != rear)
	{
		point = Queue[++rear];
		for (i = 1; i <= checkpoints; i++)
		{
			if (G[i][point])
			{
				Points[i].Outdegree--;
				if (!Points[i].Outdegree)
				{
					Queue[++top] = i;
				}
				if (Points[point].Lasttime - G[i][point] < Points[i].Lasttime)
				{
					Points[i].Lasttime = Points[point].Lasttime - G[i][point];
				}
			}
		}
	}
	for (i = 1; i <= checkpoints; i++)
	{
		if (Points[i].Lasttime == Points[i].Earlytime)
		{
			for (int j = checkpoints; j >= 1; j--)
			{
				if (G[i][j] && Points[j].Lasttime == Points[j].Earlytime && Points[i].Lasttime == Points[j].Lasttime - G[i][j])
				{
					cout << i << "->" << j << endl;
				}
			}
		}
	}
}

int main()
{
	cin >> checkpoints >> activities;
	Init();
	InsertActivities();
	totaltime = EarlytimeCheck();
	if (totaltime == 0)
	{
		cout << "0";
	}
	else
	{
		cout << totaltime << endl;
		LasttimeCheck();
	}
	return 0;
}