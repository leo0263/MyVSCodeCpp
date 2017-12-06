#include <iostream>
using namespace std;

    class sidangdut {
        private:
            struct t_stack {
                int data;
                struct t_stack *next;

                t_stack() {
                    data = 0;
                    next = NULL;
                }
            };
            struct t_stack *top;
        int count;

        public:
        sidangdut() {
            count = 0;
            top = NULL;
        }

        void tambah();
        void kurang();
        void print();
    };

    void sidangdut::tambah() {
        count++;
    }

    void sidangdut::kurang() {
        count--;
    }

    void sidangdut::print() {
        cout << "now : " << count << endl;
    }

int main() {
    sidangdut s;
    s.print();
    s.tambah();
    s.tambah();
    s.print();
    s.kurang();
    s.print();

    return 0;
}