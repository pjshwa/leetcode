const int MAX = 1e5;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

class LFUCache {
  int size, capacity, ops_count;
  priority_queue<tii, vector<tii>, greater<tii>> pq;
  int table[MAX + 1], use_count[MAX + 1];

public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
    ops_count = 0;

    for (int i = 0; i <= MAX; i++) {
      table[i] = -1;
      use_count[i] = 0;
    }
  }

  void update_use_count(int key) {
    use_count[key]++;
    pq.push({use_count[key], ops_count++, key});
  }

  int get(int key) {
    int ret = table[key];
    if (ret != -1) update_use_count(key);
    return ret;
  }
  
  void put(int key, int value) {
    if (capacity == 0) return;

    if (table[key] == -1) {
      if (size == capacity) {
        while (!pq.empty()) {
          auto [c, _, k] = pq.top(); pq.pop();
          if (c == use_count[k]) {
            use_count[k] = 0;
            table[k] = -1;
            break;
          }
        }
      }
      else size++;
      use_count[key] = 0;
    }

    table[key] = value;
    update_use_count(key);
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 