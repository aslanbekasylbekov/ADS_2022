#include <iostream>
using namespace std;
int maximum = 0;
struct Node{
    int val;
    Node*left,*right;
    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node*root,int val){
    if(root==NULL) root = new Node(val);
    else if(root->val > val) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
}

int DFS(Node*root){
    if(root==NULL) return 0;
    else{
        int ldepth = DFS(root->left);
        int rdepth = DFS(root->right);
        if(ldepth>rdepth){
            return (ldepth+1);
        }else{
            return (rdepth+1);
        }
    }
}
void findpath(Node*root){
    if(root!=NULL){
        findpath(root->left);
        maximum = max((DFS(root->left) + DFS(root->right) + 1), maximum);
        findpath(root->right);
    }
}

int main(){
    int n; cin >> n;
    Node * root = NULL;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        root = insert(root,num);
    }
    findpath(root);
    cout << maximum;
    return 0;
}