#include <iostream>
using namespace std;

class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
      capacity = size;
       arr = new int[capacity];
        top = -1;
    }

    Stack() {
        delete[] arr;
    }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == capacity - 1); }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << " Pushed: " << x << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << " Stack Underflow! Nothing to pop.\n";
        } else {
            cout << " Popped: " << arr[top--] << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << " Stack is empty!\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << " Stack is empty!\n";
        } else {
            cout << " Stack (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size);

    int choice, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << " Exiting program...\n";
            break;
        default:
            cout << " Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
