#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
    public:
        Node *next;
        int val;
        Node(int t){
            next=NULL;
            val=t;
        };
        virtual ~Node();

    protected:

    private:

};

#endif // NODE_H
