#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int index;
    Node*next;
    Node*prev;
    Node(int new_data){
        data = new_data;
        next = NULL;
    }
};
struct LList{
    Node*head;
    Node*tail;
    int size;
    LList(){
        head = NULL;
        tail=NULL;
        size = 0;
    }
    void pushback(int data){
        Node*newnode = new Node(data);
        if(head==NULL){
            head=newnode;
            tail = newnode;
        }else{
            Node*cur=head;
            while(cur!=NULL){
                if(cur->next == NULL){
                    cur->next=newnode;
                    break;
                }
                cur=cur->next;
            }
        }
        size++;
    }
    void insert(int i,int data){
        Node*newnode = new Node(data);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }else{
            if(i==0){
                newnode->next=head;
                head=newnode;
            } else{
                Node*cur=head;
                int cnt = 1;
                while(cnt!=i){
                    cur = cur->next;
                    cnt++;
                }
                
                Node*newnode=new Node(data);
                newnode->next=cur->next;
                cur->next = newnode;

            }
        }
        size++;
    }
    void print(){
        Node*cur=head;
        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
    }
};
int main(){
    LList l;
    int n; cin>>n;
    for(int i=0,num;i<n;i++){
        cin>>num;
        l.pushback(num);
    }
    int k,val; cin>>k>>val;
    l.insert(val,k);
    l.print();
}
