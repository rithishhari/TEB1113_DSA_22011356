/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 4
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next_ptr;

    Node(string n) : name(n), next_ptr(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail; 

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void add_element(Node* newNode) {
        if (!head) {
            head = tail = newNode;
            tail->next_ptr = head; 
        } else {
            tail->next_ptr = newNode;
            tail = newNode;
            tail->next_ptr = head; 
        }
    }

    void display_list() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->name << " -> ";
            temp = temp->next_ptr;
        } while (temp != head);
         cout << "(" << head->name << ")" << endl;
    }

    void delete_by_value(const string& val) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = tail;
        bool found = false;

        do {
            if (curr->name == val) {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next_ptr;
        } while (curr != head);

        if (!found) {
            cout << "Value '" << val << "' not found." << endl;
            return;
        }

        if (curr == head) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                head = head->next_ptr;
                tail->next_ptr = head;
                delete curr;
            }
        } else {
            prev->next_ptr = curr->next_ptr;
            if (curr == tail) {
                tail = prev;
            }
            delete curr;
        }

        cout << "Deleted node with value: " << val << endl;
    }
};

int main() {
    LinkedList linkedlst;

    Node* node1 = new Node("Rithish");
    Node* node2 = new Node("Rik");
    Node* node3 = new Node("Harid");
    Node* node4 = new Node("Salini");

    linkedlst.add_element(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);
    linkedlst.add_element(node4);

    linkedlst.display_list();

    
  

    return 0;
}