#include <iostream>
using namespace std;
struct Node{
    pair<char,bool> val;
    Node *next = NULL,*prev = NULL;
    Node(){
        val.first = '_';
        val.second = false;
    }
    Node(pair<char,bool> _val,Node * _next,Node *_prev){
        val = _val;
        next = _next;
        prev = _prev;
    }
};
struct LList{
    Node *head, *tail;
    LList(){
        head = new Node(make_pair('_',false),NULL,NULL);
        tail = new Node(make_pair('_',false),NULL,NULL);
    }
    void push_back(char data){
        if(head->val.first == '_'){
            head->val.first = data;
            tail = head;
        }else{
            Node *new_node = new Node(make_pair(data,false),NULL,NULL);
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node; 
        }
    }
    void check(){
        Node *cur = tail->prev,*temp = head;
        for(;cur != NULL;){
            if(cur->val.first == tail->val.first){
                tail->val.second = true;
                cur->val.second = true;
            }
            cur = cur->prev;
        }
        for(;temp != NULL;){
            if(temp->val.second == false){
                cout << temp->val.first << " ";
                return;
            }
            temp = temp->next;
        }
        cout << -1 <<" ";
    }  
    void clear(){
        head = new Node(make_pair('_',false),NULL,NULL);
        tail = new Node(make_pair('_',false),NULL,NULL);     
    } 
};
int main(){
    LList list;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        for(int j=0;j<x;j++){
            char l; 
            cin >> l;
            list.push_back(l);
            list.check();
        }
        list.clear();
        cout << endl;
    }
}