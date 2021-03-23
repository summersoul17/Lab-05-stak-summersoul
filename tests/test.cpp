// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "stack_1.hpp"
#include "stack_2.hpp"

const int a = 10, b = 20, c = 30;

TEST(Stack_1_Test, Push_Test) {
    Stack_1<int> temp_stack;
    temp_stack.push(a);
    temp_stack.push(b);
    temp_stack.push(c);
    EXPECT_EQ(temp_stack.GetSize(), 3);
    EXPECT_EQ(temp_stack.head(),30);
}

TEST(Stack_1_Test, Pop_Test) {
    Stack_1<int> temp_stack;
    temp_stack.push(a);
    temp_stack.push(b);
    temp_stack.push(c);
    temp_stack.pop();
    EXPECT_EQ(temp_stack.GetSize(), 2);
    EXPECT_EQ(temp_stack.head(), 20);
}

TEST(Stack_2_Test, Pop_Test){
    Stack_2<int> temp_stack;
    temp_stack.push(10);
    temp_stack.push(20);
    temp_stack.push(30);
    temp_stack.pop();
    EXPECT_EQ(temp_stack.GetSize(), 2);
    EXPECT_EQ(temp_stack.head(), 20);

}

class TestClass{
public:
    int temp_1;
    double temp_2;
    std::string temp_3;

    TestClass(){
        temp_1 = 10;
        temp_2 = 10.10;
        temp_3 = "Доисторические времена. Выходит рыба на берег, а там армяне в нарды играют.";
    }

    TestClass(int value_1, double value_2, std::string value_3){
        temp_1 = value_1;
        temp_2 = value_2;
        temp_3 = value_3;
    }
};

TEST(Stack_2_Test, Push_Emplace_Test){
 Stack_2<TestClass> test_stack;
 TestClass test_1;
 test_stack.push_emplace(test_1);
 EXPECT_EQ(test_1.temp_1,test_stack.head().temp_1);
 EXPECT_EQ(test_1.temp_2,test_stack.head().temp_2);
 EXPECT_EQ(test_1.temp_3,test_stack.head().temp_3);
 TestClass test_2(322,13.37,"Заходишь на пару к Байдину, а там армяне в нарды играют");
 test_stack.push_emplace(test_2);
 EXPECT_EQ(test_2.temp_1,test_stack.head().temp_1);
 EXPECT_EQ(test_2.temp_2,test_stack.head().temp_2);
 EXPECT_EQ(test_2.temp_3,test_stack.head().temp_3);
}

TEST(Stack_2_Test, Is_Move_Test){
    EXPECT_TRUE(std::is_move_assignable<int>::value);
    EXPECT_TRUE(std::is_move_constructible<int>::value);
    EXPECT_TRUE(std::is_move_assignable<TestClass>::value);
    EXPECT_TRUE(std::is_move_constructible<TestClass>::value);
}