#ifndef LINKLIST_H
#define LINKLIST_H
#include "Node.h"
#include <iostream>
using namespace std;
class LinkList
{
    public:
        LinkList();
        void addNode(Node *n);
        void display();
        void addACS(Node *n);
        void addDECS(Node *n);
        Node removeNode(int val);
        virtual ~LinkList();

    private:
        Node *head;
        Node *tail;
        int length;
};

#endif // LINKLIST_H
