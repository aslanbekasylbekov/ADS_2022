#include <iostream>
using namespace std;

struct Node {
    int value;
    int cnt;
    Node *left, *right;

    Node(int value) {
        this->value = value;
        cnt = 1;
        left = NULL;
        right = NULL;
    }
};

Node* getMin(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* insert(int value, Node *root) {
    if (root == NULL) {
        root = new Node(value);
    } else if (root->value > value) {
        root->left = insert(value, root->left);
    } else if (root->value < value) {
        root->right = insert(value, root->right);
    } else {
        root->cnt++;
    }
    return root;
}

Node* remove(int value, Node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->value > value) {
        root->left = remove(value, root->left);
    } else if (root->value < value) {
        root->right = remove(value, root->right);
    } else {
        if (root->cnt > 1) {
            root->cnt--;
        } else if (!(root->left)) {
            return root->right;
        } else if (!(root->right)) {
            return root->left;
        } else {
            Node *mn = getMin(root->right);
            root->value = mn->value;
            root->cnt = mn->cnt;
            root->right = remove(mn->value, root->right);
        }
    }
    return root;
}

int count(int value, Node *root) {
    if (root == NULL) {
        return 0;
    } else if (root->value == value) {
        return root->cnt;
    } else if (root->value > value) {
        return count(value, root->left);
    } else {
        return count(value, root->right);
    }
}

int getHeight(Node *root) {
    if (root == NULL) return 0;
    else {
        return 1 + max(
            getHeight(root->left),
            getHeight(root->right)
        );
    }
}

int getSize(Node *root) {
    if (root == NULL) return 0;
    else return 1 + getSize(root->left) + getSize(root->right);
}

void preorder(Node *root) {
    if (root == NULL) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

int main() {
    // Node *root = NULL;
    // int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int a; cin >> a;
    //     root = insert(a, root);
    // }
    // inorder(root);
    // cout << endl;

    // int m; cin >> m;
    // for (int i = 0; i < m; i++) {
    //     int a; cin >> a;
    //     root = remove(a, root);
    //     inorder(root);
    // }

    int n; cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "insert") {
            root = insert(x, root);
        }
        if (op == "delete") {
            root = remove(x, root);
        }
        if (op == "cnt") {
            cout << count(x, root) << endl;
        }
    }
}