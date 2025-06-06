#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    Element* old_head = head;
    head = new Element{entry};
    head->next = old_head;
    current_size++;
}

int List::pop() {
    if (head == nullptr) throw std::length_error{"LL was empty"};

    Element* to_remove = head;    
    head = head->next;
    current_size--;
    int result = to_remove->data;
    delete to_remove;
    to_remove = nullptr;
    return result;
}

void List::reverse() {
    if (head == nullptr) return;

    Element sentinal {0};
    sentinal.next = head;

    Element* prev = &sentinal;
    for (Element* cur = prev->next; cur != nullptr; ){
        Element* old_next = cur->next;

        if (prev == &sentinal) {
            cur->next = nullptr;
        } else {
            cur->next = prev;
        }

        prev = cur;
        cur = old_next;
    }

    head = prev;
}

List::~List() {
    for (Element* e = head; e != nullptr;){
        Element *next = e->next;
        delete e;
        e = next;
    }
}

}  // namespace simple_linked_list
