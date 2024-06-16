use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
  fn dfs(
    node: Option<Rc<RefCell<TreeNode>>>,
    target_sum: i32,
    ans: &mut Vec<Vec<i32>>,
    cur: &mut Vec<i32>,
  ) {
    if let Some(n) = node {
      let n = n.borrow();
      cur.push(n.val);
      if n.left.is_none() && n.right.is_none() && n.val == target_sum {
        ans.push(cur.clone());
      }
      Solution::dfs(n.left.clone(), target_sum - n.val, ans, cur);
      Solution::dfs(n.right.clone(), target_sum - n.val, ans, cur);
      cur.pop();
    }
  }

  pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> Vec<Vec<i32>> {
    let mut ans = vec![];
    let mut cur = vec![];
    Self::dfs(root, target_sum, &mut ans, &mut cur);
    ans
  }
}
