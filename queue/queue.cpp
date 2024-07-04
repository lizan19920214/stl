/**
 * queue队列
 * #include <queue>
 * 
 * queue是一种非常重要的数据结构，它遵循先进先出（FIFO，First In First Out）的原则。这意味着最早进入队列的元素将首先被移除
 * 
 * push()：在队列尾部插入一个元素。
 * pop()：移除队列头部的元素。注意，如果队列为空，执行此操作将引发未定义行为。
 * front()：返回队列头部的元素，但不移除它。
 * back()：返回队列尾部的元素，但不移除它。
 * empty()：检查队列是否为空，如果为空则返回true，否则返回false。
 * size()：返回队列中的元素数量。
 * 
 * 
 * 
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void test1()
{
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        q.push(i + 1);
    }
    

    if (!q.empty())
    {
        cout << "queue is not empty" << endl;
        cout << "queue size is:" << q.size() << endl;
        cout << "queue top value:" << q.front() << endl;
        cout << "queue back value:" << q.back() << endl;

        //移除头部数据
        q.pop();
        cout << "queue top value:" << q.front() << endl;
    }
}

int main()
{
    test1();
    return 0;
}