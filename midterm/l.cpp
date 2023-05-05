#include <iostream>
using namespace std;
int cnt=0;
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
    else root->right=insert(root->right,val);
    return root;
}
int find(Node*root){
    if(root==NULL) return 1;
    else{
        if(root->left==NULL && root->right==NULL){
            cnt++;
        }
    }
    find(root->left);
    find(root->right);
    return cnt;
}
int main(){
    int n; cin>>n;
    Node*root=NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        root=insert(root,x);
    }
    cout<<find(root);
}