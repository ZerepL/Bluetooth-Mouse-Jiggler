#include <BleMouse.h>

BleMouse bleMouse("Generic Mouse");

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void loop() {
  if(bleMouse.isConnected()) {
    int velocity = 0;
    int delayLoop = 0;
    int delayTime = 0;
    int directionMouse = 0;
    unsigned long startTime;

    velocity = random(1, 50);
    directionMouse = random(0, 4);
    delayLoop = random(50, 200);
    delayTime = random(1000, 2200);
    startTime = millis();

    Serial.println("Velocity: " + String(velocity) + "\nDelayLoop: " + String(delayLoop) + "\nDealyTime: " + String(delayTime) + "\nDirectionMouse: " + String(directionMouse));


    switch (directionMouse) {
      case 0:
        Serial.println("Move mouse pointer up");
        while(millis()<startTime+delayTime) {
          bleMouse.move(0,-velocity);
          delay(delayLoop);
        }
        break;

      case 1:
        Serial.println("Move mouse pointer down");
        while(millis()<startTime+delayTime) {
          bleMouse.move(0,velocity);
          delay(delayLoop);
        }
        break;

      case 2:
        Serial.println("Move mouse pointer left");
        while(millis()<startTime+delayTime) {
          bleMouse.move(-velocity,0);
          delay(delayLoop);
        }
        break;

      case 3:
        Serial.println("Move mouse pointer right");
        while(millis()<startTime+delayTime) {
          bleMouse.move(velocity,0);
          delay(delayLoop);
        }
        break;
     }

     delay(delayTime);
  }
  
}
