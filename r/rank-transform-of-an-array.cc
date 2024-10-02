class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<tuple<int, int, int>> with_index; int N = arr.size();
    for (int i = 0; i < N; ++i) with_index.emplace_back(arr[i], i, -1);
    sort(with_index.begin(), with_index.end());

    int rank = 1;
    for (int i = 0; i < N; ++i) {
      auto& [ce, ci, cr] = with_index[i];
      if (i > 0) {
        auto& [pe, pi, pr] = with_index[i - 1];
        if (ce > pe) ++rank;
      }
      cr = rank;
    }

    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
      auto& [ce, ci, cr] = with_index[i];
      result[ci] = cr;
    }
    return result;
  }
};
