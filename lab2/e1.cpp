#include <bits/stdc++.h>
using namespace std;
struct Node{
    string data;
    Node*next;
    Node*prev;
    Node(string new_data){
        data = new_data;
        next = NULL;
        prev = NULL;
    }
};
struct LList{
    int cnt;
    Node*head;
    Node*tail;
    LList(){
        cnt = 0;
        head = NULL;
        tail = NULL;
    }
    void pushback(string data){
        Node*newnode = new Node(data);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        cnt++;
    }
    void print(){
        Node*cur = tail;
        while(cur!=NULL){
            cout<<cur->data<<endl;
            cur=cur->prev;
        }
    }
    string getTail(){
        return tail->data;
    }
    bool empty(){
        return head==NULL and tail==NULL;
    }
    int size(){
        return cnt;
    }
};
int main(){
    LList l;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(s==""){
            continue;
        }
        if(l.empty()){
            l.pushback(s);
        }else{
            if(s!=l.getTail()){
                l.pushback(s);
            }
        }
    }
    cout<<"All in all: "<<l.size()<<endl;
    cout<<"Students:"<<endl;
    l.print();
}