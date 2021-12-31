#include <iostream>

using namespace std;

class Node {
    public:
        int data; //
        Node* prev; //

        // by default...
        Node() {
            data = 0;
            prev = NULL;
            prev = NULL;
        }
        //parametized constructor...
        Node(int data) {
            this->data = data;
            this->prev = NULL;
        }
};

class myStack {
    Node* top; // holds the top of the stack...
    int size; // size of the stack...
    public:
        // by default...
        myStack() {
            top = NULL;
        }
        void insert(int data);
        void printStack();
        void topNode();
        bool isEmpty();
        void popTopNode();
        int Size() const;
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
    newNode->prev = top; // save top into newNode pointing to next node...
    top = newNode; // make newNode the top of stack...
    newNode->data = data; // add data to stack...
    size++;
}
// function to return the size of the stack...
int myStack::Size() const {
    return size;
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
        cout << tmp->data << endl;
        tmp = tmp->prev; 
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
// remove the top node from stack...
void myStack::popTopNode() {

    Node* tmp;
    // stack is empty...
    if (top == NULL) {
        cout << endl << "Stack underflow " << endl;
        exit(1);
    }
    // stack not empty...
    tmp = top; // save top node into tmp...
    top = top->prev; // sava pointing to next into top...
    // free memory of top node...
    delete tmp;
    size--; 
}

int main() {

    myStack stack;
    stack.insert(0);
    stack.insert(1);
    stack.insert(2);
    stack.insert(3);
    stack.insert(4);
    stack.printStack();

    stack.topNode();
    cout << endl;
    stack.popTopNode();
    stack.popTopNode();
    stack.popTopNode();

    stack.topNode();
    cout << endl;
    cout << "check" << endl;
    stack.printStack();
    
    cout << "Hello! StackList " << endl;
}