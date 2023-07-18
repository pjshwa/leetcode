using pii = pair<int, int>;
const int MAX = 1e4;

class LRUCache {
  int D[MAX + 1], L[MAX + 1], capacity, sz, it;
  queue<pii> Q;

public:
  LRUCache(int capacity) {
    this->capacity = capacity; sz = it = 0;
    memset(D, -1, sizeof(D)); memset(L, -1, sizeof(L));
  }

  void set_time(int key) {
    it++;
    Q.push({key, it}); L[key] = it;
  }

  void evict_lru() {
    while (!Q.empty()) {
      auto [k, u] = Q.front(); Q.pop();
      if (L[k] == u) {
        D[k] = L[k] = -1;
        break;
      }
    }
  }

  int get(int key) {
    if (D[key] == -1) return -1;
    set_time(key);
    return D[key];
  }

  void put(int key, int value) {
    if (D[key] == -1) {
      if (sz == capacity) evict_lru();
      else sz++;
    }
    set_time(key);
    D[key] = value;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
