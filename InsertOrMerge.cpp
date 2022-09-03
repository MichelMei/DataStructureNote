#include <iostream>
#include <algorithm>
using namespace std;

#define MaxN 100
int OrginalArr[MaxN], part_sort[MaxN];
int work[MaxN];
int N;

void Insertion(int k)
{
	int i;
	for (i = 0; i < N; i++)
	{
		work[i] = OrginalArr[i];
	}
	sort(work, work + k);
}
void Merge(int k)
{
	int i;
	for (i = 0; i < N; i++)
	{
		work[i] = OrginalArr[i];
	}
	sort(work, work + k);
	for (i = 0; i < N; i += k)
	{
		if (i + k <= N)
		{
			sort(work + i, work + i + k);
		}
		else
		{
			sort(work + i, work + N);
		}
	}
}

bool issame()
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (work[i] != part_sort[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int i, k;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> OrginalArr[i];
	}
	for (i = 0; i < N; i++)
	{
		cin >> part_sort[i];
	}
	for (k = N - 1; k > 0; k--)
	{
		Insertion(k);
		if (issame())
		{
			Insertion(k + 1);
			cout << "Insertion Sort\n";
			for (i = 0; i < N; i++)
			{
				if (i)
				{
					cout << " ";
				}
				cout << work[i];
			}
			return 0;
		}
	}
	for (k = 1; k < N; k *= 2)
	{
		Merge(k);
		if (issame())
		{
			Merge(k * 2);
			cout << "Merge Sort\n";
			for (i = 0; i < N; i++)
			{
				if (i)
				{
					cout << " ";
				}
				cout << work[i];
			}
			return 0;
		}
	}
}