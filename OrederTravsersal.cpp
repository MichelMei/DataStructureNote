#include<iostream>
#include<stack>
using namespace std;
#define Maxsize 10;
typedef int ElementType;
typedef struct Binarytree* Bintree;
struct Binarytree
{
	ElementType Date;
	Bintree right;
	Bintree left;
};

typedef struct Node* PtrtoNode;
typedef PtrtoNode Position;
struct Node
{
	ElementType Data;
	PtrtoNode Next;
};

typedef struct QNode Queue;
struct QNode
{
	Position front, rear;//指向头和尾，头部可删除，尾部可增加
	int maxsize;
};


//递归调用的遍历模式
void PreOrderTravseral(Bintree BT)//前序遍历
{
	if (BT)
	{
		cout << BT->Date << endl;
		PreOrderTravseral(BT->left);
		PreOrderTravseral(BT->right);
	}
}
void InOrderTravseral(Bintree BT)
{
	if (BT)
	{
		PreOrderTravseral(BT->left);
		cout << BT->Date << endl;
		PreOrderTravseral(BT->right);
	}
}
void PostOrderTravseral(Bintree BT)
{
	if (BT)
	{
		PreOrderTravseral(BT->left);
		PreOrderTravseral(BT->right);
		cout << BT->Date << endl;
	}
}
//void LevalOrderTravseral(Bintree BT)
//{
//	Queue Q;
//	Bintree T;
//	if (!BT)
//	{
//		return;
//	}
//	Q = CreatQueue();
//	AddQueue(Q, BT);
//	while (!Isempty(Q))
//	{
//		T = DeleteQ(Q);
//		cout << T->Date << endl;
// //	if (T->left)
//	{
//		AddQueue(Q, T->left);
//	}
//		if (T->right)
//	{
//		AddQueue(Q, T->right);
//	}
//	}
//}

//遍历非递归算法
void PreorderTravseral(Bintree BT)
{
	Bintree T = BT;
	stack<Bintree> s;
	while (T || !s.empty())
	{
		while (T)
		{
			s.push(T);
			cout << T->Date << endl;
			T = T->left;
		}
		if (!s.empty())
		{
			T = s.top();
			s.pop();
			T = T->right;
		}
	}
}
void InorderTravseral(Bintree BT)
{
	Bintree T = BT;
	stack<Bintree> s;
	while (T || !s.empty())
	{
		while (T)
		{
			s.push(T);
			T = T->left;
		}
		if (!s.empty())
		{
			T = s.top();
			s.pop();
			cout << T->Date << endl;
			T = T->right;
		}
	}

}
void PostorderTravseral(Bintree BT)
{
	Bintree T = BT;
	stack<Bintree> S;
	stack<Bintree> Q;
	while (T || !S.empty())
	{
		while (T)
		{
			S.push(T);
			Q.push(T);
			T->right;
		}
		if (!S.empty())
		{
			T = S.top();
			S.pop();
			T = T->left;
		}
	}
	while (!Q.empty())
	{
		T = Q.top();
		cout << T-> Date << endl;
		Q.pop();
	}
}
int main()
{
	system("pause");
	return 0;
}