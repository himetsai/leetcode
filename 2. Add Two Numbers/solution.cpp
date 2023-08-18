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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        while (h1->next != nullptr && h2->next != nullptr) {
            int sum = h1->val + h2->val;
            if (carry) sum++;
            if (sum > 9) carry = true;
            else carry = false;
            h1->val = sum % 10;
            h2->val = sum % 10;
            h1 = h1->next;
            h2 = h2->next;
        }
        if (h2->next == nullptr) {
            int sum = h1->val + h2->val;
            if (carry) sum++;
            if (sum > 9) carry = true;
            else carry = false;
            h1->val = sum % 10;
            while (carry) {
                if (h1->next == nullptr) {
                    h1->next = new ListNode(1);
                    break;
                }
                if (h1->next->val != 9) {
                    carry = false;
                    h1->next->val++;
                }
                else h1->next->val = 0;
                h1 = h1->next;
            }
            return l1;
        }
        else {
            int sum = h1->val + h2->val;
            if (carry) sum++;
            if (sum > 9) carry = true;
            else carry = false;
            h2->val = sum % 10;
            while (carry) {
                if (h2->next == nullptr) {
                    h2->next = new ListNode(1);
                    break;
                }
                if (h2->next->val != 9) {
                    carry = false;
                    h2->next->val++;
                }
                else h2->next->val = 0;
                h2 = h2->next;
            }
            return l2;
        }
    }
};