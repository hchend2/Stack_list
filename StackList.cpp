#include <iostream>

using namespace std;

class Node {
    public:
        int data; //
        Node* next; //
        //Node* top;

        //by default...
        Node() {
            data = 0;
            next = NULL;
            //top = NULL;
        }
        //parametized constructor...
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
            //this->top = NULL;
        }
};

class myStack {
    Node* top; // holds the top of the stack...
    public:
        // by default...
        myStack() {
            top = NULL;
        }

        void insert(int);
        void printStack();
        void topNode();
        bool isEmpty();
};

// function to insert a node into the stack...
void myStack::insert(int data) {

    Node* newNode = new Node();
    // stack heap is full...
    if (!newNode) {
        cout << "stack is full" << endl; // (stack overflow)...
        exit(1);
    }
    //stack heap is not full...
    newNode->data = data; // add data to stack...
    newNode->next = top; // save top into newNode pointing to next node...
    top = newNode; // make newNode the top of stack...
}

// function to print out the stack...
void myStack::printStack() {

    Node* tmp;
    // Stack is empty...
    if (top == NULL) {
        cout << "stack is empty" << endl; // (stack underflow)...
        exit(1);
    }
    // stack not empty...
    tmp = top;
    while (tmp != NULL) {
        cout << tmp->data <<endl;
        tmp = tmp->next;
    }
}
// check if stack is empty...
bool myStack::isEmpty() {
    return top == NULL;
}

// return top node of stack...
void myStack::topNode() {
    if (!isEmpty()) {
        cout << endl << top->data << endl;
    } else {
        exit(1);
    }
}

int main() {
    myStack stack;
    stack.insert(0);
    stack.insert(1);
    stack.insert(2);

    stack.printStack();
    stack.topNode();
    cout << "Hello! StackList " << endl;
}