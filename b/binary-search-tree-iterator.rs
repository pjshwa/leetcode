// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::rc::Rc;
use std::cell::RefCell;

struct BSTIterator {
  stack: Vec<Rc<RefCell<TreeNode>>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
  fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
    let mut stack = vec![];
    let mut node = root;
    while let Some(n) = node {
      stack.push(n.clone());
      node = n.borrow().left.clone();
    }
    BSTIterator { stack }
  }

  fn next(&mut self) -> i32 {
    let node = self.stack.pop().unwrap();
    let mut n = node.borrow().right.clone();
    let ret = node.borrow().val.clone();

    while let Some(x) = n {
      self.stack.push(x.clone());
      n = x.borrow().left.clone();
    }

    ret
  }
  
  fn has_next(&self) -> bool {
    !self.stack.is_empty()
  }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */
