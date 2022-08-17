#include <iostream>
#include <map>
#include <string>
using namespace std;

#define HeapCapacity 64
#define MinData 0 
typedef struct TreeNode* HuffmanTree;
typedef struct Heap* MinHeap;

struct Heap
{
	HuffmanTree* Data;
	int size;
};

struct TreeNode
{
	int weight;
	HuffmanTree Left;
	HuffmanTree Right;
};

MinHeap Creat_Heap();
HuffmanTree Creat_HuffmanTree();
void Sort_Heap(MinHeap H, int i);
void Adjust_Heap(MinHeap H);
MinHeap InitHeap(int N);
HuffmanTree Delete_Heap(MinHeap H);
void Insert(MinHeap Heap, HuffmanTree Huff);
HuffmanTree Huffman(MinHeap H);
int WPL(HuffmanTree Huff, int Depth);

map<char, int>mappp;

MinHeap Creat_Heap()
{
	MinHeap H;
	H = (MinHeap)malloc(sizeof(struct Heap));
	H->Data = (HuffmanTree*)malloc(sizeof(struct TreeNode) * HeapCapacity);
	H->size = 0;

	//设置哨兵
	HuffmanTree Huff = Creat_HuffmanTree();
	H->Data[0] = Huff;
	return H;
}

HuffmanTree Creat_HuffmanTree()
{
	HuffmanTree Huff;
	Huff = (HuffmanTree)malloc(sizeof(struct TreeNode));
	Huff->weight = MinData;
	Huff->Left = NULL;
	Huff->Right = NULL;
	return Huff;
}

void Sort_Heap(MinHeap H, int i)
{
	int parent, child;
	HuffmanTree Huff = H->Data[i];
	for (parent = i; parent * 2 <=  H->size; parent = child)
	{
		child = parent * 2;
		if ((child != H->size) && (H->Data[child + 1]->weight < H->Data[child]->weight))
		{
			child++;
		}
		if (Huff->weight <= H->Data[child]->weight)
		{
			break;
		}
		H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = Huff;
}
void Adjust_Heap(MinHeap H)
{
	for (int i = H->size / 2; i > 0 ; i--)
	{
		Sort_Heap(H, i);
	}
}

MinHeap InitHeap(int N)
{
	MinHeap H = Creat_Heap();
	HuffmanTree Huff;
	char c;
	int f;
	for (int i = 0; i < N; i++)//map头文件
	{
		getchar();
		cin >> c >> f;
		mappp.insert(pair<char, int>(c, f));
		Huff = Creat_HuffmanTree();
		Huff->weight = f;
		H->Data[++H->size] = Huff;
	}
	Adjust_Heap(H);
	return H;
}

HuffmanTree Delete_Heap(MinHeap H)
{
	int parent, child;
	HuffmanTree T = H->Data[1];
	HuffmanTree Huff = H->Data[H->size--];
	for (parent = 1; parent * 2 <= H->size; parent = child)
	{
		child = parent * 2;
		if (child != H->size && H->Data[child + 1]->weight < H->Data[child]->weight)
		{
			child++;
		}
		if (Huff->weight <= H->Data[child]->weight)
		{
			break;
		}
		H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = Huff;
	return T;
}

void Insert(MinHeap H, HuffmanTree Huff)
{
	int i = ++H->size;
	for ( ; Huff->weight < H->Data[i / 2]->weight; i /= 2)
	{
		H->Data[i] = H->Data[i / 2];
	}
	H->Data[i] = Huff;
}

HuffmanTree Huffman(MinHeap H)
{
	HuffmanTree Huff;
	int times = H->size;
	for (int i = 1; i < times; i++)
	{
		Huff = Creat_HuffmanTree();
		Huff->Left = Delete_Heap(H);
		Huff->Right = Delete_Heap(H);
		Huff->weight = Huff->Left->weight + Huff->Right->weight;
		Insert(H, Huff);
	}
	Huff = Delete_Heap(H);
	return Huff;
}

int WPL(HuffmanTree Huff, int Depth)
{
	if (Huff->Left == NULL && Huff->Right == NULL)
	{
		return Depth * Huff->weight;
	}
	else
	{
		return (WPL(Huff->Left, Depth + 1) + WPL(Huff->Right, Depth + 1));
	}
}

void submit(int n, int codelen)
{
	HuffmanTree Huff = Creat_HuffmanTree();
	HuffmanTree Pre;
	int counter = 1;
	bool flag = true;
	char ch;
	string code;
	for (int i = 0; i < n; i++)
	{
		getchar();
		Pre = Huff;
		cin >> ch;
		cin >> code;
		for (int j = 0; j < code.size(); j++)
		{
			if (code[j] == '0')
			{
				if (Pre->Left == NULL)
				{
					Pre->Left = Creat_HuffmanTree();
					counter++;
				}
				if (Pre->weight != 0)
				{
					flag = false;
				}
				Pre = Pre->Left;
			}
			else if (code[j] == '1')
			{
				if (Pre->Right == NULL)
				{
					Pre->Right = Creat_HuffmanTree();
					counter++;
				}
				if (Pre->weight != 0)
				{
					flag = false;
				}
				Pre = Pre->Right;
			}
		}
		if (Pre->Left || Pre->Right)
		{
			flag = false;
		}
		Pre->weight = mappp[ch];
	}
	if (counter != 2 * n - 1 || !flag || WPL(Huff, 0) != codelen)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
}

int main()
{
	int N;// 共N个字符需要01替换
	int M;// 共M个学生
	cin >> N;
	MinHeap H = InitHeap(N);
	HuffmanTree Huff = Huffman(H);
	int codelen = WPL(Huff, 0);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		submit(N, codelen);
	}
	system("pause");
	return 0;
} 