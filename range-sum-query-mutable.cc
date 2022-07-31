class NumArray {
  vector<int> nums, blocks;
  int bsz;
public:
  NumArray(vector<int>& nums) {
    this->nums = nums;
    bsz = ceil(nums.size() / sqrt(nums.size()));
    blocks.resize(bsz, 0);
    for (int i = 0; i < nums.size(); i++) blocks[i / bsz] += nums[i];
  }
  
  void update(int index, int val) {
    blocks[index / bsz] += val - nums[index];
    nums[index] = val;
  }
  
  int sumRange(int left, int right) {
    int lb = left / bsz, rb = right / bsz;
    int res = 0;

    if (lb == rb) {
      for (int i = left; i <= right; i++) res += nums[i];
    }
    else {
      for (int i = lb + 1; i <= rb - 1; i++) res += blocks[i];
      for (int i = left; i < bsz * (lb + 1); i++) res += nums[i];
      for (int i = bsz * rb; i <= right; i++) res += nums[i];
    }

    return res;
  }
};
