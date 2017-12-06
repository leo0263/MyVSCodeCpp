#include <iostream>
using namespace std;

    class c_stack {
        private:
            struct t_stack {
                int data;
                struct t_stack *next;

                t_stack(int newData) {
                    data = newData;
                    next = NULL;
                }
            };
            struct t_stack *top;
            int count;

        public:
            c_stack() {
                top = NULL;
                count = 0;
            }

            void push(int newData);
            int pop();
            int peek();
            void print();
            bool isEmpty();

            ~c_stack() {
                t_stack *currentNode;
                while (top != NULL) {
                    currentNode = top;
                    top = top->next;
                    delete currentNode;
                }
            }
    };

    void c_stack::push(int newData) {
        struct t_stack *newNode = new t_stack(newData);

        if (count == 0) top = newNode;
        else newNode->next = top;

        top = newNode;
        count++;
    }

    int c_stack::pop() {
        if (count == 0) return -1;

        int topData = top->data;
        struct t_stack *currentNode = top;
        top = top->next;
        count--;

        delete currentNode;
        return topData;
    }

    int c_stack::peek() {
        if (count == 0) return -1;
        return top->data;
    }

    void c_stack::print() {
        if (count == 0) {
            cout << "stack is empty!\n";
            return;
        }

        struct t_stack *currentNode = top;
        cout << "stack :";
        while (currentNode != NULL) {
            cout << " " << currentNode->data;
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    bool c_stack::isEmpty() {
        return count == 0;
    }



int main() {
    cout << "my stack class\n";

    c_stack mStack;

    mStack.push(1);
    mStack.push(2);
    mStack.push(3);
    mStack.push(4);
    mStack.push(5);
    // mStack.pop();
    // mStack.pop();
    // mStack.pop();
    // mStack.pop();
    // mStack.pop();
    // mStack.pop();
    mStack.push(5);
    mStack.print();

    return 0;
}