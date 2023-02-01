class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    int z1 = str1.size(), z2 = str2.size();
    int g = __gcd(z1, z2);

    string str_g = str1.substr(0, g);
    string str1_r = "", str2_r = "";
    for (int i = 0; i < z1 / g; ++i) str1_r += str_g;
    for (int i = 0; i < z2 / g; ++i) str2_r += str_g;

    if (str1_r == str1 && str2_r == str2) return str_g;
    else return "";
  }
};
