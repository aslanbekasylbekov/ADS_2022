#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left,*right;
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
Node*insert(Node*root,int x,int y,int z){
    if(root==NULL){
        root = new Node(y);
        return root;
    }
    if(root->val==x){
        if(z==0) root->left = insert(root->left,x,y,z);
        else root->right = insert(root->right,x,y,z);
    }
    insert(root->left,x,y,z);
    insert(root->right,x,y,z);
    return root;
}
int getHeight(Node*root){
    if(root==NULL) return 0;
    else return 1 + max(getHeight(root->left),getHeight(root->right));
}
int width(Node*root,int level){
    if(root==NULL) return 0;
    else if(level==1) return 1;
    else return width(root->left,level-1)+width(root->right,level-1);
}
int main(){
    int n; cin>>n;
    Node*root=new Node(1);
    for(int i=0;i<n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        root = insert(root,a,b,c);
    }
    int maks = 0;
    for(int i=1;i<getHeight(root)+1;i++){
        maks = max(maks, width(root,i));
    }
    cout<<maks;
}