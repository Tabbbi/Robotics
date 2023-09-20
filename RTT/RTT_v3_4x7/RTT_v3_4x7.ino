#include <Bounce2.h> // including library Bounce2
#include <SevSeg.h> // including library SevSeg

SevSeg sevseg; //Instantiate a seven segment controller object

#define btn1 13 // button 1 yellow
#define btn2 12 // button 2 orange

class Led { // class Led
  int pin; // pin
  bool state; // state

  public:
  Led(int ledPin){ // constructor
    pin = ledPin; // pin
    pinMode(pin, OUTPUT); // pin mode
  } // end constructor

  void toggle(){ // toggle led
    state = !state; // state
    digitalWrite(pin, state); // set state for pin
  } // end toggle

  void speedToggle(int ms, int maxC){ // speed toggle
    int c; // counter
    while (c < maxC) { // while counter is less than max counter
      toggle(); // toggle led
      delay(ms); // delay
      c = c + random(ms); // counter
    } // end while
  } // end speed toggle
}; // end class Led

int gState = 1; // global state
long start; // global start time
long stop; // global stop time
float result; // global result

Bounce btn1Bouncer = Bounce(); // creating Bounce object for button 1
Bounce btn2Bouncer = Bounce(); // creating Bounce object for button 2

void setup(){ // setup function
  byte numDigits = 4; // number of digits
  byte digitPins[] = {A4, A3, A2, A1}; // digit pins
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // segment pins
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint); // begin seven segment controller
  sevseg.setBrightness(100); // set brightness

  btn1Bouncer.attach(btn1, INPUT_PULLUP); // attaching button 1 to Bounce object
  btn2Bouncer.attach(btn2, INPUT_PULLUP); // attaching button 2 to Bounce object
  btn2Bouncer.interval(25); // setting interval for button 2
  btn1Bouncer.interval(25); // setting interval for button 1
}

Led led2(11); // creating Led object for led 2 red
Led led1(10); // creating Led object for led 1 green

void loop(){ // loop function
  btn1Bouncer.update(); // updating Bounce object for button 1
  btn2Bouncer.update(); // updating Bounce object for button 2

  switch(gState){ // switch statement for global state
    case 1: // case 1
      led1.toggle(); // toggle led 1
      gState = 2; // global state
      break; // break
    case 2: // case 2
      if (btn1Bouncer.fell()){ // if button 1 fell
        gState = 3; // global state
      }
      break; // break
    case 3: // case 3
      led1.speedToggle(300, random(5*1000)); // speed toggle led 1
      led2.toggle(); // toggle led 2
      if (digitalRead(10) == HIGH) { // if button 1 is pressed
        digitalWrite(10, LOW); // set button 1 to low
      } 
      start = millis(); // start time
      gState = 4; // global state
      break; // break
    case 4: // case 4
      if (btn2Bouncer.fell()){ // if button 2 fell
        stop = millis(); // stop time
        led2.toggle(); // toggle led 2
        digitalWrite(10, HIGH); // set button 1 to high
        result = stop - start; // result
        sevseg.setNumberF(result / 1000, 2); // set number for seven segment controller
      }
      sevseg.refreshDisplay(); // refresh display
      break; // break
    default: // default case
      sevseg.setChars("FAIL"); // set characters
      sevseg.refreshDisplay(); // refresh display
      break; // break
  } // end switch statement
} // end loop function
