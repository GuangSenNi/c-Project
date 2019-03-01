#include "LinkList.h"

LinkList::LinkList()
{
    Node *n=new Node(0);
    head=n;
    tail=n;
    length=0;
}

LinkList::~LinkList()
{
    Node *p=head;
    while(p!=NULL){
        Node *t=p;
        p=p->next;
        delete t;
    }
}

void LinkList::addNode(Node *n){
    tail->next=n;
    tail=n;
    length++;
}

void LinkList::addACS(Node *n){
    Node *last=head;
    Node *p=head->next;
    while(p!=NULL){
        if(n->val<p->val){
            last->next=n;
            n->next=p;
            length++;
            return;
        }
        last=p;
        p=p->next;
    }
    last->next=n;
    length++;
}

Node LinkList::removeNode(int val){
    Node *last=head;
    Node *p=head->next;
    while(p!=NULL){
        if(p->val==val){
            last->next=p->next;
            length--;
            return *p;
        }
        last=p;
        p=p->next;
    }
    length=0;
    return *p;
}

void LinkList::display(){
    Node *p=head->next;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
