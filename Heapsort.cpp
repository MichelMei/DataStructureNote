#include <iostream>
using namespace std;

//建立堆的时间复杂度为O（N）
//堆排序的时间复杂度为O（NlogN）

int h[100];
int n;//堆的大小
void swap(int x, int y)
{
	int temp;
	temp = h[x];
	h[x] = h[y];
	h[y] = temp;
}

void siftdownmin(int i)
{
	int t, flag = 0;
	while (i * 2 <= n && flag == 0)//非叶节点的两倍小于总节点数
	{
		if (h[i] > h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		if (i * 2 + 1 <= n)//跟右子树比较
		{
			if (h[t] > h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}
		if (t != i)
		{
			swap(t, i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}
void siftdownmax(int i)
{
	int t, flag = 0;
	while (i * 2 <= n && flag == 0)//非叶节点的两倍小于总节点数
	{
		if (h[i] < h[i * 2])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		if (i * 2 + 1 <= n)//跟右子树比较
		{
			if (h[t] < h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}
		if (t != i)
		{
			swap(t, i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}
void creatminheap()//建立最小堆
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		siftdownmin(i);
	}
}
void creatmaxheap()//建立最大堆
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		siftdownmax(i);
	}
}
void heapsort()//将最大堆转化为最小堆
{
	while (n > 1)
	{
		swap(1, n);
		n--;
		siftdownmax(1);
	}
}
int deletemax()
{
	int t;
	t = h[1];
	h[1] = h[n];//将堆中最大的数放到最高处来
	n--;
	siftdownmin(1);//对堆的顺序重新进行调整
	return t;//返回堆的第一个值，输出最小的数
}
int main()
{
	int i, num;
	cin >> num;
	for (i = 1; i <= num; i++)
	{
		cin >> h[i];
	}
	n = num;
	creatminheap();//将上面的数组建立成堆
	for (i = 1; i <= num; i++)
	{
		cout << deletemax() << endl;//从小到大进行输出，到时候输出堆直接输出数组即可
	}

	system("pause");
	return 0;
}