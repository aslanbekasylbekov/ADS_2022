#include <bits/stdc++.h>
  
using namespace std;

struct Node{
  Node * prev;
  Node * next;
  string val;
  Node(string _val){
    prev = NULL;
    next = NULL;
    val = _val;
  }  
};
struct LList{
  Node * head;
  Node * tail;
  int cnt;
  LList(){
    head=NULL;
    tail=NULL; 
    cnt=0;
  }
  void add_back(string s){
  Node*newNode = new Node(s);
  if(head==NULL){
    head=newNode;
    tail=newNode;
  }
  else{
    Node*cur=head;
    while(cur->next!=NULL){
      cur=cur->next;
    }
    cur->next=newNode;
    newNode->prev=cur;
    tail=newNode;
  }
  }
  void add_front(string s){
    Node* newNode = new Node(s);
    if(head==NULL){
      head=newNode;
      tail=newNode;
    }
    else{
      newNode->next=head;
      head=newNode;
    }
  
  }
  bool empty(){
    if(head==NULL) return true;
    else return false;
  }
  void erase_front(){
      Node*temp=head;
      temp=head->next;
      head->next=NULL;
      head=temp;
  }
  void erase_back(){
    if(head == tail){
      head = NULL;
      tail = NULL;
    }
    Node* cur = head;
    while(cur -> next != NULL){
      cur = cur -> next;
    }
    tail = NULL;
    Node* prev_last = cur -> prev;
    cur -> prev = NULL;
    prev_last -> next =NULL;
    tail = prev_last;
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
     while(cin >> s){
       if(s == "add_front"){
         string t;
         cin >> t;
         ll.add_front(t);
         cout << "ok" << endl;
       }
       if(s == "add_back"){
         string t;
         cin >> t;
         ll.add_back(t);
         cout << "ok" << endl;
       }
       if(s == "erase_front"){
         if(ll.empty()){
           cout << "error" << endl;
         }
         else
         {
           cout << ll.front() << endl;
           ll.erase_front();
         }
       }
       if(s == "erase_back"){
         if(ll.empty()){
           cout << "error" << endl;
         }
         else{
           cout << ll.back() << endl;
           ll.erase_back();
         }
       }
       if(s == "front"){
         if(ll.empty()){
           cout << "error" << endl;
         }
         else{
           cout << ll.front() << endl;
         }
       }
       if(s == "back"){
         if(ll.empty()){
           cout << "error" << endl;
         }
         else{
           cout << ll.back() << endl;
         }
       }
       if(s == "clear"){
         ll.clear();
         cout << "ok" << endl;
       }
       if(s == "exit"){
         cout << "goodbye" << endl;
         break;
       }
       // cout << "hi" << endl;
     }
    return 0;
}