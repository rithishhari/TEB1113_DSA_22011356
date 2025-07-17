/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 8 
*/

#include <iostream>
using namespace std;

class Node {
public:
    int num;
    Node* leftbranch;
    Node* rightbranch;

    Node(int num) : num(num), leftbranch(nullptr), rightbranch(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    void insert(int num) {
        root = insert_recursive(root, num);
    }

    Node* insert_recursive(Node* node, int num) {
        if (node == nullptr) {
            return new Node(num);
        }

        if (num < node->num) {
            node->leftbranch = insert_recursive(node->leftbranch, num);
        } else if (num > node->num) {
            node->rightbranch = insert_recursive(node->rightbranch, num);
        }
        return node;
    }

    bool search(int num) {
        return search_recursive(root, num);
    }

    bool search_recursive(Node* node, int num) {
        if (node == nullptr) {
            return false;
        }

        if (num == node->num) {
            return true;
        } else if (num < node->num) {
            return search_recursive(node->leftbranch, num);
        } else {
            return search_recursive(node->rightbranch, num);
        }
    }

    void display_preorder(Node* node) {
        if (node == nullptr)
            return;

        cout << node->num << " ";
        display_preorder(node->leftbranch);
        display_preorder(node->rightbranch);
    }

    void display() {
        cout << "Preorder Traversal: ";
        display_preorder(root);
        cout << endl;
    }
};

int main() {
    Tree tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(10);
    tree.insert(3);
    tree.insert(1);
    tree.insert(7);

    tree.display();

    int valueToSearch;
    cout << "Enter a number to search in the tree: ";
    cin >> valueToSearch;

    if (tree.search(valueToSearch)) {
        cout << valueToSearch << " was found in the tree." << endl;
    } else {
        cout << valueToSearch << " was not found in the tree." << endl;
    }

    return 0;
}