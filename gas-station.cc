class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int psum = 0, minpf = 0, n = gas.size();
    for (int i = 0; i < n; i++) {
      psum += gas[i] - cost[i];
      minpf = min(minpf, psum);
    }
    if (psum < 0) return -1;

    for (int i = 0; i < n; i++) {
      if (minpf == 0) return i;
      minpf -= gas[i] - cost[i];
    }
    return -1;
  }
};
