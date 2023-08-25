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

    void recur(vector<ListNode*>& lists, ListNode* curr) {
        int mval = INT_MAX;
        int mn = -1;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == nullptr || lists[i]->val >= mval) continue;
            mval = lists[i]->val;
            mn = i;
        }
        if (mn == -1) return;            
        curr->next = lists[mn];
        lists[mn] = lists[mn]->next;
        recur(lists, curr->next);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        recur(lists, dummy);
        return dummy->next;
    }
};