#include<iostream>
using namespace std;

// Stack using an array
class StackArray {
private:
    int max_size;
    int* stack;
    int top;

public:
    StackArray(int size) {
        max_size = size;
        stack = new int[max_size];
        top = -1;
    }

    void push(int value) {
        if (top < max_size - 1) {
            top++;
            stack[top] = value;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    int pop() {
        if (top >= 0) {
            int value = stack[top];
            top--;
            return value;
        } else {
            cout << "Stack underflow!" << endl;
            return -1;
        }
    }
};

// Circular Queue using an array
class QueueArray {
private:
    int max_size;
    int* queue;
    int front, rear;

public:
    QueueArray(int size) {
        max_size = size;
        queue = new int[max_size];
        front = rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % max_size != front) {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % max_size;
            queue[rear] = value;
        } else {
            cout << "Queue overflow!" << endl;
        }
    }

    int dequeue() {
        if (front != -1) {
            int value = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % max_size;
            }
            return value;
        } else {
            cout << "Queue underflow!" << endl;
            return -1;
        }
    }
};

// Queue using a linked list
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front != nullptr) {
            int value = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
            return value;
        } else {
            cout << "Queue underflow!" << endl;
            return -1;
        }
    }
};

int main() {
    // Example usage
    StackArray stack(5);
    stack.push(10);
    stack.push(20);
    cout << "Popped from stack: " << stack.pop() << endl;

    QueueArray queueArray(5);
    queueArray.enqueue(30);
    queueArray.enqueue(40);
    cout << "Dequeued from circular queue: " << queueArray.dequeue() << endl;

    QueueLinkedList queueLinkedList;
    queueLinkedList.enqueue(50);
    queueLinkedList.enqueue(60);
    cout << "Dequeued from linked list queue: " << queueLinkedList.dequeue() << endl;

    return 0;
}
