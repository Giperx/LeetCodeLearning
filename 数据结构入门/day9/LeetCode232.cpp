//
// Created by Giperx on 2022/9/20.
//
#include <iostream>
#include <stack>
using namespace std;
//用栈实现队列
// O(1) O(n) 用两个栈来模拟
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

    void to2(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if(s2.empty()) to2();

        int tmp = s2.top();
        s2.pop();
        return tmp;
    }

    int peek() {
        if(s2.empty()) to2();

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
