//
// Created by Furcas on 14.12.2020.
//

#ifndef QUEQE_DEQUE_H
#define QUEQE_DEQUE_H

#include <memory>
#include "nodes.h"
#include "stack.h"

template<class T, class TypeNode = Deque_Node<T>>
class Deque : public Stack<T, TypeNode> {
public:

    virtual void push(T data) override;
    virtual void remove(const T &data) override;
    virtual void emplace_front() override;

};

template<class T, class TypeNode>
inline void Deque<T, TypeNode>::push(T data) {
    auto new_element = std::make_shared<TypeNode>(data);
    if (this->head == nullptr)
        this->head = new_element;
    else {
        std::shared_ptr<TypeNode> current = this->head;
        while (current->p_next != nullptr) {
            current = current->p_next;
        }

        current->p_next = new_element;
        current->p_next->p_prev = current;

    }

}

template<class T, class TypeNode>
inline void Deque<T, TypeNode>::remove(const T &data) {
    if (this->head == nullptr)
        return;

    std::shared_ptr<TypeNode> current_shared_p = this->head;
    std::shared_ptr<TypeNode> prev_shared_p = this->head;

    TypeNode *current_p = this->head.get();

    while (current_p != nullptr) {

        if (current_pointer->data == data && current_shared_p == this->head) {
            this->head = current_p->p_next;
            current_p->p_next->p_prev.reset();
            return;
        }

        if (current_p->data == data) {
            prev_shared_p->p_next = move(current_p->p_next);

            if (current_p->p_next == nullptr)
                return;
            current_p->p_next->p_prev = prev_shared_p;

        }
        prev_shared_p = current_shared_p;
        current_shared_p = current_p->p_next;
        current_p = current_p->p_next.get();


    }
}

template<class T, class TypeNode>
inline void Deque<T, TypeNode>::emplace_front() {
    Deque<T, TypeNode>::emplace_front();

    TypeNode *head_pointer = this->head.get();
    head_pointer->p_prev.reset();
}

#endif //QUEQE_DEQUE_H
