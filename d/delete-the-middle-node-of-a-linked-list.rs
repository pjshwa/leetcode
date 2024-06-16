// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
  pub fn delete_middle(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut n = 0;
    {
      let mut p = &head;
      while let Some(node) = p {
        n += 1;
        p = &node.next;
      }
    }

    let mid = n / 2;
    let mut dummy = Some(Box::new(ListNode { val: 0, next: head }));
    let mut p = &mut dummy;
    for _ in 0..mid { p = &mut p.as_mut().unwrap().next; }

    p.as_mut().unwrap().next = p.as_mut().unwrap().next.as_mut().unwrap().next.take();
    dummy.unwrap().next
  }
}
