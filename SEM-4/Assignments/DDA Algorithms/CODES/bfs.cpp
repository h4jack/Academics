#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;
};

class RBTree {
private:
    Node *root;
    Node *TNULL;

    void initializeNULLNode(Node *node, Node *parent) {
        node->data = 0;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = BLACK;
    }

    void preOrderHelper(Node *node) {
        if (node != TNULL) {
            cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    void rotateLeft(Node *&x) {
        Node *y = x->right;
        x->right = y->left;
        if(y->left != TNULL)
            y->left->parent = x;
        y->parent = x->parent;
        if(x->parent == nullptr)
            this->root = y;
        else if(x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node *&x) {
        Node *y = x->left;
        x->left = y->right;
        if(y->right != TNULL)
            y->right->parent = x;
        y->parent = x->parent;
        if(x->parent == nullptr)
            this->root = y;
        else if(x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node *k) {
        Node *u;
        while(k->parent->color == RED) {
            if(k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if(u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if(k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateLeft(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;
                if(u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if(k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateRight(k->parent->parent);
                }
            }
            if(k == root)
                break;
        }
        root->color = BLACK;
    }

    void transplant(Node *u, Node *v) {
        if(u->parent == nullptr)
            root = v;
        else if(u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    void deleteFix(Node *x) {
        Node *s;
        while(x != root && x->color == BLACK) {
            if(x == x->parent->left) {
                s = x->parent->right;
                if(s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    s = x->parent->right;
                }
                if(s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if(s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rotateRight(s);
                        s = x->parent->right;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if(s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    s = x->parent->left;
                }
                if(s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                } else {
                    if(s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        rotateLeft(s);
                        s = x->parent->left;
                    }
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    Node* minimum(Node *node) {
        while(node->left != TNULL)
            node = node->left;
        return node;
    }

    void deleteNodeHelper(Node *node, int key) {
        Node *z = TNULL;
        Node *x, *y;
        while(node != TNULL){
            if(node->data == key)
                z = node;
            if(node->data <= key)
                node = node->right;
            else
                node = node->left;
        }

        if(z == TNULL) return;

        y = z;
        int y_original_color = y->color;
        if(z->left == TNULL) {
            x = z->right;
            transplant(z, z->right);
        } else if(z->right == TNULL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if(y->parent == z)
                x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if(y_original_color == BLACK)
            deleteFix(x);
    }

public:
    RBTree() {
        TNULL = new Node;
        initializeNULLNode(TNULL, nullptr);
        root = TNULL;
    }

    void insert(int key) {
        Node *node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        Node *y = nullptr;
        Node *x = this->root;

        while(x != TNULL) {
            y = x;
            if(node->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        node->parent = y;
        if(y == nullptr)
            root = node;
        else if(node->data < y->data)
            y->left = node;
        else
            y->right = node;

        if(node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        if(node->parent->parent == nullptr)
            return;

        fixInsert(node);
    }

    void deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }

    void preorder() {
        preOrderHelper(this->root);
        cout << endl;
    }
};

int main() {
    RBTree tree;
    tree.insert(8);
    tree.insert(18);
    tree.insert(5);
    tree.insert(15);
    tree.insert(17);
    tree.insert(25);
    tree.insert(40);
    tree.insert(80);

    cout << "Preorder after insertion: ";
    tree.preorder();

    tree.deleteNode(25);
    cout << "Preorder after deleting 25: ";
    tree.preorder();
    return 0;
}
