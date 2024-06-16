class Solution {
public:
  int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    int C[sideLength][sideLength];
    memset(C, 0, sizeof(C));

    // Count occurences of each slot in matrix M on board
    for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) {
      C[i % sideLength][j % sideLength] += 1;
    }

    // greedily fill 1 on M, from slots that appears the most on board
    priority_queue<int> pq;
    for (int i = 0; i < sideLength; i++) for (int j = 0; j < sideLength; j++) {
      pq.push(C[i][j]);
    }

    int ans = 0;
    while (maxOnes--) {
      ans += pq.top();
      pq.pop();
    }
    return ans;
  }
};
