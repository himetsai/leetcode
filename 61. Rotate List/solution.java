class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return head;
        ListNode ind = head;
        int cnt = 0;
        Stack<ListNode> s = new Stack<ListNode>();
        while (ind != null) {
            cnt++;
            s.push(ind);
            ind = ind.next;
        }
        k %= cnt;
        if (k == 0) return head;
        s.peek().next = head;
        while (--k > 0) {
            s.pop();
        }
        ind = s.pop();
        if (s.size() > 0) s.peek().next = null;
        return ind;
    }
}