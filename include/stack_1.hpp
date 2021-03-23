// Copyright 2021 summersoul17 <17summersoul17@gmail.com>

#ifndef INCLUDE_STACK_1_HPP_
#define INCLUDE_STACK_1_HPP_

#include <string>
#include <iostream>
#include <utility>

template <typename T>
class Stack_1
{
public:
    size_t GetSize()const{return stack_size;}

    void push(T&& value){
        Container* temp = new Container(std::move(value), header);
        header = temp;
        ++stack_size;
    }

    void push(const T& value){
        Container* temp = new Container(value, header);
        header = temp;
        ++stack_size;
    }

    void pop(){
        Container* temp = new Container(header);
        delete header;
        header = temp;
        --stack_size;
    }

    const T& head() const{return header->data;}

    Stack_1(){header = nullptr;}
    Stack_1(const Stack_1& value) = delete;
    Stack_1 operator=(const Stack_1&) = delete;

private:
    class Container{
    public:
        Container* pointer;
        T data = T();

        Container(T data_ = T(), Container* poineter_ = nullptr){
            pointer = poineter_;
            data = data_;
        }
        explicit Container(Container* header_){
            pointer = header_->pointer;
            data = header_->pointer->data;
        }
    };

    size_t stack_size = 0;
    Container* header;
};



#endif // INCLUDE_STACK_1_HPP_
