#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int cnt;
    Node*next;
    Node*prev;
    Node(int new_data){
        data = new_data;
        next = NULL;
        prev = NULL;
        cnt = 0;
    }
};
struct LList{
    int size;
    int max;
    Node*head;
    Node*tail;
    LList(){
        size = 0;
        max = 0;
        head = NULL;
        tail = NULL;
    }
    void pushback(int data){
        Node*newnode = new Node(data);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }else{
            Node*cur=head;
            while(cur!=NULL){
                if(cur->data==newnode->data){
                    cur->cnt++;
                }
                if(cur->next==NULL){
                    cur->next=newnode;   
                    break;
                }
                cur=cur->next;
            }
        }
        size++;
    }
    void found(){
        Node*cur=head;
        while(cur!=NULL){
            if(cur->cnt>max){
                max=cur->cnt;
            }
            cur=cur->next;
        }
    }
    void print(){
        vector<int>foo;
        Node*cur=head;
        while(cur!=NULL){
            if(cur->cnt==max){
                foo.push_back(cur->data);
            }
            cur=cur->next;
        }
        sort(foo.rbegin(),foo.rend());
        for(int i=0;i<foo.size();i++){
            cout<<foo[i]<<" ";
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
    l.found();
    l.print();
    return 0;
}