#include <iostream>
#include <stack>
using namespace std;

//根据输入进行填装，如果填装大于栈的容量则失败
//设置最大容量

void Judeg(int Capacity, int N, int M)
{
	int Data;
	int cmp = 0;

	stack <int> S;
	for (int i = 0; i < N; i++)
	{
		int Maxnum = 0;
		int flag = 1;
		for (int j = 1; j <= M; j++)
		{
			cin >> Data;
			if (Data > Maxnum)
			{
				for (int k = Maxnum + 1; k <= Data; k++)
				{
					S.push(k);
				}
				cmp = S.top();
				if (Data != cmp)
				{
					flag = 0;
				}
				if (S.size() > Capacity)
				{
					flag = 0;
				}
				S.pop();
				Maxnum = Data;
			}
			if (Data < Maxnum)
			{
				if (!S.empty())
				{
					cmp = S.top();
					S.pop();
				}
				if (Data != cmp)
				{
					flag = 0;
				}
			}
		}
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		while (!S.empty())
		{
			S.pop();
		}
	}
}

int main()
{
	int Capacity;//堆栈的容量
	int N;//需要检测N个序列
	int M;//一共输入M个数字
	cin >> Capacity >> M >> N;
	Judeg(Capacity, N, M);
	system("pause");
	return 0;
}