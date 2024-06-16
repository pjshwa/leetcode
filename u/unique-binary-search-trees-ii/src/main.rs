use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  fn dfs(start: i32, end: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
    let mut res = vec![];
    if start > end {
      res.push(None);
      return res;
    }

    for i in start..=end {
      let left = Self::dfs(start, i - 1);
      let right = Self::dfs(i + 1, end);

      for l in &left {
        for r in &right {
          let mut node = TreeNode::new(i);
          node.left = l.clone();
          node.right = r.clone();
          res.push(Some(Rc::new(RefCell::new(node))));
        }
      }
    }
    res
  }

  pub fn generate_trees(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
    Self::dfs(1, n)
  }
}

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}

struct Solution;
fn main() {
  assert_eq!(
    Solution::generate_trees(3),
    vec![
      Some(Rc::new(RefCell::new(TreeNode {
        val: 1,
        left: None,
        right: Some(Rc::new(RefCell::new(TreeNode {
          val: 2,
          left: None,
          right: Some(Rc::new(RefCell::new(TreeNode::new(3)))),
        }))),
      }))),
      Some(Rc::new(RefCell::new(TreeNode {
        val: 1,
        left: None,
        right: Some(Rc::new(RefCell::new(TreeNode {
          val: 3,
          left: Some(Rc::new(RefCell::new(TreeNode::new(2)))),
          right: None,
        }))),
      }))),
      Some(Rc::new(RefCell::new(TreeNode {
        val: 2,
        left: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
        right: Some(Rc::new(RefCell::new(TreeNode::new(3)))),
      }))),
      Some(Rc::new(RefCell::new(TreeNode {
        val: 3,
        left: Some(Rc::new(RefCell::new(TreeNode {
          val: 1,
          left: None,
          right: Some(Rc::new(RefCell::new(TreeNode::new(2)))),
        }))),
        right: None,
      }))),
      Some(Rc::new(RefCell::new(TreeNode {
        val: 3,
        left: Some(Rc::new(RefCell::new(TreeNode {
          val: 2,
          left: Some(Rc::new(RefCell::new(TreeNode::new(1)))),
          right: None,
        }))),
        right: None,
      }))),
    ]
  );
  assert_eq!(Solution::generate_trees(1), vec![Some(Rc::new(RefCell::new(TreeNode::new(1))))]);
  println!("OK");
}
