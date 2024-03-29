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
  pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
    let mut sz = 0;
    {
      let mut cur = &head;
      while let Some(node) = cur {
        sz += 1;
        cur = &node.next;
      }
    }

    if n == sz {
      return head.unwrap().next;
    }

    let mut dummy = Some(Box::new(ListNode {
      val: 0,
      next: head,
    }));;
    
    let mut cur = &mut dummy;
    for _ in 0..(sz - n) {
      cur = &mut cur.as_mut().unwrap().next;
    }

    cur.as_mut().unwrap().next = cur.as_mut().unwrap().next.as_mut().unwrap().next.take();
    dummy.unwrap().next
  }
}
