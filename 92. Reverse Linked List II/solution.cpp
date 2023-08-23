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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 0;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while (++count < left) {
            pre = curr;
            curr = curr->next;
        }
        ListNode* start = curr;
        ListNode* prev = nullptr;
        ListNode* next;
        while (count <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        start->next = curr;
        if (pre == nullptr) head = prev;
        else pre->next = prev;
        return head;
    }
};