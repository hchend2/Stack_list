#include <iostream>

using std::endl;
using std::cout;

class Node {
    public:
        int data; //
        Node* prev; //

        // by default...
        Node() {
            data = 0;
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
            size = 0;
        }
        //methods of the myStack...
        void insert(int data);
        void topNode();
        bool isEmpty(); 
        void popTopNode();
        int Size() const;
        void printStack();
};

// function to insert a node into the stack...
void myStack::insert(int data) {

    Node* newNode = new Node();
    // stack heap is full...
    if (!newNode) {
        cout << "Stack overflow" << endl; // ()...
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
        cout << "Stack underflow" << endl; // ()...
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
        cout << top->data << endl;
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
    top = top->prev; // save  top->prev into top...
    delete tmp; // free memory of top node...
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
    cout << "size of stack is: " << stack.Size() << endl;
    cout << "Top of stack is: "; stack.topNode();
    cout << endl;
    stack.popTopNode();
    stack.popTopNode();
    stack.popTopNode();
    stack.printStack();
    cout << "New top of stack is: "; stack.topNode();
    cout << "New size of stack is: " << stack.Size() << endl;
}