#include <iostream>
#include "LinkList.h"
#include "Node.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    LinkList *l=new LinkList();
    for(int i=5;i>0;i--){
        Node *n=new Node(i);
        l->addACS(n);
    }
    l->removeNode(3);
    l->display();
    l->~LinkList();
    return 0;
}
