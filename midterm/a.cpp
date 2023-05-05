#include <iostream>
using namespace std;
int cnt;

int a[10000] = {0}; 
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

void triangle(Node*root){
    if(root!=NULL){
        Node*left = root->left;
        Node*right = root->right;
        cnt = 0;
        while(left!=NULL && right!=NULL){
            a[cnt++]++;
            left = left->left;
            right = right->right;
        }
        triangle(root->left);
        triangle(root->right);
    }
}
int main(){
    int n; cin>>n;
    Node*root=NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        root=insert(root,x);
    }
    triangle(root);
    for(int i=0; i<n-1; i++) cout << a[i] << " ";

}