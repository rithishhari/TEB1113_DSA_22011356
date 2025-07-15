/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 6 Circular Queue
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node *next_ptr;

    Node(string name, Node *next_ptr = nullptr)
    {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue(Node *front = nullptr)
    {
        this->front = front;
        this->rear = front;
        if (front)
            front->next_ptr = nullptr;
    }

    ~Queue()
    {
        while (front)
        {
            dequeue();
        }
    }

    void enqueue(Node *node)
    {
        if (!node)
            return;

        node->next_ptr = nullptr;

        if (!front)
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next_ptr = node;
            rear = node;
        }
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next_ptr;
        cout << "Removing: " << temp->name << endl;
        delete temp;

        if (!front)
            rear = nullptr;
    }

    void display_queue()
    {
        Node *current = front;
        if (!current)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        while (current)
        {
            cout << current->name;
            if (current->next_ptr)
                cout << " <- ";
            current = current->next_ptr;
        }

        cout << " <- NULL" << endl;
    }
};

int main()
{
    Node *node1 = new Node("Rik");
    Node *node2 = new Node("Rithish");
    Node *node3 = new Node("Harid");
    Node *node4 = new Node("Neb");

    Queue queue(node1);
    queue.enqueue(node2);
    queue.enqueue(node3);
    queue.enqueue(node4);

    cout << "Initial Queue: ";
    queue.display_queue();

    queue.dequeue();

    cout << "After Dequeue: ";
    queue.display_queue();

    return 0;
}