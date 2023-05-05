# include <iostream>
# include <algorithm>
# include <cassert>
using namespace std;
struct Node {
  int val;
  Node *next;
  Node() {
    val = 0;
    next = NULL;
  }
};
int findMaxSum(int n, Node *head) {
	// Implement this function
  Node*temp=head;
  int m=-1e9,sum=0;
  for(;temp;){
    sum+=temp->val;
    if(m<sum) m=sum;
    if(sum<0) sum=0;
    temp=temp->next;
  }
  return m;
}
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
  cout << findMaxSum(n, head) << "\n";
  return 0;
}