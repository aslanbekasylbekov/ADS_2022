#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left,*right;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
Node*insert(int val,Node*root){
    if(root==NULL)  root=new Node(val);
    else if(root->val>val)  root->left = insert(val,root->left);
    else root->right = insert(val,root->right);
    return root;
}
Node*find(int k,Node*root){
    if(root==NULL or root->val==k) return root;
    else if(root->val>k) return find(k,root->left);
    else return find(k,root->right);
}
int getSize(Node*root){
    if(root==NULL) return 0;
    else return 1+getSize(root->left)+getSize(root->right);
}
int main(){
    int n,x; cin>>n;
    Node*root=NULL;
    Node*temp=NULL;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        root = insert(num,root);
    }
    cin>>x;
    cout<<getSize(find(x,root));
}