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

Node* top; // holds the top of the stack...

// function to insert a node into the stack...
void insert(int data) {
    Node* newNode = new Node();

    // stack heap is full...
    if (!newNode) {
        cout << "stack is full" << endl; //(stack overflow)...
        exit(1);
    }
    //stack heap is not full...
    newNode->data = data; // add data to stack...
    newNode->next = top; // save top into newNode pointing to next node...
    top = newNode; //make newNode the top of stack...

}

// function to print out the stack...
void printStack() {
    Node* tmp;

    // Stack is empty...
    if (top == NULL) {
        cout << "stack is empty" << endl; //(stack underflow)...
        exit(1);
    }

    //stack not empty...
    tmp = top;
    while (tmp != NULL) {
        cout << tmp->data <<endl;
        tmp = tmp->next;
    }
}
// check if stack is empty...
bool isEmpty() {
    return top == NULL;
}

// return top node of stack...
void topNode() {
    if (!isEmpty()) {
        cout<< endl << top->data << endl;
    } else {
        exit(1);
    }
}

int main() {

    insert(0);
    insert(1);
    insert(2);

    printStack();
    topNode();
    cout << "Hello! StackList " << endl;
}