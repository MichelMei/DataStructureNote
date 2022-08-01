#include <iostream>
using namespace std;
#define MAXSIZE 10

#define NotFound 0

typedef int ElementType;


ElementType BinarySearch(ElementType L[], ElementType X, ElementType length)
{
    ElementType right, left, mid;
    left = 1;
    right = length;

    while (left <= right)
    {
        mid = (right + left) / 2;
        if (X < L[mid])
        {
            right = mid - 1;
        }
        else if (X > L[mid])
        {
            left = mid + 1;
        }
        else 
            return mid;
    }
    return NotFound;
}



int main()
{
    int Array[MAXSIZE];
    int i = 0, j = 0, X;
    cin >> i;
    for (int z = 1; z <= i; z++)
    {
        cin >> Array[z];//从下标为1开始存储
        j++;
    }
    cin >> X;
    int position = BinarySearch(Array, X, j);
    cout << position << endl;
    return 0;
}
