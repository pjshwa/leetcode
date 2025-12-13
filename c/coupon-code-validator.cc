class Solution {
  int getBusinessLineIdx(const string& businessLine) {
    if (businessLine == "electronics") return 0;
    if (businessLine == "grocery") return 1;
    if (businessLine == "pharmacy") return 2;
    if (businessLine == "restaurant") return 3;
    return -1; // Invalid business line
  }

  bool isCodeValid(const string& code) {
    if (code.empty()) return false;
    for (char ch : code) {
      if (!isalnum(ch) && ch != '_') return false;
    }
    return true;
  }

public:
  vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    int N = code.size();
    vector<pair<int, string>> validCoupons;
    for (int i = 0; i < N; ++i) {
      if (!isCodeValid(code[i])) continue;
      int idx = getBusinessLineIdx(businessLine[i]);
      if (idx == -1) continue;
      if (isActive[i]) validCoupons.emplace_back(idx, code[i]);
    }
    sort(validCoupons.begin(), validCoupons.end());

    vector<string> res;
    for (const auto& p : validCoupons) res.push_back(p.second);
    return res;
  }
};
