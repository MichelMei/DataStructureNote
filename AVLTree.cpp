#include <iostream>
using namespace std;

typedef struct AVLNode* Position;
typedef Position AVLTree;

struct AVLNode
{
	int Data;
	int Height;
	AVLTree Left;
	AVLTree Right;
};

int Max(int a, int b)
{
	return a > b ? a : b;
}
int GetHeight(AVLTree A)
{
	if (!A)
	{
		return -1;
	}
	else
	{
		return Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	}
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;
	return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T, int X)
{
	if (!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Height = 0;
		T->Data = X;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Data)
	{
		T->Left = Insert(T->Left, X);
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
		{
			if (X < T->Left->Data)
			{
				T = SingleLeftRotation(T);
			}
			else
			{
				T = DoubleLeftRightRotation(T);
			}
		}

	}
	else if (X > T->Data)
	{
		T->Right = Insert(T->Right, X);
		if (GetHeight(T->Left) - GetHeight(T->Right) == -2)
		{
			if (X > T->Right->Data)
			{
				T = SingleRightRotation(T);
			}
			else
			{
				T = DoubleRightLeftRotation(T);
			}
		}
	}
	//X 与 T相等,无需插入
	return T;
}



int main()
{
	int N = 0, X = 0;
	AVLTree T = NULL;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		T = Insert(T, X);
	}
	cout << T->Data << endl;


	system("pause");
	return 0;
}