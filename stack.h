//
// Created by Furcas on 14.12.2020.
//

#ifndef QUEQE_STACK_H
#define QUEQE_STACK_H

#include <memory>
#include "nodes.h"

template<class T, class TypeNode = Stack_Node<T>>
class Stack {
protected:

    std::shared_ptr<TypeNode> head;
public:


    virtual void push(T data) ;
    virtual bool find(const T &data) ;
    virtual void remove(const T &data) ;
    virtual void emplace_front();


};

template<class T, class TypeNode>
inline void Stack<T, TypeNode>::push(T data) {

    auto new_element = std::make_shared<TypeNode>(data);

    if (head == nullptr)
        head = new_element;
    else {
        std::shared_ptr<TypeNode> current = head;
        while (current->p_next != nullptr)
            current = current->p_next;
        current->p_next = new_element;
    }
}

template<class T, class TypeNode>
inline bool Stack<T, TypeNode>::find(const T &data) {

    TypeNode *p = head.get();

    while (p != nullptr) {
        if (p->data == data)
            return true;

        p = p->p_next.get();
    }

    return false;
}

template<class T, class TypeNode>
inline void Stack<T, TypeNode>::remove(const T &data) {
    if (head == nullptr)
        return;

    std::shared_ptr<TypeNode> current_shared_p = head;
    std::shared_ptr<TypeNode> prev_shared_p = head;

    TypeNode *current_p = head.get();

    while (current_p != nullptr) {

        if (current_pr->data == data && current_shared_p == head) {
            head = current_p->p_next;
            return;
        }

        if (current_pointer->data == data) {
            prev_shared_p->p_next = move(current_p->p_next);
            return;
        }


        prev_shared_p = current_shared_p;
        current_shared_p = current_p->p_next;
        current_p = current_p->p_next.get();


    }

}

template<class T, class TypeNode>
inline void Stack<T, TypeNode>::emplace_front() {
    TypeNode *head_pointer = head.get();
    head = head_pointer->p_next;
}

#endif //QUEQE_STACK_H
