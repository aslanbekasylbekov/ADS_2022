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
    if(root==NULL){
        root=new Node(val);
    }
    else if(root->val>val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
int cnt = 0;
int triangle(Node*root){
    if(root==NULL) return 0;
    if(root->left and root->right){
        cnt++;
    }
    triangle(root->left);
    triangle(root->right);
}
int main(){
    int n; cin>>n;
    Node*root=NULL;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        root = insert(root,num);
    } 
    triangle(root);
    cout<<cnt;  
}