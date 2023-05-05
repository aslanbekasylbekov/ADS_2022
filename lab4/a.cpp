#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left,*right;
    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
Node*insert(int val,Node*root){
    if(root==NULL){
        root=new Node(val);
    } 
    else if(root->val>val){
        root->left = insert(val,root->left);
    } 
    else {
        root->right = insert(val,root->right);
    }
    return root;
}
bool find(Node*root,string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
            if(root->right==NULL){
                return false;
                break;
            }
            root=root->right;
        } else{
            if(root->left==NULL){
                return false;
                break;
            }
            root=root->left;
        }
    }
    return true;
}
int main(){
    int n; cin>>n;
    int k; cin>>k;
    Node*root =NULL;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        root = insert(num,root);
    }
    for(int i=0;i<k;i++){
        string st; cin>>st;
        if(find(root,st)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}