class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int maxH = 0;
        for (auto& row : heights) maxH = max(maxH, *max_element(row.begin(),row.end()));

        int left = 0, right = maxH;
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canReach(heights, m, n, mid)) {
                result = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return result;
    }

    bool canReach(const vector<vector<int>>& heights, int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return canReach(heights, m, n, 0, 0, k, visited);
    }

    bool canReach(const vector<vector<int>>& heights, int m, int n, int x, int y, int minDiff, vector<vector<bool>>& visited) {
        if (x == m - 1 && y == n - 1) return true;
        if (visited[x][y]) return false;
        visited[x][y] = true;

        if (x - 1 >= 0 && abs(heights[x][y] - heights[x - 1][y]) <= minDiff) if (canReach(heights, m, n, x - 1, y, minDiff, visited)) return true;
        if (y + 1 < n &&  abs(heights[x][y] - heights[x][y + 1]) <= minDiff) if (canReach(heights, m, n, x, y + 1, minDiff, visited)) return true;
        if (x + 1 < m &&  abs(heights[x][y] - heights[x + 1][y]) <= minDiff) if (canReach(heights, m, n, x + 1, y, minDiff, visited)) return true;
        if (y - 1 >= 0 && abs(heights[x][y] - heights[x][y - 1]) <= minDiff) if (canReach(heights, m, n, x, y - 1, minDiff, visited)) return true;

        return false;
    }
};
