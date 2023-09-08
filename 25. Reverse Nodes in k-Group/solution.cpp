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
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = start;
        ListNode* curr = start->next;
        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        start->next = end;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = head;
        ListNode* start = dummy;
        int count = 0;
        while (curr != nullptr) {
            if (count++ % k == 0 && curr != head) {
                ListNode* temp = start->next;
                start->next = reverse(start->next, curr);
                start = temp;
            }
            curr = curr->next;
        }
        if (count++ % k == 0 && curr != head) {
            ListNode* temp = start->next;
            start->next = reverse(start->next, curr);
            start = temp;
        }
        return dummy->next;
    }
};