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

impl Solution {
  fn r(node: Option<Rc<RefCell<TreeNode>>>, val: i32, cdepth: i32, tdepth: i32) {
    if let Some(n) = node {
      if cdepth == tdepth - 1 {
        let mut n = n.borrow_mut();
        let mut l = TreeNode::new(val);
        let mut r = TreeNode::new(val);
        l.left = n.left.take();
        r.right = n.right.take();
        n.left = Some(Rc::new(RefCell::new(l)));
        n.right = Some(Rc::new(RefCell::new(r)));
      }
      else {
        let n = n.borrow();
        Self::r(n.left.clone(), val, cdepth + 1, tdepth);
        Self::r(n.right.clone(), val, cdepth + 1, tdepth);
      }
    }
  }

  pub fn add_one_row(root: Option<Rc<RefCell<TreeNode>>>, val: i32, depth: i32) -> Option<Rc<RefCell<TreeNode>>> {
    if depth == 1 {
      let mut r = TreeNode::new(val);
      r.left = root;
      Some(Rc::new(RefCell::new(r)))
    }
    else {
      Self::r(root.clone(), val, 1, depth);
      root
    }
  }
}
