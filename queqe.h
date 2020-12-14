//
// Created by Furcas on 14.12.2020.
//

#ifndef QUEQE_QUEQE_H
#define QUEQE_QUEQE_H

#include "deque.h"
#include <queue>

template<class T, class TypeList = Deque<T>>
class Queue {
public:
    std::shared_ptr<TypeList> list = std::make_shared<TypeList>();
    TypeList *pointer = list.get();
    void push_elem(T data){

        pointer->push(data);

    };
    void pop(){

        pointer->emplace_front();

    };
    bool find(const T &data){

        return pointer->find(data);

    };

};


#endif //QUEQE_QUEQE_H
