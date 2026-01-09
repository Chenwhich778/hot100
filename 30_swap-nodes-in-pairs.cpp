// 可独立运行的交换相邻节点实现（递归），并增加调试输出以观察递归流程
#include <iostream>
#include <vector>

// Definition for singly-linked list node (可直接用于本地测试)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // 递归交换相邻节点：
    // 思路：如果链表长度小于2（空或只有1个节点），返回 head（无法交换）——这是递归的终止条件。
    // 否则：
    // - newHead 指向 head->next（第二个节点），它将成为当前子链表的头
    // - 递归地对 newHead->next（从第三个节点开始的子链表）执行 swapPairs，得到子链表交换后的头
    // - 把 head 接到递归结果之后，再把 newHead->next 指向 head，完成当前两节点的交换
    // 通过在关键位置打印，可以观察递归函数的进入、递归调用和返回时的行为（有助于调试）
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
        {
            std::cout << "swapPairs called with head=nullptr -> return nullptr" << std::endl;
            return head;
        }
        if (head->next == nullptr)
        {
            std::cout << "swapPairs called with single node (val=" << head->val << ") -> return same node" << std::endl;
            return head;
        }

        // 打印当前调用信息（显示值和地址，地址用于辨别同一节点）
        std::cout << "swapPairs called: head->val=" << head->val << " addr=" << head << std::endl;

        ListNode *newHead = head->next;    // 第二个节点
        ListNode *nextSub = newHead->next; // 从第三个节点开始的子链表

        std::cout << "  will recurse on nextSub addr=" << nextSub << (nextSub ? (std::string(" val=") + std::to_string(nextSub->val)) : std::string("")) << std::endl;

        // 递归：处理剩余链表并返回交换后的头
        ListNode *rec = swapPairs(nextSub);

        std::cout << "  returned from recursion: rec addr=" << rec << std::endl;

        // 连接：head 的 next 指向递归结果（rec），newHead 指向 head，完成当前两节点交换
        head->next = rec;
        newHead->next = head;

        std::cout << "  swapped pair -> newHead val=" << newHead->val << " addr=" << newHead << " ; head val=" << head->val << " addr=" << head << std::endl;

        return newHead;
    }
};

// --------- 辅助函数：构造、打印与销毁链表（便于本地测试/调试） ---------
ListNode *make_list(const std::vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *cur = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

void print_list(ListNode *head)
{
    ListNode *cur = head;
    while (cur)
    {
        std::cout << cur->val;
        if (cur->next)
            std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void delete_list(ListNode *head)
{
    while (head)
    {
        ListNode *tmp = head->next;
        delete head;
        head = tmp;
    }
}

// --------- main：用于观察递归流程的示例运行 ---------
int main()
{
    // 测试用例：你可以修改这些值观察不同输入下的递归行为
    std::vector<int> vals = {1, 2, 3, 4, 5};
    ListNode *head = make_list(vals);

    std::cout << "Original list: ";
    print_list(head);

    Solution sol;
    std::cout << "\nCalling swapPairs(head) to observe recursion flow..." << std::endl;
    ListNode *res = sol.swapPairs(head);

    std::cout << "\nResulting list: ";
    print_list(res);

    delete_list(res);
    return 0;
}