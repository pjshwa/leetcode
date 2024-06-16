class Solution {
  map<pair<string, string>, double> cost;
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    set<string> variables;
    for (auto& equation : equations) {
      variables.insert(equation[0]);
      variables.insert(equation[1]);
    }

    for (auto& variable : variables) cost[{variable, variable}] = 1.0;
    int n = equations.size();
    for (int i = 0; i < n; i++) {
      auto& equation = equations[i];
      auto& value = values[i];
      cost[{equation[0], equation[1]}] = value;
      cost[{equation[1], equation[0]}] = 1.0 / value;
    }

    // Floyd-Warshall
    for (auto& v3 : variables) for (auto& v1 : variables) for (auto& v2 : variables) {
      if (cost.count({v1, v2})) continue;
      if (cost.count({v1, v3}) && cost.count({v3, v2})) {
        cost[{v1, v2}] = cost[{v1, v3}] * cost[{v3, v2}];
      }
    }

    vector<double> result;
    for (auto& query : queries) {
      if (cost.count({query[0], query[1]})) result.push_back(cost[{query[0], query[1]}]);
      else result.push_back(-1.0);
    }

    return result;
  }
};
