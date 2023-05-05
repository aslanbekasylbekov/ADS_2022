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

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node* new_node = new Node(s);
    Node* last = head;
    new_node -> next = NULL;
    if(head == NULL)
    {
        new_node -> prev = NULL;
        head = new_node;
        return;
    }
    while(last -> next != NULL)
    {
        last = last -> next;
    }
    last -> next = new_node;
    new_node -> prev = last;
    tail = new_node;
    return;


}
void add_front(string s){
    Node* new_node = new Node(s);
    new_node -> next = head;
    new_node -> prev = NULL;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    if(head  != NULL)
    {
        head  -> prev = new_node;
    }
    head  = new_node;
    return;
}
bool empty(){
    if(head == NULL)
    return true;
    else
    return false;
}
void erase_front(){
  Node* temp =head;
  temp =head -> next;
  head -> next =NULL;
  head = temp;



    return;
}
void erase_back(){
  if(head == tail)
  {
    head = NULL;
    tail = NULL;
    return;
  }
  Node* last = head;
  while(last -> next != NULL)
  {
    last = last -> next;
  }
  tail = NULL;
  Node* prev_last = last -> prev;
  last -> prev = NULL;
  prev_last -> next =NULL;
  tail = prev_last;
  return;

}
string front(){
    return head -> val;
}
string back(){
    return tail-> val;
}
void clear(){
head = NULL;
tail = NULL;
}
  
int main()
{
  string s;
     while(cin >> s){
       if(s == "add_front"){
         string t;
         cin >> t;
         add_front(t);
         cout << "ok" << endl;
       }
       if(s == "add_back"){
         string t;
         cin >> t;
         add_back(t);
         cout << "ok" << endl;
       }
       if(s == "erase_front"){
         if(empty()){
           cout << "error" << endl;
         }
         else
         {
           cout << front() << endl;
           erase_front();
         }
       }
       if(s == "erase_back"){
         if(empty()){
           cout << "error" << endl;
         }
         else{
           cout << back() << endl;
           erase_back();
         }
       }
       if(s == "front"){
         if(empty()){
           cout << "error" << endl;
         }
         else{
           cout << front() << endl;
         }
       }
       if(s == "back"){
         if(empty()){
           cout << "error" << endl;
         }
         else{
           cout << back() << endl;
         }
       }
       if(s == "clear"){
         clear();
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