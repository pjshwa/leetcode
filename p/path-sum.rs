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

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
  fn dfs(
    node: Option<Rc<RefCell<TreeNode>>>,
    running_sum: i32,
    target_sum: i32
  ) -> bool {
    let mut ret = false;

    if let Some(n) = node {
      let n = n.borrow();
      if n.left.is_none() && n.right.is_none() && running_sum + n.val == target_sum {
        ret = true;
      }

      ret = ret || Self::dfs(n.left.clone(), running_sum + n.val, target_sum);
      ret = ret || Self::dfs(n.right.clone(), running_sum + n.val, target_sum);
    }
    ret
  }

  pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> bool {
    Self::dfs(root, 0, target_sum)
  }
}
