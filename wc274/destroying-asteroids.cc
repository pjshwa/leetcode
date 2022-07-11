class Solution {
public:
  bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    sort(asteroids.begin(), asteroids.end());

    long long realmass = mass;

    for (auto& a: asteroids) {
      if (realmass >= a) realmass += a;
      else return false;
    }

    return true;
      
  }
};
