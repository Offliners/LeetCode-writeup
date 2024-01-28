


typedef struct {
    int space[3];
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *parking_space = (ParkingSystem *)malloc(1 * sizeof(ParkingSystem));
    parking_space->space[0] = big;
    parking_space->space[1] = medium;
    parking_space->space[2] = small;

    return parking_space;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    return obj->space[carType - 1]-- > 0;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/