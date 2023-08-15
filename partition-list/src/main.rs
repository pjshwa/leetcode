// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

impl Solution {
  pub fn partition(head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
    let (mut head, mut left, mut right) = (head, None, None);
    let (mut left_tail, mut right_tail) = (&mut left, &mut right);
    while let Some(mut node) = head {
      head = node.next.take();
      if node.val < x {
        *left_tail = Some(node);
        left_tail = &mut left_tail.as_mut().unwrap().next;
      }
      else {
        *right_tail = Some(node);
        right_tail = &mut right_tail.as_mut().unwrap().next;
      }
    }
    *left_tail = right;
    left
  }
}

struct Solution;
fn main() {
  assert_eq!(Solution::partition(
    Some(Box::new(ListNode {
      val: 1,
      next: Some(Box::new(ListNode {
        val: 4,
        next: Some(Box::new(ListNode {
          val: 3,
          next: Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode {
              val: 5,
              next: Some(Box::new(ListNode {
                val: 2,
                next: None,
              })),
            })),
          })),
        })),
      })),
    })), 3),
    Some(Box::new(ListNode {
      val: 1,
      next: Some(Box::new(ListNode {
        val: 2,
        next: Some(Box::new(ListNode {
          val: 2,
          next: Some(Box::new(ListNode {
            val: 4,
            next: Some(Box::new(ListNode {
              val: 3,
              next: Some(Box::new(ListNode {
                val: 5,
                next: None,
              })),
            })),
          })),
        })),
      })),
    }))
  );
  assert_eq!(Solution::partition(
    Some(Box::new(ListNode {
      val: 2,
      next: Some(Box::new(ListNode {
        val: 1,
        next: None,
      })),
    })), 2),
    Some(Box::new(ListNode {
      val: 1,
      next: Some(Box::new(ListNode {
        val: 2,
        next: None,
      })),
    }))
  );
  println!("OK");
}
