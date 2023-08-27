#include "LinkedList.h"
#include <iostream>

DLL::DLL() : head(nullptr), tail(nullptr), size(0) {}

DLL::DLL(int initialData) : head(nullptr), tail(nullptr), size(0) {
    push_back(initialData);
}

int DLL::getSize() {
    return size;
}

void DLL::push_back(int data) {
    newnode = new Node();
    newnode->data = data;
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
        ++size;
    }
    else {
        Node* tmp = tail;
        tail->next = newnode;
        newnode->prev = tmp;
        tail = newnode;
        ++size;
    }
}

void DLL::push_front(int data) {
    newnode = new Node();
    newnode->data = data;
    newnode->prev = nullptr;
    newnode->next = head;  
    if (head == nullptr) {
        tail = newnode;
    } else {
        head->prev = newnode;
    }
    head = newnode;  
    ++size;
}

void DLL::insert(int index, int value) {
    if (index < 0 || index > size) {
        std::cerr << "Error: Invalid index for insertion." << std::endl;
        return;  
    }

    newnode = new Node();
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = nullptr;

    if (index == 0) {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = nullptr;
        head = newnode;
        ++size;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            if (current != nullptr) {
                current = current->next;
            }
        }
        if(current != nullptr) {
            newnode->next = current->next;
            newnode->prev = current;
            current->next = newnode;
            if(newnode->next != nullptr) {
                newnode->next->prev = newnode;
            }
            ++size;
        }
    }
}

void DLL::remove(int index) {
    if (index < 0 || index > size) {
        std::cerr << "Error: Invalid index for insertion." << std::endl;
        return;  
    }
    else if (index == 0) {
        if (head != nullptr) {
            Node* current = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete current; 
        }
        --size;
    } 
    else {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
        }
        --size;
    }
}

int DLL::get(int index) {
    if (index < 0 || index > size) {
        std::cerr << "Error: Invalid index for insertion" << std::endl;
        return;  
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

void DLL::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DLL::printReverse() {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

DLL::~DLL() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}