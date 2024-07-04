/**
 * 仿函数，就是使一个类的使用看上去像一个函数，实现就是类中实现一个operator()，这个类就有了类似函数的行为，operator()称为函数对象或者仿函数。
 * 仿函数是可被调用的函数对象，它是一种重载了()操作符的类，使得类对象可以像函数一样被调用。
 * 
 * 有些功能的的代码，会在不同的成员函数中用到，想复用这些代码。
 *     1）公共的函数，可以，这是一个解决方法，不过函数用到的一些变量，就可能成为公共的全局变量，再说为了复用这么一片代码，就要单立出一个函数，也不是很好维护。
 *     2）仿函数，写一个简单类，除了那些维护一个类的成员函数外，就只是实现一个operator()，在类实例化时，就将要用的，非参数的元素传入类中。
 * 
 * 
*/

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class display
{
public:
    void operator()(const T& x)
    {
        cout << x << " " << endl;
    }
};

class IsGreaterThanThresholdFunctor 
{
public:
	explicit IsGreaterThanThresholdFunctor(int t):threshold(t)
    {
        cout << " threadhold = " << threshold << endl;
    }

	bool operator() (int num) const 
    {
        cout << " num = " << num << endl;
		return num > threshold ? true : false;
	}
private:
	const int threshold;
};

int RecallFunc(int *start, int *end, IsGreaterThanThresholdFunctor myFunctor) 
{
	int count = 0;
	for (int *i = start; i != end + 1; i++) 
    {
		count = myFunctor(*i) ? count + 1 : count;
	}
	return count;
}

void test1()
{
    int arr[] = {1, 2, 3, 4, 5};
    for_each(arr, arr + 5, display<int>());
}

void test2()
{
	int a[5] = {10,100,11,5,19};
	int result = RecallFunc(a, a + 4, IsGreaterThanThresholdFunctor(10));
	cout << result << endl;
}

int main()
{
    test1();
    cout << endl;
    test2();
    return 0;
}