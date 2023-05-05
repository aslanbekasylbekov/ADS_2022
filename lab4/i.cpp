#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left,*right;
    int cnt;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
        cnt=1;
    }
};
Node*getMin(Node*root){
    while(root->left){
        root=root->left;
    }
    return root;
}
Node*insert(Node*root,int val){
    if(root==NULL) root=new Node(val);
    else if(root->val>val) root->left=insert(root->left,val);
    else if(root->val<val) root->right=insert(root->right,val);
    else root->cnt++;
    return root;
}
Node*remove(Node*root,int val){
    if(root==NULL) return NULL;
    else if(root->val>val) root->left=remove(root->left,val);
    else if(root->val<val) root->right=remove(root->right,val);
    else{
        if(root->cnt>1){
            root->cnt--;
        } else if(!(root->left)){
            return root->right;
        } else if(!(root->right)){
            return root->left;
        } else{
            Node*mn=getMin(root->right);
            root->val=mn->val;
            root->cnt=mn->cnt;
            root->right=remove(root->right,mn->val);
        }
    }
    return root;
}
int count(int val,Node*root){
    if(root==NULL) return 0;
    else if(root->val==val) return root->cnt;
    else if(root->val>val) return count(val,root->left);
    else return count(val,root->right);
}
int main(){
    int n; cin>>n;
    Node*root=NULL;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int num; cin>>num;
        if(s=="insert"){
            root=insert(root,num);
        }  if(s=="delete"){
            root=remove(root,num);
        } if(s=="cnt"){
            cout<<count(num,root)<<endl;;
        }
    }
}