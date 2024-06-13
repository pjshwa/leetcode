class Solution {
public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int N = seats.size(), ans = 0;
    for (int i = 0; i < N; ++i) ans += abs(seats[i] - students[i]);
    return ans;
  }
};
