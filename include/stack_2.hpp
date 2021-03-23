// Copyright 2021 summersoul17 <17summersoul17@gmail.com>

#ifndef INCLUDE_STACK_2_HPP_
#define INCLUDE_STACK_2_HPP_

#include <string>
#include <iostream>
#include <utility>

template <typename T>
class Stack_2
{
public:
    class Container{
    public:
        Container* pointer;
        T data;

        explicit Container(Container* header_){
            pointer = header_->pointer;
            data = header_->pointer->data;
        }

        Container(Container* pointer_, T data_){
            pointer = pointer_;
            data = data_;
        }
    };
    Container* header;
    size_t stack_size = 0;

    size_t GetSize()const{return stack_size;}

    template <typename ... Args>
    void push_emplace(Args&&... value){
        T typeT = T(std::forward<Args>(value)...);
        Container* temp = new Container(header, typeT);
        header = temp;
        ++stack_size;
    }

    void push(T&& value){
        Container* temp = new Container(header, std::move(value));
        header = temp;
        ++stack_size;
    }

    const T& head() const{return header->data;}

    T pop(){
        Container* temp = new Container(header);
        T temp_data = header->data;
        delete header;
        header = temp;
        --stack_size;
        return temp_data;
    }

    Stack_2(){header = nullptr;}
    Stack_2(const Stack_2& value) = delete;
    Stack_2 operator=(const Stack_2&) = delete;
};

#endif //INCLUDE_STACK_2_HPP_
