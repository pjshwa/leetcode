class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rsz = rowSum.size(), csz = colSum.size();

        vector<vector<int>> ans;
        for (int i = 0; i < rsz; i++) {
            vector<int> row(csz, 0);
            for (int j = 0; j < csz; j++) {
                int cv = min(rowSum[i], colSum[j]);
                row[j] = cv;
                rowSum[i] -= cv;
                colSum[j] -= cv;
            }
            ans.push_back(row);
        }

        return ans;
    }
};
