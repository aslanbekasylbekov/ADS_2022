#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next;
};
    // Given a reference (pointer to pointer)
    // to the head of a list and an int,
    // inserts a new node on the front of
    // the list.
    void pushback(Node**head_ref,int new_data){
        // 1. allocate node
        Node* new_node = new Node(); 
        // 2. put in the data
        new_node->data = new_data; 
        // 3. Make next of new node as head
        new_node->next = NULL;
        // 4. If the Linked List is empty,
        // then make the new node as head
        if(*head_ref==NULL){
            *head_ref = new_node;
            return;
        }
        // 5. Else traverse till the last node
        Node*cur = *head_ref;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=new_node;
        return;
    }
    void answer(Node*node){
        int i = 1;
        while(node!=NULL){
            if(i%2!=0){
                cout<<node->data<<" ";  
            }
            node = node->next;
            i++;
        }  
    }
int main(){
    int n; cin>>n;
    Node * head = NULL;
    for(int i=0,val;i<n;i++){
        cin>>val;
        pushback(&head, val);
    }
    answer(head);
}