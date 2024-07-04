/**
 * 成员模板
 * 任意类(模板或者非模板)可以拥有本身为类模板或者函数模板的成员，这种成员被称为成员函数模板
 * 考虑 vector 容器的 assign 成员函数，它可以接受两个迭代器为容器赋值，
 *      而这两个迭代器可以是 list 的迭代器、deque的迭代器、甚至是两个原生指针。也就是说成员函数 assign 的形参是不确定的。
 *      解决的方法是使用模板形参来表示迭代器形参的类型。下面给出一段小程序，使用成员模板技术。
*/

#include <iostream>
#include <list>

using namespace std;

//自定义
class MyAlloc
{
};

template<class T, class Alloc = MyAlloc>
class MyVector
{
public:
    typedef T value_type;
    typedef value_type* iterator;
    //成员模板，接收各种迭代器
    template<class I>
    void assign(I first, I last)
    {
        cout << "assign" << endl;
    }
};

int main()
{
    MyVector<int> v;
    int a[] = {1, 2, 3};
    list<int> l(a, a+3);
    cout << *a << " " << *(a + 2) << endl;
    v.assign(a, a+3);
    v.assign(l.begin(), l.end());
    

    return 0;
}

