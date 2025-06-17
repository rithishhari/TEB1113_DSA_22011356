/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 3
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList(Node* head = nullptr) { 
        this->head = head;
        this->tail = head;
        if (head) head->next_ptr = nullptr;
    }

    void add_element(Node* node) {
        if (!node) return;
        
        node->next_ptr = nullptr;
        
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next_ptr = node; 
            tail = node;
        }
    }

    void display_list() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "nullptr" << endl;
    }

    void delete_by_value(string val) {
        if (!head) return;

        if (head->name == val) {
            Node* temp = head;
            head = head->next_ptr;
            delete temp;
            if (!head) tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next_ptr && current->next_ptr->name != val) {
            current = current->next_ptr;
        }

        if (current->next_ptr) {
            Node* temp = current->next_ptr;
            current->next_ptr = temp->next_ptr;
            if (temp == tail) tail = current;
            delete temp;
        }
    }

    Node* get_head() const {
        return head;
    }
};

int main() {
    Node* node1 = new Node("Rithish");
    Node* node2 = new Node("Rik");
    Node* node3 = new Node("Harid");

    LinkedList linkedlst(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    linkedlst.display_list();

    linkedlst.delete_by_value("Rik");
    cout << "After deleting Rik: ";
    linkedlst.display_list();

    Node* current = linkedlst.get_head(); 
    while (current) {
        Node* temp = current;
        current = current->next_ptr;
        delete temp;
    }

    return 0;
}