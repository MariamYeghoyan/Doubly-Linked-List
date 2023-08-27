#include "LinkedList.h"
#include <iostream>

int main() {
    DLL dll;
    dll.push_back(10);
    dll.push_back(50);
    dll.push_back(100);
    dll.push_front(1000);

    std::cout << "You added the following elements into the list: ";

    dll.printList();
    dll.insert(10, 500); 

    std::cout << "Element at index 2 is ";

    std::cout << dll.get(2) << std::endl;

    dll.remove(0);

    std::cout << "Size after remove(0): " << dll.getSize() << std::endl;
    std::cout << "List after removing the element is: ";

    dll.printList();
    
    std::cout << "Reversed list is: ";
    
    dll.printReverse();

    return 0;
}
