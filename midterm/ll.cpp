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
    Node*head;
    Node*tail;
    int cnt;
    LList(){
        head=NULL;
        tail=NULL;
        cnt=0;
    }
    void insertFirst(int val){
        Node*newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    } 
    void insertLast(int val){
        Node*newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        } else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    int count(int x){
        Node*cur = head;
        while(cur!=NULL){
            if(cur->val == x){
                cnt++;
            }
            cur=cur->next;
        }
        return cnt;
    }
    int getNth(int n){
        Node*cur=head;
        int i=0;
        while(cur!=NULL){
            if(i == n){
                return cur->val;
            }
            i++;
            cur=cur->next;
        }
    }
};
int main(){
    LList ll;
    int n; cin>>n;
    string s;
    while(cin>>s){
        if(s=="insertFirst"){
            int t; cin>>t;
            ll.insertFirst(t);
        }
        if(s=="insertLast"){
            int t; cin>>t;
            ll.insertLast(t);
        }
        if(s=="cnt"){
            int t; cin>>t;
            cout<<ll.count(t)<<endl;
        }
        if(s=="getNth"){
            int t; cin>>t;
            cout<<ll.getNth(t)<<endl;
        }
    }
}