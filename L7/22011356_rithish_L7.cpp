/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 7
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* leftbranch;
    Node* rightbranch;

    Node(string name) : name(name), leftbranch(nullptr), rightbranch(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    void addRoot(string name) {
        Node* newRoot = new Node(name);
        if (root == nullptr) {
            root = newRoot;
        } else {
            cout << "Root already exists" << endl;
        }
    }

    void addLeft(Node* parent, string name) {
        if (parent->leftbranch == nullptr) {
            parent->leftbranch = new Node(name);
            cout << "Added left child: " << name << " to parent: " << parent->name << endl;
        } else {
            cout << "Left child already exists";
        }
    }

    void addRight(Node* parent, string name) {
        if (parent->rightbranch == nullptr) {
            parent->rightbranch = new Node(name);
            cout << "Added right child: " << name << " to parent: " << parent->name << endl;
        } else {
            cout << "Right child already exiss";
        }
    }

    Node* findNode(Node* current, string name) { 
        if (current == nullptr) {
            return nullptr;
        }
        if (current->name == name) {
            return current;
        }
        Node* leftResult = findNode(current->leftbranch, name); 
        if (leftResult != nullptr) {
            return leftResult;
        }
        return findNode(current->rightbranch, name);
    }

    void tree_add_left(string parentName, string childName) {
        Node* parent = findNode(root, parentName);
        if (parent != nullptr) {
            addLeft(parent, childName);
        } else {
            cout << "Parent node " << parentName << " not found." << endl;
        }
    }

    void tree_add_right(string parentName, string childName) {
        Node* parent = findNode(root, parentName);
        if (parent != nullptr) {
            addRight(parent, childName);
        } else {
            cout << "Parent node " << parentName << " not found." << endl;
        }
    }
};

int main() {
    Tree tree;

    tree.addRoot("A");
    tree.tree_add_left("A", "B");
    tree.tree_add_right("A", "C");
    tree.tree_add_left("B", "D");
    tree.tree_add_right("B", "E");
    tree.tree_add_left("C", "F");
    tree.tree_add_right("C", "G");

    return 0;
}