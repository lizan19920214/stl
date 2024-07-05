/**
 * map和multimap
 * #include<map>
 * 
 * map的键值key不可重复，而multimap可以，也正是由于这种区别，map支持[]运算符，multimap不支持[]运算符。在用法上没什么区别。
 * 
 * map 由红黑树实现，其元素都是 “键值/实值” 所形成的一个对组（key/value pairs）。每个元素有一个键，
 *      是排序准则的基础。每一个键只能出现一次，不允许重复。
 * map主要用于资料一对一映射的情况，map 内部自建一颗红黑树，这颗树具有对数据自动排序的功能，
 *      所以在 map 内部所有的数据都是有序的。比如一个班级中，每个学生的学号跟他的姓名就存在着一对一映射的关系。
*/


#include <map>
#include <iostream>

using namespace std;


// 容器大小：mp.size();
// 容器最大容量：mp.max_size();
// 容器判空：mp.empty();
// 查找键 key 的元素个数：mp.count(key);

void test1()
{
	map<int,string> mp;
    //会根据key默认升序自动排序
	mp.insert(pair<int, string>{ 3, "老王" });
	mp.insert({ 2, "李四" });
	mp.insert({ 1, "张三" });
    //使用std::make_pair自动创建，不用指定类型
    mp.insert(make_pair(4, "老张"));
// 1 张三
// 2 李四
// 3 老王
// 4 老张

	cout << mp.size() << endl;
	cout << mp.max_size() << endl;
	cout << mp.count(2) << endl; //关键字2出现的次数
	if (mp.empty())
    {
		cout << "元素为空" << endl;
    }
    else
    {
		cout << "元素不为空" << endl;
    }
    cout << "map info:" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;

}

// 删除键值为 keyValue 的元素：mp.pop_back(const T& keyValue);
// 删除迭代器所指的元素：mp.erase(iterator it);
// 删除区间[first,last]之间的所有元素：mp.erase(iterator first, iterator last);
// 清空所有元素：mp.clear();
// 查找键 key 是否存在，若存在，返回该键的元素的迭代器；若不存在，返回 map.end()： mp.find(key);

void test2()
{
	map<int,string> mp;
	// 在容器中插入元素
	mp.insert({ 1, "张三" });
	mp.insert({ 2, "李四" });
	mp.insert({ 4, "王五" });
	mp.insert({ 5, "小明" });
	// 任意位置插入一个元素
	mp.insert(mp.begin(), pair<int, string>{ 3, "隔壁老王" }); // 会自动排序

	// 通过find(key)查找键值
	cout << mp.find(1)->first << endl; // 输出：1
	cout << mp.find(2)->second << endl; // 输出：李四

	// 删除键值为keyValue的元素
	mp.erase(2);
	// 删除迭代器所指的元素
	mp.erase(mp.begin());
	// 删除区间[first,last]之间的所有元素
	mp.erase(mp.begin(), ++mp.begin());

	// 遍历显示
	map<int, string>::iterator it = mp.begin();
	for (it = mp.begin(); it != mp.end(); it++)
		cout << it->first << " " << it->second << endl;

	// 清空容器内的所有元素
	mp.clear();

	// 判断map是否为空
    if (mp.empty())
        cout << "元素为空" << endl; // 输出：元素为空

}

//迭代器失效
// 对于关联容器(如 map, set,multimap,multiset)，删除当前的 iterator，仅仅会使当前的 iterator 失效，只要在 erase 时，
//      递增当前 iterator 即可。这是因为 map 之类的容器，使用了红黑树来实现，插入、删除一个结点不会对其他结点造成影响。
//      erase 迭代器只是被删元素的迭代器失效，但是返回值为 void，所以要采用erase(iter++)的方式删除迭代器。
void test3()
{
	map<int,string> mp;
	// 在容器中插入元素
	mp.insert({ 1, "张三" });
	mp.insert({ 2, "李四" });
	mp.insert({ 4, "王五" });
	mp.insert({ 5, "小明" });

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->first == 2)
        {
              // mp.erase(it); //迭代器失效
            //这句话分三步走，先把 iter 传值到 erase 里面，然后 iter 自增，然后执行 erase，所以 iter 在失效前已经自增了
            mp.erase(it++); //迭代器不失效
        }
        else
        {
            it ++;
        }
    }

    cout << "iteration after erase:" << endl;

    map<int, string>::iterator it = mp.begin();
	for (it = mp.begin(); it != mp.end(); it++)
		cout << it->first << " " << it->second << endl;

}

// 交换两个同类型容器的元素：swap(map&, map&);或mp.swap(map&);
// 
void test4()
{
    map<int,string> mp1;
	// 在容器中插入元素
	mp1[1] = "张三";
	mp1[2] = "李四";
	mp1[3] = "隔壁老王";

	map<int, string> mp2;
	// 在容器中插入元素
	mp2[1] = "tom";
	mp2[2] = "jerry";
	mp2[3] = "mariy";

	// 交换两个容器的元素
	mp2.swap(mp1);

	// 通过iterator遍历mp1
	map<int, string>::iterator it;
	for (it = mp1.begin(); it != mp1.end(); it++)
		cout << it->second << " "; // 输出：tom jerry mariy
	cout << endl;

}

// 开始迭代器指针：mp.begin();
// 末尾迭代器指针：mp.end(); // 指向最后一个元素的下一个位置
// 指向常量的开始迭代器指针：mp.cbegin(); // 意思就是不能通过这个指针来修改所指的内容，但还是可以通过其他方式修改的，而且指针也是可以移动的。
// 指向常量的末尾迭代器指针：mp.cend();
// 反向迭代器指针，指向最后一个元素：mp.rbegin();
// 反向迭代器指针，指向第一个元素的前一个元素：mp.rend();
// 返回最后一个 key<=keyElem 元素的迭代器：mp.lower_bound(keyElem);
// 返回第一个 key>keyElem 元素的迭代器：mp.upper_bound(keyElem);
// 返回容器中 key 与 keyElem 相等的上下限的两个迭代器，这两个迭代器被放在对组（pair）中： mp.equal_range(keyElem);
void test5()
{
	map<int,string> mp;
	// 在容器中插入元素
	mp[1] = "张三";
	mp[2] = "李四";
	mp[3] = "隔壁老王";

	cout << mp.begin()->first << endl; // 输出：1
	cout << (--mp.end())->first << endl; // 输出：3
	cout << mp.cbegin()->first << endl; // 输出：1
	cout << (--mp.cend())->first << endl; // 输出：3
	cout << mp.rbegin()->first << endl; // 输出：3
	cout << (--mp.rend())->first << endl; // 输出：1
	cout << mp.lower_bound(2)->first << endl; // 输出：2
	cout << mp.upper_bound(2)->first << endl; // 输出：3
	pair<map<int, string>::iterator, map<int, string>::iterator> t_pair = mp.equal_range(2);
	cout << t_pair.first->first << endl; // 输出：2
	cout << t_pair.second->first << endl; // 输出：3
	cout << endl;

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