class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    string query = "";
    vector<vector<string>> ans;
    sort(products.begin(), products.end());
    
    for (char c : searchWord) {
      query += c;
      vector<string> tmp;

      for (string& product : products) {
        if (tmp.size() < 3 && product.find(query) == 0) tmp.push_back(product);
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};
