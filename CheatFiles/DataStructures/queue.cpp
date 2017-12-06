#include <iostream>
using namespace std;

    class c_queue {
        private:
            struct t_queue {
                int data;
                struct t_queue *next;

                t_queue(int newData) {
                    data = newData;
                    next = NULL;
                }
            };
            struct t_queue *head, *tail;
            int count;

        public:
            c_queue() {
                head = NULL;
                tail = NULL;
                count = 0;
            }

            void enqueue(int newData);
            int dequeue();
            void print();
            bool isEmpty();

            ~c_queue() {
                t_queue *currentNode;
                while (head != NULL) {
                    currentNode = head;
                    head = head->next;
                    delete currentNode;
                }
                tail = NULL;
            }
    };

    void c_queue::enqueue(int newData) {
        struct t_queue *newNode = new t_queue(newData);

        if (count == 0) {
            head = newNode;
            tail = newNode;
        }
        else tail->next = newNode;

        tail = newNode;
        count++;
    }

    int c_queue::dequeue() {
        if (count == 0) return -1;

        int headData = head->data;
        struct t_queue *currentNode = head;

        if (count == 1) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
        }

        count--;
        delete currentNode;
        return headData;
    }

    void c_queue::print() {
        if (count == 0) {
            cout << "queue is empty!\n";
            return;
        }

        struct t_queue *currentNode = head;
        cout << "queue :";
        while (currentNode != NULL) {
            cout << " " << currentNode->data;
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    bool c_queue::isEmpty() {
        return count == 0;
    }



int main() {
    cout << "my queue class\n";

    c_queue mQueue;

    mQueue.enqueue(1);
    mQueue.enqueue(2);
    mQueue.enqueue(3);
    mQueue.enqueue(4);
    mQueue.enqueue(5);
    mQueue.dequeue();
    mQueue.dequeue();
    mQueue.dequeue();
    mQueue.dequeue();
    mQueue.dequeue();
    mQueue.dequeue();
    mQueue.enqueue(5);
    mQueue.print();

    return 0;
}