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
Node*insert(Node*root,int val){
    if(root==NULL) root=new Node(val);
    else if(root->val>val) root->left=insert(root->left,val);
    else root->right = insert(root->right,val);
    return root;
}
Node*find(Node*root,int k){
    if(root==NULL || root->val==k) return root;
    else if(root->val>k) return find(root->left,k);
    else return find(root->right,k);
}
void preorder(Node*root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int n; cin>>n;
    Node*root=NULL;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        root = insert(root,num);
    }
    int x; cin>>x;
    preorder(find(root,x));
}