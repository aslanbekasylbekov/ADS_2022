#include <iostream>
using namespace std;

struct Node {
  string word;
  Node* next;

  Node() {}

  Node(string word) {
    this->word = word;
    this->next = NULL;
  }
};

// your code goes here

Node* cyclicShift(Node* head, int k, int n, Node* tail) {
    
    if(k > n){
        k = k % n;

    }
    int stop = 1;
    Node* temp = head;
    Node* nl;
    while(k > 0 ){   
        if(stop == 1){
            nl = temp;
        }
        temp = temp -> next;
        --k;
    }
    nl -> next = NULL;
    tail -> next = head;
    return temp;

}

void print(Node* head) {
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->word << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  int n; cin >> n;
  int k; cin >> k;
  Node* head;
  Node* cur;
  Node* tail;
  for (int i = 0; i < n; i++) {
    string word; cin >> word;
    if (i == 0) {
      head = new Node(word);
      cur = head;
    } else {
      cur->next = new Node(word);
      cur = cur->next;
            tail = cur;
    }
  }

  head = cyclicShift(head, k, n, tail);
    print(head);
}