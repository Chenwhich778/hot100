/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;

        // fast 先走 n 步
        for (int i = 0; i < n; ++i)
        {
            if (fast->next)
                fast = fast->next;
            else
                return head; // n 超过长度，直接返回原链表（或按题目保证 n 合法可省略）
        }

        // 同时走，直到 fast 到达末尾
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next 是要删除的节点
        ListNode *toDelete = slow->next;
        slow->next = toDelete->next;
        // 可选：delete toDelete;
        return dummy.next;
    }
};