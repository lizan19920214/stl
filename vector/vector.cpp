/**
 * 
 * vector 容器
 * #include<vector>
 * 
 * 向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，
 *      它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。
 * 
 * 1. 底层数据结构是数组
 * 2. 支持随机访问
 * 3. 插入和删除元素时，可能会导致元素移动
 * 4. 内存空间可以自动扩展
 * 5. 插入和删除元素效率高，访问元素效率低
 * 6. 支持迭代器
 * 7. 支持双向迭代器
 * 8. 支持随机访问迭代器
 * 9. 支持比较运算符
 * 10. 支持赋值运算符
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

//vector的默认初始化方式
void test1()
{
    //默认初始化
    vector<int> v1;
    //创建包含3个1的数组
    vector<int> v2(3, 1);
    //将v1复制给v4
    vector<int> v4(v1);
    //将v2复制给v5
    vector<int> v5(v2.begin(), v2.end());
}

//API操作
void test2()
{
    vector<int> v;
    //尾部添加元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //删除元素
    auto it = v.begin();
    v.erase(it);

    //删除最后一个元素
    v.pop_back();

    //清空所有元素
    v.clear();
}

//遍历函数
void test3()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(auto& it : v)
    {
        cout << it << " ";
    }

    cout << endl;

    //返回at[pos] pos位置元素的引用
    auto it1 = v.at(2);
    cout << "at:" << it1 << endl;

    //返回首元素的引用
    auto it2 = v.front();
    cout << "front:" << it2 << endl;

    //返回尾元素的引用
    auto it3 = v.back();
    cout << "back:" << it3 << endl;

    //返回迭代器头
    auto it4 = v.begin();
    cout << "begin:" << *it4 << endl;

    //end指向最后一个元素的下一个位置，因此end-1指向最后一个元素
    auto it5 = v.end();
    cout << "end:" << *(it5 - 1) << endl;


    //反向迭代器 指向最后一个元素
    auto it6 = v.rbegin();
    cout << "rbegin:" << *it6 << endl;
    //指向第一个元素的前一个位置
    auto it7 = v.rend();
    cout << "rend:" << *(it7 - 1) << endl;

    cout << "empty:" << v.empty() << endl;
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;
    cout << "max_size:" << v.max_size() << endl;
}

void test4()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int> v2;
    v2.push_back(99);
    v2.push_back(88);

    //swap 交换两个同类型vector的数据
    v1.swap(v2);
    for(auto& it : v1)
    {
        cout << it << " ";
    }

    cout << endl;

    for(auto& it : v2)
    {
        cout << it << " ";
    }
    
    cout << "v2 size:" << v2.size() << endl;

    //清掉原vector的内容，并将vector的前2个元素设置为100
    v2.assign(5, 100);
    for(auto& it : v2)
    {
        cout << it << " ";
    }
    cout << "v2 size:" << v2.size() << endl;

    //void assign(const_iterator first,const_iterator last):向量中[first,last)中元素设置成当前向量元素
    // 这个函数原型相当于拷贝函数，把first到last的值赋值给调用者，注意区间的闭合；
    // 将区间 [first,last) 的元素赋值到当前的 vector 容器中；[)这个是左闭右开区间，表示左边的元素包括，右边的元素不包括；

    v2.assign(v1.begin(), v1.end());
    for(auto& it : v2)
    {
        cout << it << " ";
    }
    cout << "v2 size:" << v2.size() << endl;

}

//迭代器删除
//vector等顺序容器因为是分配的连续内存空间,erase操作删除一个元素之后会导致后面所有的元素都会向前移动一个位置
//这些元素的地址发生了变化，因此因此当前位置到容器末尾的所有迭代器全部失效
//解决方法：
// 利用erase返回的是下一个有效的迭代器，将这个有效迭代器重新赋给迭代器it，这样it就指向了下一个有效的元素

void test5()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(2);

    //正确做法
    for(auto it = v1.begin(); it != v1.end(); )
    {
        if (2 == *it)
        {
            it = v1.erase(it);
        }
        else
        {
            it ++;
        }
    }

    //错误做法
    // for(auto it = v1.begin(); it != v1.end(); it++)
    // {
    //     if (2 == *it)
    //     {
    //         v1.erase(it);
    //     }
    // }


    for(auto& it : v1)
    {
        cout << it << " ";
    }

}

int main()
{
    test1();
    cout << endl;
    test2();
    cout << endl;
    test3();
    cout << endl;
    test4();
    cout << endl;
    test5();
    cout << endl;

    return 0;
}