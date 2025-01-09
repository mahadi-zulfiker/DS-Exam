#include <iostream>
using namespace std;

class Stack {
    int top;
    int* arr;
    int capacity;

public:
    Stack(int size) {
        top = -1;
        capacity = size;
        arr = new int[size];
    }

    Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top < capacity - 1) {
            arr[++top] = value;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

class Queue {
    int front, rear, capacity;
    int* arr;

public:
    Queue(int size) {
        front = 0;
        rear = 0;
        capacity = size;
        arr = new int[size];
    }

    Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (rear < capacity) {
            arr[rear++] = value;
        }
    }

    int dequeue() {
        if (front < rear) {
            return arr[front++];
        }
        return -1;
    }

    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Stack stack(n);
    Queue queue(m);

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        stack.push(value);
    }

    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        queue.enqueue(value);
    }

    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    while (!stack.isEmpty() && !queue.isEmpty()) {
        if (stack.pop() != queue.dequeue()) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
