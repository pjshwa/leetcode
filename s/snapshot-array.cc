const int MAX = 5e4;

class SnapshotArray {
  vector<pair<int, int>> P[MAX];
  int snap_id;

public:
  SnapshotArray(int length) {
    snap_id = 0;
  }

  void set(int index, int val) {
    P[index].push_back({snap_id, val});
  }

  int snap() {
    return snap_id++;
  }

  int get(int index, int snap_id) {
    auto it = upper_bound(P[index].begin(), P[index].end(), make_pair(snap_id, INT_MAX));
    if (it == P[index].begin()) return 0;
    return prev(it)->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
