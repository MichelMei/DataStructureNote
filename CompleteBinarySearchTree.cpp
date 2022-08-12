#include <iostream>
#include <algorithm>
using namespace std;

#define Maxsize 1010
typedef int ElementType;

int N, t = 0;
ElementType Arr[Maxsize];
ElementType Arr1[Maxsize];


void Inorder(ElementType Root)
{
	if (Root >= N)
	{
		return;
	}
	Inorder(Root * 2 + 1);
	Arr1[Root] = Arr[t++];
	Inorder(Root * 2 + 2);
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}
	sort(Arr, Arr + N);
	Inorder(0);
	cout << Arr1[0];
	for (int i = 1; i < N; i++)
	{
		cout << " " << Arr1[i];
	}
	system("pause");
	return 0;
}