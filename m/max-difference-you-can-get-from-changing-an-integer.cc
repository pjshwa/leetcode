class Solution {
public:
  int maxDiff(int num) {
    string nums_s = to_string(num);
    int nums_min = num, nums_max = num;
    for (char from = '0'; from <= '9'; ++from) for (char to = '0'; to <= '9'; ++to) {
      string nums_e = nums_s;
      for (char &c : nums_e) if (c == from) c = to;
      if (nums_e[0] == '0') continue;
      nums_min = min(nums_min, stoi(nums_e));
      nums_max = max(nums_max, stoi(nums_e));
    }
    return nums_max - nums_min;
  }
};
