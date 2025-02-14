class ProductOfNumbers {
  vector<long long> P;

public:
  ProductOfNumbers() {}

  void add(int num) {
    if (num == 0) P.clear();
    else if (!P.empty()) P.push_back(P.back() * num);
    else P.push_back(num);
  }

  int getProduct(int k) {
    int Z = P.size(), ans;
    if (Z == k) ans = P.back();
    else if (Z < k) ans = 0;
    else ans = P[Z - 1] / P[Z - k - 1];
    return ans;
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
