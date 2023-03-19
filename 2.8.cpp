
#include <iostream>

using namespace std;

struct node
{
    int info;
    struct node *pNext;
    struct node *pPrev;
};
typedef struct node NODE;

typedef NODE *TREE;

int main()
{
    cout<<"Hello World";

    return 0;
}
