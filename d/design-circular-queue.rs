struct MyCircularQueue {
  a: Vec<i32>,
  head: usize,
  tail: usize,
  size: usize,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCircularQueue {
  fn new(k: i32) -> Self {
    Self {
      a: vec![0; k as usize],
      head: 0,
      tail: 0,
      size: 0,
    }
  }
  
  fn en_queue(&mut self, value: i32) -> bool {
    if self.is_full() { return false; }

    self.a[self.tail] = value;
    self.tail = (self.tail + 1) % self.a.len();
    self.size += 1;
    true
  }

  fn de_queue(&mut self) -> bool {
    if self.is_empty() { return false; }

    self.head = (self.head + 1) % self.a.len();
    self.size -= 1;
    true
  }
  
  fn front(&self) -> i32 {
    if self.is_empty() { return -1; }
    self.a[self.head]
  }
  
  fn rear(&self) -> i32 {
    if self.is_empty() { return -1; }
    self.a[(self.tail + self.a.len() - 1) % self.a.len()]
  }
  
  fn is_empty(&self) -> bool {
    self.size == 0
  }
  
  fn is_full(&self) -> bool {
    self.size == self.a.len()
  }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * let obj = MyCircularQueue::new(k);
 * let ret_1: bool = obj.en_queue(value);
 * let ret_2: bool = obj.de_queue();
 * let ret_3: i32 = obj.front();
 * let ret_4: i32 = obj.rear();
 * let ret_5: bool = obj.is_empty();
 * let ret_6: bool = obj.is_full();
 */
