#include <iostream>

using namespace std;

class Node {
    public:
        int data; //
        Node* next; //

        //by default
        Node() {
            data = 0;
            next = NULL;
        }
        //else...
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
};

int main() {
    cout << "Hello! StackList " << endl;
}