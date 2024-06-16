class FoodRatings {
  map<string, string> cuisine_by_food;
  map<string, int> rating_by_food;
  map<string, set<pair<int, string>>> foods_by_cuisine;

public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int N = foods.size();
    for (int i = 0; i < N; ++i) {
      cuisine_by_food[foods[i]] = cuisines[i];
      rating_by_food[foods[i]] = ratings[i];
      foods_by_cuisine[cuisines[i]].insert({-ratings[i], foods[i]});
    }
  }

  void changeRating(string food, int new_rating) {
    string cuisine = cuisine_by_food[food];
    int old_rating = rating_by_food[food];

    foods_by_cuisine[cuisine].erase({-old_rating, food});
    foods_by_cuisine[cuisine].insert({-new_rating, food});
    rating_by_food[food] = new_rating;
  }

  string highestRated(string cuisine) {
    return foods_by_cuisine[cuisine].begin()->second;
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
