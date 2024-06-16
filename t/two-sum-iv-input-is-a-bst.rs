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
  reverse: bool,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
  fn new(root: Option<Rc<RefCell<TreeNode>>>, reverse: bool) -> Self {
    let mut stack = vec![];
    let mut node = root;

    if reverse {
      while let Some(n) = node {
        stack.push(n.clone());
        node = n.borrow().right.clone();
      }
    }
    else {
      while let Some(n) = node {
        stack.push(n.clone());
        node = n.borrow().left.clone();
      }
    }
    BSTIterator { stack, reverse }
  }

  fn next(&mut self) -> i32 {
    let node = self.stack.pop().unwrap();

    if self.reverse {
      let mut n = node.borrow().left.clone();
      let ret = node.borrow().val;

      while let Some(x) = n {
        self.stack.push(x.clone());
        n = x.borrow().right.clone();
      }

      ret
    }
    else {
      let mut n = node.borrow().right.clone();
      let ret = node.borrow().val;

      while let Some(x) = n {
        self.stack.push(x.clone());
        n = x.borrow().left.clone();
      }

      ret
    }
  }
  
  fn has_next(&self) -> bool {
    !self.stack.is_empty()
  }
}

impl Solution {
  pub fn find_target(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
    let mut left = BSTIterator::new(root.clone(), false);
    let mut right = BSTIterator::new(root.clone(), true);

    let mut l = left.next();
    let mut r = right.next();

    while l < r {
      if l + r == k { return true; }
      else if l + r < k { l = left.next(); }
      else { r = right.next(); }
    }

    false
  }
}
