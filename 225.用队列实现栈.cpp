/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        int topValue = q1.front();
        q1.pop();
        return topValue;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.empty() << endl;

    return 0;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
