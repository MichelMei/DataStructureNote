#include <iostream>
using namespace std;

#define Tree int
#define Maxtree 10
#define ElementType char
#define NULL -1

struct TreeNode
{
	ElementType Element;
	Tree left;
	Tree right;
}T1[Maxtree], T2[Maxtree];
Tree BuildTree(struct TreeNode T[])
{
	int N, i;
	int check[Maxtree];//设立一个数组用于检查根节点
	ElementType cl, cr;
	Tree Root;

	cin >> N;
	if (N)
	{
		for (i = 0; i < N; i++)
		{
			check[i] = 0;
		}
		for (i = 0; i < N; i++)
		{
			cin >> T[i].Element >> cl >> cr;
			if (cl != '-')
			{
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else
			{
				T[i].left = NULL;
			}
			if (cr != '-')
			{
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else
			{
				T[i].right = NULL;
			}
		}
	}
	else
	{
		return NULL;
	}
	for ( i = 0; i < N; i++)
	{
		if (check[i] != 1)
		{
			break;
		}
	}
	Root = i;
	return Root;
};

int Ismorphic(int R1, int R2)
{
	if (R1 == NULL && R2 == NULL )//两个空树
	{
		return 1;
	}
	if ((R1 == NULL && R2 != NULL) || (R1 != NULL && R2 == NULL))//一个空树
	{
		return 0;
	}
	if (T1[R1].Element != T2[R2].Element)//根节点不一样
	{
		return 0;
	}
	if (T1[R1].left == NULL && T2[R2].left == NULL)//都是左边空，检测右边
	{
		return Ismorphic(T1[R1].right, T2[R2].right);
	}

	if (T1[R1].left != NULL && T2[R2].left != NULL && T1[T1[R1].left].Element == T2[T2[R2].left].Element)//目前不需要进行左右对比
	{
		return(Ismorphic(T1[R1].right, T2[R2].right) & Ismorphic(T1[R1].left, T2[R2].left));
	}
	else 
	{
		return(Ismorphic(T1[R1].right, T2[R2].left) & Ismorphic(T1[R1].left, T2[R2].right));
	}
}

int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Ismorphic(R1, R2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}


	system("pause");
	return 0;
}