#include <iostream>
using namespace std;
struct Node{
    string val;
    Node*next,*prev;
    Node(string val){
        this->val=val;
        next = NULL;
        prev = NULL;
    }
};
struct LList{
    Node*head,*tail;
    int cnt;
    LList(){
        head = NULL;
        tail = NULL;
        cnt = 0;
    }
    void add_front(string val){
        Node* NewNode = new Node(val);
        if(head == NULL){
            head = tail = NewNode;
        }
        else{
            head -> prev = NewNode;
            NewNode -> next = head;
            head = NewNode;
        }
        cnt++;
    }
    void add_back(string val){
        Node* NewNode = new Node(val);
        if(head == NULL){
            head = tail = NewNode;
        }
        else{
            tail -> next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
        }
        cnt++;
    }
    bool empty(){
        if(head==NULL) return true;
        else return false;
    }
    void erase_front(){
        if(head->next == NULL){
            head=NULL;
            tail=NULL;
        }
        else{
            head->next->prev=NULL;
            head=head->next;
        }
    }
    void erase_back(){
        if(tail->prev==NULL){
            head=NULL;
            tail=NULL;
        }
        else{
            tail->prev->next=NULL;
            tail=tail->prev;
        }
    }
    string front(){
        return head->val;
    }
    string back(){
        return tail->val;
    }
    
    void clear(){
        head=NULL;
        tail=NULL;
    }
};
int main(){
    LList ll;
    string s;
    while(cin>>s){
        if(s=="add_front"){
            string t; cin>>t;
            ll.add_front(t);
            cout<<"ok\n";
        }
        if(s=="add_back"){
            string t; cin>>t;
            ll.add_back(t);
            cout<<"ok\n";
        }
        if(s=="erase_front"){
            if(ll.empty()){
                cout<<"error\n";
            } else{
                cout<<ll.front()<<endl;
                ll.erase_front();
            }
        }
        if(s=="erase_back"){
            if(ll.empty()){
                cout<<"error\n";
            } else{
                cout<<ll.back()<<endl;
                ll.erase_back();
            }
        }
        if(s=="front"){
            if(ll.empty()){
                cout<<"error\n";
            } else{
                cout<<ll.front()<<endl;
        }
        if(s=="back"){
            if(ll.empty()){
                cout<<"error\n";
            } else{
                cout<<ll.back()<<endl;
            }
        }
        if(s=="clear"){
            ll.clear();
            cout<<"ok"<<endl;
        }
    }
} 
}