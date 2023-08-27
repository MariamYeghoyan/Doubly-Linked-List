#ifndef LINKED_LIST
#define LINKED_LIST

class DLL {
    public:
        DLL();
        DLL(int initialData);
        int getSize();
        void push_back(int data);
        void push_front(int data);
        void insert(int index, int value);
        void remove(int index);
        int get(int index);
        void printList();
        void printReverse();
        ~DLL();

    private:
        struct Node {
            int data;
            Node* next;
            Node* prev;
        };
        Node* head;
        Node* tail;
        Node* newnode;
        int size;
};

#endif