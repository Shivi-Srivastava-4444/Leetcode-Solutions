class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;

        while (true) {
            ListNode end = prev;
            for (int i = 0; i < k && end != null; i++) end = end.next;
            if (end == null) break;

            ListNode curr = prev.next;
            ListNode next = curr.next;

            for (int i = 1; i < k; i++) {
                curr.next = next.next;
                next.next = prev.next;
                prev.next = next;
                next = curr.next;
            }

            prev = curr;
        }

        return dummy.next;
    }
}