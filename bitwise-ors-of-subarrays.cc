class Solution {
public:
  int subarrayBitwiseORs(vector<int>& arr) {
    int N = arr.size();

    int P[N + 1][32]; memset(P, 0, sizeof(P));
    for (int i = 1; i <= N; ++i) {
      int num = arr[i - 1];
      for (int j = 0; j < 30; ++j) {
        P[i][j] = P[i - 1][j];
        if (num & (1 << j)) P[i][j] += 1;
      }
    }

    vector<int> ans;
    for (int i = 1; i <= N; ++i) {
      int last = arr[i - 1], li = i;
      ans.push_back(last);

      while (1) {
        int l = li, r = N + 1;
        while (l < r) {
          int mid = (l + r) / 2;

          int num = 0;
          for (int j = 0; j < 30; ++j) {
            if (P[mid][j] - P[i - 1][j] > 0) num |= (1 << j);
          }

          if (num <= last) l = mid + 1;
          else r = mid;
        }
        if (l == N + 1) break;

        last |= arr[l - 1];
        ans.push_back(last);
        li = l;
      }
    }

    return unordered_set<int>(ans.begin(), ans.end()).size();
  }
};
