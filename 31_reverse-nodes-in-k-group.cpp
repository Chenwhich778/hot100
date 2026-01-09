#include <iostream>
#include <vector>

// Definition for singly-linked list.
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k <= 1 || head == nullptr)
            return head;

        // 使用最简单的思路：每次收集 k 个节点到一个临时数组中，
        // 然后把它们的 next 指针反向连接，再接回主链表。
        // 空间复杂度 O(k)，代码简单易懂（适合初学者）。
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy; // prev 指向待处理段的前驱

        while (true)
        {
            // 检查是否还有 k 个节点
            ListNode *node = prev;
            for (int i = 0; i < k && node; ++i)
                node = node->next;
            if (!node)
                break; // 不足 k 个，结束

            // 收集 k 个节点
            std::vector<ListNode *> group;
            ListNode *cur = prev->next;
            for (int i = 0; i < k; ++i)
            {
                group.push_back(cur);
                cur = cur->next;
            }

            // 反向连接 group 中的节点
            for (int i = (int)group.size() - 1; i > 0; --i)
            {
                group[i]->next = group[i - 1];
            }

            // 将反转后的段接回主链表
            group[0]->next = cur;      // 原来的第一个节点现在是段尾，指向后继
            prev->next = group.back(); // prev 连接到新的段头

            // prev 前进到段尾，为下一段做准备
            prev = group[0];
        }

        return dummy.next;
    }
};

// 辅助函数：创建链表
ListNode *createList(const std::vector<int> &arr)
{
    ListNode dummy(0);
    ListNode *curr = &dummy;
    for (int x : arr)
    {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution sol;
    std::vector<int> data = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode *head = createList(data);
    std::cout << "Original: ";
    printList(head);

    ListNode *res = sol.reverseKGroup(head, k);
    std::cout << "Reversed (k=" << k << "): ";
    printList(res);

    return 0;
}
