bool right = true;
bool left = false;

bool isEvent() {
    return ((sensorValues[0] > edge) || (sensorValues[2] < edge) || (sensorValues[4] > edge));
}

void reactToEvent(int pEventNum) {
    switch (pEventNum) {
        case 1:
        case 2:
        case 11:
        case 12:
            turn(right);
        break;

        case 3:
            followEdge();
        break;

        case 4:

        break;
        
        case 5:

        break;
    }
}

void turn(bool pDirection) {
    sensors.readCalibrated(sensorValues);
    motors.setSpeeds(150, 150);
    delay(200);
    if (pDirection) {
        while (sensorValues[2] > edge) {
            motors.setSpeeds(150, -150);
            while (sensorValues[2] < edge) {
                motors.setSpeeds(100, -100);
            }
        }
    }
    
    
    // if (pDirection == right) {
    //     motors.setSpeeds(150, -150);
    //     delay(300);
    // }
    // if (pDirection == left) {
    //     motors.setSpeeds(150, -150);
    //     delay(300);
    // }
}

void followEdge() {
    
}

