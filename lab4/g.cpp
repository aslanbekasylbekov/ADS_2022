#include <iostream>
#include <cmath>
using namespace std;
struct node {
   int val;
   node* left;
   node* right;
};
node* createNewNode(int x){
    node* nn = new node;
    nn->val = x;
    nn->left  = NULL;
    nn->right = NULL;
    return nn;
}
void bstInsert(node* &root, int x){
    if(root == NULL) {
        root = createNewNode(x);
        return;
    }
    if(x < root->val){
        if(root->left == NULL) {
            root->left = createNewNode(x);
            return;
        } else bstInsert(root->left, x);
    }
    if( x > root->val ){
        if(root->right == NULL) {
            root->right = createNewNode(x);
            return;
        } else bstInsert(root->right, x);  
    }
}
class Sol{
public:
    int f(node* root,int &ans){
        if(root==NULL) return 0;
        int lh = f(root->left,ans);
        int rh = f(root->right,ans);
        ans = max(ans,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(node* root) {
        int ans = 0;
        f(root,ans);
        return ans;
    }
};
int main(){
	 Sol s;
     node* root=NULL;
     int n;
     cin>>n;
     for(int i=0;i<n;i++){
     	int a;
     	cin>>a;
	 	bstInsert(root,a);
	 }
     cout<<s.diameterOfBinaryTree(root)+1;
     return 0;
}