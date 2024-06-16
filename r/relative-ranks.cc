class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& score) {
    vector<tuple<int, int, string>> A; int N = score.size();
    for (int i = 0; i < N; ++i) A.push_back(make_tuple(score[i], i, ""));
    sort(A.begin(), A.end(), greater<>());

    vector<string> pnames = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    for (int i = 0; i < N; ++i) {
      if (i < 3) get<2>(A[i]) = pnames[i];
      else get<2>(A[i]) = to_string(i + 1);
    }
    sort(A.begin(), A.end(), [](auto& a, auto& b) { return get<1>(a) < get<1>(b); });

    vector<string> res(N);
    for (int i = 0; i < N; ++i) res[i] = get<2>(A[i]);
    return res;
  }
};
