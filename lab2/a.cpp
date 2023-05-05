#include <iostream>
using namespace std;
class Node{
    public:
    int data; 
    Node*next;
};
int main(){
    int n,k; cin>>n;
    int inx = n;
    int ans;
    Node*head=NULL;
    Node*cur=head;
    for(int i=0,digit;i<n;i++){
        cin>>digit;
        Node*new_node = new Node();
        new_node->data=digit;
        new_node->next=cur;
        cur = new_node;
    }
    cin>>k;   
    int differ = 99999;
    while(cur!=NULL){
        inx--;
        if(abs(cur->data - k)<= differ){
            differ = abs(cur->data - k);
            ans = inx; 
        }
        cur = cur->next;
    }
    cout<<ans;
}