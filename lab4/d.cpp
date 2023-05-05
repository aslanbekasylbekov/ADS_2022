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
    if(root==NULL) root = new Node(val);
    else if(root->val>val) root->left=insert(root->left,val);
    else root->right = insert(root->right,val);
    return root;
}
int getHeight(Node*root){
    if(root==NULL) return 0;
    else return 1 + max(getHeight(root->left),getHeight(root->right));
}
void calcSum(Node*root,int level,int sum[]){
    if(root==NULL) return;
    sum[level]+=root->val;
    calcSum(root->left,level+1,sum);
    calcSum(root->right,level+1,sum);   
}
int main(){
    int n; cin>>n;
    Node*root=NULL;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        root=insert(root,num);
    }
    cout<<getHeight(root)<<endl;;
    int levels = getHeight(root)+1;
    int sum[levels]={0};
    calcSum(root,0,sum);
    for(int i=0;i<levels-1;i++){
        cout<<sum[i]<<" ";
    }
}