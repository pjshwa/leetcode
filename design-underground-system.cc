class UndergroundSystem {
public:
  map<pair<string, string>, int> total, count;
  map<int, pair<int, string>> custo;

  UndergroundSystem() {
  }
  
  void checkIn(int id, string stationName, int t) {
    custo[id] = {t, stationName};
  }
  
  void checkOut(int id, string stationName, int t) {
    auto& [stim, ssta] = custo[id];
    auto& esta = stationName;

    total[{ssta, esta}] += t - stim;
    count[{ssta, esta}]++;
  }
  
  double getAverageTime(string startStation, string endStation) {
    return (double)total[{startStation, endStation}] / count[{startStation, endStation}];
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
