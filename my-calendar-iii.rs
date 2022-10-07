use std::collections::{BTreeSet, BTreeMap};

struct MyCalendarThree {
  t: BTreeMap<i32, i32>,
  s: BTreeSet<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendarThree {
  fn new() -> Self {
    MyCalendarThree {
      t: BTreeMap::new(),
      s: BTreeSet::new(),
    }
  }
  
  fn book(&mut self, start: i32, end: i32) -> i32 {
    self.s.insert(start); self.s.insert(end);
    *self.t.entry(start).or_insert(0) += 1;
    *self.t.entry(end).or_insert(0) -= 1;

    let (mut ret, mut dt) = (0, 0);
    for x in self.s.iter() {
      dt += self.t[x];
      ret = ret.max(dt);
    }
    ret
  }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * let obj = MyCalendarThree::new();
 * let ret_1: i32 = obj.book(start, end);
 */
