#include <iostream>
using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode
{
	int v, flag;
	Tree Right, Left;
};


Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}
Tree Insert(Tree T, int V)
{
	if (!T)
	{
		T = NewNode(V);
	}
	else
	{
		if (V > T->v)
		{
			T->Right = Insert(T->Right, V);
		}
		else
		{
			T->Left = Insert(T->Left, V);
		}
	}
	return T;
}
Tree MakeTree(int N)
{
	Tree T;
	int i, V;
	cin >> V;
	T = NewNode(V);
	for ( i = 1; i < N; i++)
	{
		cin >> V;
		T = Insert(T, V);
	}
	return T;
}
int check(Tree T, int V)
{
	if (T->flag)
	{
		if (V < T->v)
		{
			return check(T->Left, V);
		}
		else if (V > T->v)
		{
			return check(T->Right, V);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (V == T->v)
		{
			T->flag = 1;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int Judge(Tree T, int N)
{
	int i, V, flag = 0;//当flag等于1时代表不一致
	cin >> V;
	if (V != T->v)
	{
		flag = 1;
	}
	else
	{
		T->flag = 1;
	}
	for (i = 1; i < N; i++)
	{
		cin >> V;
		if ((!flag) && !check(T, V))
		{
			flag = 1;
		}
	}
	if (flag)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void ResetT(Tree T)
{
	if (T->Left)
	{
		ResetT(T->Left);
	}
	if (T->Right)
	{
		ResetT(T->Right);
	}
	T->flag = 0;
}
void FreeT(Tree T)
{
	if (T->Left)
	{
		FreeT(T->Left);
	}
	if (T->Right)
	{
		FreeT(T->Right);
	}
	free(T);
}

int main()
{
	int N, L, i;
	Tree T;
	cin >> N;
	while (N)
	{
		cin >> L;
		T = MakeTree(N);
		for ( i = 0; i < L; i++)
		{
			if (Judge(T, N))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			ResetT(T);
		}
		FreeT(T);
		cin >> N;
	}

	system("pause");
	return 0;
}