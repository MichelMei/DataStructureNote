#include <iostream>
using namespace std;

#define Maxsize 10000

int SetType[Maxsize];

int Find(int Arr[], int X)
{
	if (Arr[X] < 0)
	{
		return X;
	}
	else
	{
		return Arr[X] = Find(Arr, Arr[X]);//是否要减一？
	}
}

void Union(int Arr[], int Root1, int Root2)
{
	if (Arr[Root1] < Arr[Root2])
	{
		Arr[Root2] = Root1;
	}
	else if (Arr[Root1] > Arr[Root2])
	{
		Arr[Root1] = Root2;
	}
	else
	{
		if (Arr[Root1] == Arr[Root2])
		{
			Arr[Root2] = Root1;
			Arr[Root1]--;
		}
	}
}

void Input_Connection(int Arr[])
{
	int u, v;
	int Root1, Root2;
	cin >> u >> v;
	Root1 = Find(Arr, u - 1);//减一的结果？
	Root2 = Find(Arr, v - 1);
	if (Root1 != Root2)
	{
		Union(Arr, Root1, Root2);
	}
}
void Check_Connection(int Arr[])
{
	int u, v;
	int Root1, Root2;
	cin >> u >> v;
	Root1 = Find(Arr, u - 1);
	Root2 = Find(Arr, v - 1);
	if (Root1 == Root2)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
}
void Check_Network(int Arr[], int n)
{
	int i, counter = 0;
	for (i = 0; i < n; i++)
	{
		if (Arr[i] < 0)
		{
			counter++;
		}
	}
	if (counter == 1)
	{
		cout << "The network is connected." << endl;
	}
	else
	{
		cout << "There are " << counter << " components." << endl;
	}
}
int main()
{
	int N;
	char ch;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		SetType[i] = -1;
	}
	do
	{
		cin >> ch;
		switch (ch)
		{
		case 'I':
			Input_Connection(SetType);
			break;
		case 'C':
			Check_Connection(SetType);
			break;
		case 'S':
			Check_Network(SetType, N);
			break;
		}
	} while (ch != 'S');
	system("pause");
	return 0;
}