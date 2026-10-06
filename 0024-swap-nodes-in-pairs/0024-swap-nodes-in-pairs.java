class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode cur = dummy;

        while (cur.next != null && cur.next.next != null) {
            ListNode a = cur.next;
            ListNode b = a.next;

            a.next = b.next;
            b.next = a;
            cur.next = b;

            cur = a;
        }

        return dummy.next;
    }
}