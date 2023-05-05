#include <iostream>
using namespace std;
int sum=0;
struct Node{
    public:
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
    else if(root->val>val) root->left = insert(root->left,val);
    else root->right = insert(root->right,val);
    return root;
}

int getHeight(Node*root){
    if(root==NULL) return 0;
    else{
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
}
void print(Node*root,int level){
    if(root==NULL) return;
    sum+=(root->val-level);
    print(root->left,level+1);
    print(root->right,level+1);
}
int main(){
    int n; cin>>n;
    Node*root=NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        root=insert(root,x);
    }
    print(root,0);
    cout<<sum;
}