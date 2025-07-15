/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 6 Queue
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node *next_ptr;

    Node(string name, Node *next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue {
private:
    Node *front;
    Node *rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(Node *node) {
        if (!node) return;

        node->next_ptr = nullptr;

        if (!front) {
            front = rear = node;
        } else {
            rear->next_ptr = node;
            rear = node;
        }
    }

    void display_queue() {
        Node *current = front;
        if (!current) {
            cout << "Queue is empty" << endl;
            return;
        }
        while (current) {
            cout << current->name << " <- ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next_ptr;
        if (!front) rear = nullptr; 
        cout << "Removing: " << temp->name << endl;
        delete temp;
    }
};

int main() {
    Queue queue;

    queue.enqueue(new Node("Rik"));
    queue.enqueue(new Node("Rithish"));
    queue.enqueue(new Node("Harid"));
    queue.enqueue(new Node("Neb"));

    cout << "Queue: ";
    queue.display_queue();

    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}
