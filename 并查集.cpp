#include <iostream>
using namespace std;
//要符合几条基本规则：输入的每一组元素，右边的元素归顺于左边的元素；组里的元素若找到新的根节点，让原本的根节点归顺新的根节点，若找到了原来的根节点，则这一条路压缩路径
int f[20] = {0}, n, m, sum = 0;
void intt()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}
}

int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}

	else
	{
		f[v] = getf(f[v]);//此处为路径压缩
		return f[v];//运用了递归的思想
	}
}

void merge(int v, int u)
{
	int t1, t2;//t1，t2可以理解成根节点
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)
	{
		f[t2] = t1;
	}
}

int main()
{
	int i, x, y;
	//x,y可以理解成两个相关的元素
	//n为独立集
	//m为一共有多少条相关的信息
	cin >> n >> m;
	intt();
	for (i = 1; i <= m; i++)
	{
		cin >> x >> y;
		merge(x, y);
	}
	for (i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			sum++;
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}
