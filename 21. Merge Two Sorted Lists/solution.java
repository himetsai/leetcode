/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ArrayList<ListNode> l = new ArrayList<ListNode>();
        ListNode cur = head;
        while (cur != null) {
            l.add(cur);
            cur = cur.next;
        }
        if (n == l.size()) return l.get(0).next;
        l.get(l.size() - n - 1).next = l.get(l.size() - n - 1).next.next;
        return head;
    }
}