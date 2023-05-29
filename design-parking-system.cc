class ParkingSystem {
  int D[4];
public:
  ParkingSystem(int big, int medium, int small) {
    D[1] = big; D[2] = medium; D[3] = small;
  }

  bool addCar(int carType) {
    if (D[carType] > 0) {
      D[carType]--;
      return true;
    }
    return false;
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
 