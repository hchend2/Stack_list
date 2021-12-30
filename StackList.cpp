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


    newNode->next = top;
    top = newNode;

}

int main() {

    cout << "Hello! StackList " << endl;
}