#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode { /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};

int main()
{


	system("pause");
	return 0;
}
