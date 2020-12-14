//
// Created by Furcas on 14.12.2020.
//

#include <memory>

#ifndef QUEQE_NODES_H
#define QUEQE_NODES_H

template<class T>
struct Node {
    Node(T data) : data(data) {}

    T data;
};

template<class T>
struct Stack_Node : public Node<T> {
    Stack_Node(T data = T()) : Node<T>(data) {}

    std::shared_ptr<Stack_Node> p_next = nullptr;
};

template<class T>
struct Deque_Node : public Node<T> {
    Deque_Node(T data = T()) : Node<T>(data) {}

    std::shared_ptr<Deque_Node> p_next = nullptr;
    std::shared_ptr<Deque_Node> p_prev = nullptr;
};

#endif //QUEQE_NODES_H
