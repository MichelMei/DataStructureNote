#include <iostream>
#include <iomanip>
using namespace std;

#define Maxsize 100001

 typedef struct Node
{
	int NextAddress;
	int Data;
}Node;

Node List[Maxsize];

int Reverse(int FirstAddress, int K)
{
	int Head = FirstAddress;
	int Rear = FirstAddress;
	int NextHead = 0;
	int k = K;

	while (Rear != -1 && k != 1)
	{
		Rear = List[Rear].NextAddress;
		k--;
	}
	k = K;
	if (Rear != -1)
	{
		NextHead = Rear;
	}
	while (Rear != -1)
	{
		int P = Head;
		while (Head != Rear)
		{
			Head = List[P].NextAddress;
			List[P].NextAddress = List[Rear].NextAddress;
			List[Rear].NextAddress = P;
			P = Head;
		}
		while (k != 1)
		{
			P = List[P].NextAddress;
			k--;
		}
		Rear = List[P].NextAddress;
		Head = List[P].NextAddress;

		k = K;

		while (Rear != -1 && k != 1)
		{
			Rear = List[Rear].NextAddress;
			k--;
		}
		k = K;
		if (Rear != -1)
		{
			List[P].NextAddress = Rear;
		}		
	}
	return NextHead;
}


int main()
{
	int N, K, FA, P;
	cin >> FA >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> P;
		cin >> List[P].Data >> List[P].NextAddress;
	}
	int NList;
	NList = Reverse(FA, K);
	P = NList;
	while (List[P].NextAddress != -1)
	{
		cout << setw(5) << setfill('0') << P << " " << List[P].Data << " " << setw(5) << setfill('0') << List[P].NextAddress << endl;
		P = List[P].NextAddress;
	}
	cout << setw(5) << setfill('0') << P << " " << List[P].Data << " " << List[P].NextAddress << endl;
	system("pause");
	return 0;
}