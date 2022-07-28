#include <iostream>
using namespace std;

int a[101], n;
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
	{
		return;
	}
	temp = a[left];//基准位
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];//基准位与ij相遇的位置调换
	a[i] = temp;//产生了新的基准位

	quicksort(left, i - 1);//当上一个基准位到达正确位置后，利用递归思想处理正确位置左边的数组
	quicksort(i + 1, right);//处理右边的数组
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	quicksort(1, n);
	for (i = 1; i < n; i++)
	{
		cout << a[i];
	}
	system("pause");
	return 0;
}
//核心思路
//交换右边碰到比基准位小的数与左边比基准位大的数
//平均复杂度为NlogN，最复杂的情况下为N^2