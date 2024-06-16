class Solution {
public:
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    sort(restrictions.begin(), restrictions.end());
    int Z = restrictions.size();
    if (Z == 0) return n - 1;

    {
      int last_id = 1, last_height = 0;
      for (int i = 0; i < Z; ++i) {
        int id = restrictions[i][0], height = restrictions[i][1];
        height = min(height, last_height + id - last_id);
        restrictions[i][1] = height;

        last_id = id; last_height = height;
      }
    }
    {
      int last_id = restrictions[Z - 1][0], last_height = restrictions[Z - 1][1];
      for (int i = Z - 2; i >= 0; --i) {
        int id = restrictions[i][0], height = restrictions[i][1];
        height = min(height, last_height + last_id - id);
        restrictions[i][1] = height;

        last_id = id; last_height = height;
      }
    }

    int ans = 0;
    {
      int last_id = 1, last_height = 0;
      for (int i = 0; i < Z; ++i) {
        int id = restrictions[i][0], height = restrictions[i][1];

        int diff_id = id - last_id, diff_height = height - last_height;
        assert(diff_id >= abs(diff_height));

        int base = max(height, last_height);
        int leeway = diff_id - abs(diff_height);
        ans = max(ans, base + leeway / 2);

        last_id = id; last_height = height;
      }

      ans = max(ans, last_height + n - last_id);
    }

    return ans;
  }
};
