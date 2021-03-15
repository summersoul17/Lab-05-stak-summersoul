// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "stak.hpp"

const int a = 10, b = 20, c = 30;

TEST(Stack_Test, Push_Test) {
    Stack<int> temp_stack;
    temp_stack.push(10);
    temp_stack.push(b);
    temp_stack.push(c);
    EXPECT_EQ(temp_stack.GetSize(), 3);
    EXPECT_EQ(temp_stack.head(),30);
}

TEST(Stack_Test, Pop_Test) {
    Stack<int> temp_stack;
    temp_stack.push(10);
    temp_stack.push(b);
    temp_stack.push(c);
    temp_stack.pop();
    EXPECT_EQ(temp_stack.GetSize(), 2);
    EXPECT_EQ(temp_stack.head(), 20);
}
