

#include "main.h"


void initializeIO() {
pinMode(SHOULDER_LIMIT, INPUT);
pinMode(ELBOW_LIMIT, INPUT);
}


void initialize() {
shoulderEncoder = encoderInit(6 ,7 ,false );
elbowEncoder= encoderInit(8, 9, false);

}
