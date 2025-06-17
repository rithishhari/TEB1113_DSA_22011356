/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 3 (2)
*/

#include <iostream>
using namespace std;

struct SLLNode {
    int data;
    SLLNode* next;
};

class SinglyLinkedList {
private:
    SLLNode* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void addNode(int value) {
        SLLNode* newNode = new SLLNode{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            SLLNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        SLLNode* temp = head;
        cout << "Singly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            SLLNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        SLLNode* current = head;
        while (current->next && current->next->data != value)
            current = current->next;

        if (current->next) {
            SLLNode* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        }
    }
};

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
};

class DoublyLinkedList {
private:
    DLLNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void addNode(int value) {
        DLLNode* newNode = new DLLNode{value, nullptr, nullptr};
        if (!head) {
            head = newNode;
        } else {
            DLLNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display() {
        DLLNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int value) {
        DLLNode* temp = head;

        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }
};

int main() {
    SinglyLinkedList sll;
    DoublyLinkedList dll;

    int choice, value;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add to Singly Linked List\n";
        cout << "2. Display Singly Linked List\n";
        cout << "3. Delete from Singly Linked List\n";
        cout << "4. Add to Doubly Linked List\n";
        cout << "5. Display Doubly Linked List\n";
        cout << "6. Delete from Doubly Linked List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                sll.addNode(value);
                break;
            case 2:
                sll.display();
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                sll.deleteNode(value);
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                dll.addNode(value);
                break;
            case 5:
                dll.display();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                dll.deleteNode(value);
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}