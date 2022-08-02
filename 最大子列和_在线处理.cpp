#include <iostream>
using namespace std;

int Maxsum(int Arr[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for ( i = 0; i < N; i++)
	{
		ThisSum += Arr[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;
		}
	}
	return MaxSum;
}

int main()
{
	int N = 0;
	int Arr[100000];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}
	cout << Maxsum(Arr, N) << endl;


	system("pause");
	return 0;
}