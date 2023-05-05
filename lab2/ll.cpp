#include <iostream>
using namespace std;

struct Node{
    int val; 
    Node*next,*prev;
    Node(int val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};

struct LList{
    Node*head,*tail;
    int size;
    LList(){
        head=NULL;
        prev=NULL;
        size=0;
    }
    void pushBack(int val){
        Node*newnode = new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            Node*cur=head;
            while(cur->next!=NULL){
                cur=cur->next;
            }
            cur->next=newnode;
            newnode->prev=cur;
            tail=newnode;
        }
        size++;
    }
    void pushFront(int val){
        Node*newnode = new Node(val);
        if(head==NULL){
            head = newnode;
            tail=newnode;
        }
        else{
            newnode->nexhead;
            head=newnode;
        }
    }
    void erase_back(){
        if(head==tail){
            head=NULL;
            tail=NULL;
        }
        Node*cur=head;
        while()
    }
};