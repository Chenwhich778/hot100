/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // A 指针从链表 A 的头开始走
        // B 指针从链表 B 的头开始走
        // 目标：找到两个链表“相交”的那个节点（同一个地址的节点），如果不相交则返回 nullptr
        ListNode *A = headA, *B = headB;

        // 当 A 和 B 指向同一个节点时，说明相遇了：
        // - 可能在相交点相遇
        // - 也可能都走到 nullptr（不相交）
        while (A != B)
        {
            // A 还没走到链表末尾：就继续往后走一步
            // A 走到末尾（nullptr）：就“换轨”到链表 B 的头继续走
            // 这样 A 走过的总路程 = A链长度 + B链长度
            A = A != nullptr ? A->next : headB;

            // B 同理：先走 B 链，走完了就换到 A 链
            // 这样 B 走过的总路程 = B链长度 + A链长度
            B = B != nullptr ? B->next : headA;
        }

        // 跳出循环时：
        // - 如果相交：A == B == 相交节点
        // - 如果不相交：A == B == nullptr
        return A;
    }
};