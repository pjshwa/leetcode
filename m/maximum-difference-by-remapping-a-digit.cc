class Solution {
public:
  int minMaxDifference(int num) {
    string nums_s = to_string(num);
    int nums_min, nums_max = 0;

    {
      string nums_min_s = nums_s;
      char from = nums_s[0], to = '0';
      for (char& c : nums_min_s) {
        if (c == from) c = to;
      }
      nums_min = stoi(nums_min_s);
    }
    {
      for (char from = '0'; from <= '9'; ++from) for (char to = from + 1; to <= '9'; ++to) {
        string nums_max_s = nums_s;
        for (char& c : nums_max_s) {
          if (c == from) c = to;
        }
        nums_max = max(nums_max, stoi(nums_max_s));
      }
    }
    return nums_max - nums_min;
  }
};
