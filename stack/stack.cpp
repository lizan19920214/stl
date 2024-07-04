/**
 * stack 堆栈容器
 * #include <stack>
 * 
 * 堆栈是一个线性表，插入和删除只能在表的一端进行。这一端称为栈顶(Stack Top)，另一端则为栈底(Stack Bottom)。堆栈的元素插入称为入栈，元素的删除称为出栈。
 * 由于元素的入栈和出栈总在栈顶进行，因此，堆栈是一个后进先出(Last In First Out)表，即 LIFO 表。
 *  ！！！！为了严格遵循堆栈的数据后进先出原则，stack 不提供元素的任何迭代器操作，因此，stack 容器也就不会向外部提供可用的前向或反向迭代器类型。
 * 
 * 入栈：
 * stack堆栈容器的元素入栈函数为 push 函数。由于 C++ STL 的堆栈函数是不预设大小的，因此，
 *      入栈函数就不考虑堆栈空间是否为满，均将元素压入堆栈，从而函数没有标明入栈成功与否的返回值。
 *      void  push(const value_type& x)
 * 
 * 出栈：
 * stack容器的元素出栈函数为 pop 函数，由于函数并没有判断堆栈是否为空，才进行元素的弹出，因此，
 *      需要自行判断堆栈是否为空，才可执行 pop 函数。
 *      void pop()
 * 
 * 全部出栈
 *  stack<int>  s;
 *  while(!s.empty())
 *  { 
 *     s.pop();// 出栈
 *  }
 * 
 * 取栈顶元素：
 *      value_type&  top()
 * 
 * 堆栈非空判断
 *      bool  empty()
 * 
*/

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i + 1);
    }

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    
    return 0;
}