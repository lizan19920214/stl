/**
 * 
 * 原理
 *      在数据量很大时采用正常的快速排序，此时效率为O(N logN)。
 *      一旦分段后的数据量小于某个阈值，就改用插入排序，因为此时这个分段是基本有序的，这时效率可达O(N)。
 *      在递归过程中，如果递归层次过深，分割行为有恶化倾向时，它能够自动侦测出来，使用堆排序来处理，在此情况下，
 *      使其效率维持在堆排序的O(N logN)，但这又比一开始使用堆排序好。
 * 
*/
#include <iostream>
#include <algorithm>

void test1()
{
    //sort形参需要随机迭代器
    // 所谓随机迭代器可以提供在常量时间内访问容器任意位置的功能，比如指针和vector的迭代器。
    int arr[] = { 1, 3, 2, 5, 4, 6 };
    std::sort(arr, arr + 6);
    /**
     * 哪些容器能使用sort的算法
     * 1、序列式容器：vector, list, deque
     *      序列式容器中，vector和deque拥有随机访问迭代器，因此它们可以使用std::sort排序。
     *      而list只有双向迭代器，所以它无法使用std::sort，但好在它提供了自己的sort成员函数。(list.sort()默认升序)
     * 2、关联式容器：set, map, multiset, multimap
     *      对于所有的关联式容器如map和set，由于它们底层是用红黑树实现，因此已经具有了自动排序功能，
     *      不需要std::sort。至于配置器容器，因为它们对出口和入口做了限制，比如说先进先出，先进后出，因此它们也禁止使用排序功能。
     * 3、配置器容器：queue, stack, priority_queue
     * 4、无序关联式容器：unordered_set, unordered_map, unordered_multiset, unordered_multimap。这些是在C++ 11中引入的。
     *      由于std::sort算法内部需要去取中间位置元素的值，为了能够让访问元素更迅速，因此它只接受有随机访问迭代器的容器。
     *      对于所有的无序关联式容器而言，它们只有前向迭代器，因而无法调用std::sort。但我认为更为重要的是，
     *      从它们名称来看，本身就是无序的，它们底层是用哈希表来实现。它们的作用像是字典，
     *      为的是根据key快速访问对应的元素，所以对其排序是没有意义的。
     * 
     * 因此可以使用的容器有：数组，vector,deque,queue, stack,priority_queue
    */
}

int main()
{
    test1();
    return 0;
}