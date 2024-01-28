class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        parking_space = {big, medium, small};
    }
    
    bool addCar(int carType) {
        return parking_space[carType - 1]-- > 0;
    }

private:
    vector<int> parking_space;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */