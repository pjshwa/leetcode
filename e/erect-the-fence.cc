using ll = long long;

struct Point {
  ll x, y;
  Point(ll a, ll b) : x(a), y(b) {};
  Point() {};
  bool operator<(const Point &rhs) const {
    if (y != rhs.y) return y < rhs.y;
    return x < rhs.x;
  }
};

ll ccw(Point pt1, Point pt2, Point pt3) {
  return (pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt2.y - pt1.y) * (pt3.x - pt1.x);
}

ll dist(Point pt1, Point pt2) {
  ll dx = pt2.x - pt1.x;
  ll dy = pt2.y - pt1.y;
  return dx * dx + dy * dy;
}

class Solution {
public:
  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    vector<Point> points;
    for (auto &tree : trees) {
      points.push_back(Point(tree[0], tree[1]));
    }

    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), [&](Point x, Point y) {
      ll ccw_val = ccw(points[0], x, y);
      if (ccw_val != 0) return ccw_val > 0;
      return dist(points[0], x) < dist(points[0], y);
    });

    int p = points.size() - 1;
    while (p >= 2 && ccw(points[0], points[points.size() - 1], points[p - 1]) == 0) {
      p--;
    }
    reverse(points.begin() + p, points.end());

    vector<Point> hull;
    for (int i = 0; i < points.size(); i++) {
      while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i]) < 0) {
        hull.pop_back();
      }
      hull.push_back(points[i]);
    }

    vector<vector<int>> ans;
    for (auto [x, y] : hull) ans.push_back({(int)x, (int)y});
    return ans;
  }
};
