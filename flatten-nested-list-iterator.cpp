#include <iostream>
#include <vector>

using namespace std;

/**
 * NestedInteger 类定义。在 LeetCode 中这是预定义的接口。
 * 为了本地可运行，我们需要提供一个简单的实现。
 */
class NestedInteger
{
private:
    int val;
    vector<NestedInteger> list;
    bool is_integer;

public:
    // 构造函数：单整数
    NestedInteger(int v) : val(v), is_integer(true) {}
    // 构造函数：嵌套列表
    NestedInteger(vector<NestedInteger> l) : list(l), is_integer(false) {}

    bool isInteger() const { return is_integer; }
    int getInteger() const { return val; }
    const vector<NestedInteger> &getList() const { return list; }
};

/**
 * 扁平化嵌套列表迭代器
 * 思路：在构造时通过 DFS 递归遍历整个嵌套列表，将所有整数拉平存入一个 vector 中。
 */
class NestedIterator
{
private:
    vector<int> vals;          // 存储拉平后的所有整数
    vector<int>::iterator cur; // 当前迭代到的位置指针

    // 深度优先搜索 (DFS)：递归处理 NestedInteger
    void dfs(const vector<NestedInteger> &nestedList)
    {
        for (const auto &nest : nestedList)
        {
            if (nest.isInteger())
            {
                // 如果是单纯的整数，直接存入
                vals.push_back(nest.getInteger());
            }
            else
            {
                // 如果是列表，递归处理子列表
                dfs(nest.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        // 1. 初始化时就将整个结构“拉平”
        dfs(nestedList);
        // 2. 将迭代器指向起始位置
        cur = vals.begin();
    }

    // 返回下一个整数值，并移动指针
    int next()
    {
        return *cur++;
    }

    // 判断是否还有下一个元素
    bool hasNext()
    {
        return cur != vals.end();
    }
};

/**
 * 主函数：用于本地测试
 */
int main()
{
    // 构造测试数据: [[1,1],2,[1,1]]
    NestedInteger ni1(1);
    NestedInteger ni2(1);
    vector<NestedInteger> list1 = {ni1, ni2};
    NestedInteger nested1(list1);

    NestedInteger nested2(2);

    vector<NestedInteger> list3 = {ni1, ni2};
    NestedInteger nested3(list3);

    vector<NestedInteger> fullList = {nested1, nested2, nested3};

    cout << "Input: [[1,1],2,[1,1]]" << endl;
    cout << "Flattened Result: ";

    // 测试迭代器
    NestedIterator it(fullList);
    while (it.hasNext())
    {
        cout << it.next() << " ";
    }
    cout << endl;

    return 0;
}
