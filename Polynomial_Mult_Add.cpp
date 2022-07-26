#include<iostream>
using namespace std;

typedef struct PolyNode* Polynomial;
struct PolyNode
{
	int coef;//系数
	int expon;//指数
	Polynomial Link;//链表节点
};

void Attach(int c, int e, Polynomial* pRear);
void PrintPoly(Polynomial P);

Polynomial ReadPoly()//读入多项式
{
	Polynomial P, t, Rear;
	int c, e, N;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->Link = NULL;//此处申请一个空结点，使Rear等于空结点
	Rear = P;
	cout << "请输入项数" << endl;
	cin >> N;
	cout << "请输入系数和指数" << endl;
	while (N--)
	{
		cin >> c >> e;
		Attach(c, e, &Rear);
	}
	t = P;//这里是删除空结点
	P = P->Link;
	free(t);
	return P;
}
void Attach(int c, int e, Polynomial* pRear)//最后一个是指向指针的指针, 因为传递的形参
{                                          
	Polynomial P;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->coef = c;
	P->expon = e;
	P->Link = NULL;
	(*pRear)->Link = P;//此处*代表解引用，即代表Rear指针。使得P插入在原本的Rear后面
	*pRear = P;//让尾部结点更改为新的P
}
Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P, t1, t2, Rear, t;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->Link = NULL;
	Rear = P;
	t1 = P1;
	t2 = P2;
	while (t1 && t2)
	{
		if (t1->expon == t2->expon)
		{
			if (t1->coef + t2->coef)
			{
				Attach(t1->coef + t2->coef, t1->expon, &Rear);
				t1 = t1->Link;
				t2 = t2->Link;
			}
			else
			{
				//此处采取了直跳过的方式
				t1 = t1->Link;
				t2 = t2->Link;
			}
		}
		else if (t1->expon > t2->expon)
		{
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->Link;
		}
		else
		{
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->Link;
		}
	}
	while (t1)
	{
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->Link;
	}
	while (t2)
	{
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->Link;
	}
	t = P;
	P = P->Link;
	free(t);
	return P;
}
Polynomial Mult1(Polynomial P1, Polynomial P2)//逐项插入法
{
	Polynomial t1, t2, t, Rear, P;
	int c, e;
	if (!P1 || !P2)
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(PolyNode));
	P->Link = NULL;
	Rear = P;
	while (t2)
	{
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->Link;//先用t1的第一项乘以t2的每一项
	}
	t1 = t1->Link;
	while (t1)
	{
		t2 = P2;
		Rear = P;
		while (t2)
		{
			c = t1->coef * t2->coef;
			e = t1->expon + t2->expon;
			while (Rear->Link && Rear->Link->expon > e)
			{
				Rear = Rear->Link;
			}
			if (Rear->Link && Rear->Link->expon == e)
			{
				if (Rear->Link->coef + c)
				{
					Rear->Link->coef += c;
				}
				else
				{
					t = Rear->Link;
					Rear->Link = t->Link;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(PolyNode));
				t->coef = c;
				t->expon = e;
				t->Link = Rear->Link;
				Rear->Link = t;
				Rear = Rear->Link;
			}
			t2 = t2->Link;
		}
		t1 = t1->Link;
	}
	t2 = P;
	P = P->Link;
	free(t2);
	return P;
}
Polynomial Mult2(Polynomial P1, Polynomial P2)
{
	Polynomial t1, t2, t, Rear, PS, P;
	int flag = 0;
	if (!P1 || !P2)
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	PS = (Polynomial)malloc(sizeof(PolyNode));

	while (t1)
	{
		P = (Polynomial)malloc(sizeof(PolyNode));
		P->Link = NULL;
		Rear = P;
		t2 = P2;
		while (t2)
		{
			if (t1->expon + t2->expon)//指数相加不为0时执行，但是相加为0的时候还未做处理
			{
				Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
			}
			t2 = t2->Link;
		}
		t1 = t1->Link;
		t = P;
		P = P->Link;
		free(t);
		if (!flag)
		{
			PS = P;
			flag = 1;
		}
		else
		{
			PS = Add(PS, P);
		}
	}
	return PS;
}
void PrintPoly(Polynomial P)
{
	int flag = 0;//调整格式
	if (!P)
	{
		cout << "多项式为空" << endl;
	}
	while (P)
	{
		if (!flag)
			flag = 1;
		else
			cout << "  " ;
		cout << P->coef << " " << P->expon;
		P = P->Link;
	}
	cout << endl;
}
int main()
{
	Polynomial P1, P2, PP1, PP2, SP;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP1 = Mult1(P1, P2);
	PP2 = Mult2(P1, P2);
	SP = Add(P1, P2);
	PrintPoly(PP1);
	PrintPoly(PP2);
	system("pause");
	return 0;
}
//遗留的问题：当指数相乘等于0时，并未处理
//遗留的问题：加法函数，当一项为空时，无法正常执行