#include <Bounce2.h> // including library Bounce2

#define btn1 13 // button 1  gelb
#define btn2 12 // button 2  orange

class Led { // class Led
  int pin; // pin
  bool state; // state

  public:
  Led(int ledPin){ // constructor
    pin = ledPin; // pin
    pinMode(pin, OUTPUT); // pin mode
  }

  void toggle(){ // toggle led
    state = !state; // state
    digitalWrite(pin, state); // set state for pin
  }

  void speedToggle(int ms, int maxC){ // speed toggle
    int c; // counter
    while (c < maxC) // while counter is less than max counter
    {
      toggle(); // toggle led
      delay(ms); // delay
      c = c + random(ms); // counter
    }
  }
};

int gState = 1; // global state
long start; // global start time
long stop; // global stop time
double result; // global result

Bounce btn1Bouncer = Bounce(); // creating Bounce object for button 1
Bounce btn2Bouncer = Bounce(); // creating Bounce object for button 2

void setup(){ // setup function
  Serial.begin(9600); // starting serial communication

  btn1Bouncer.attach(btn1, INPUT_PULLUP); // attaching button 1 to Bounce object
  btn2Bouncer.attach(btn2, INPUT_PULLUP); // attaching button 2 to Bounce object
  btn2Bouncer.interval(25); // setting interval for button 2
  btn1Bouncer.interval(25); // setting interval for button 1
}

Led led1(10); // grün creating Led object for led 1
Led led2(11); // rot  creating Led object for led 2

void loop(){ // loop function
  btn1Bouncer.update(); // updating Bounce object for button 1
  btn2Bouncer.update(); // updating Bounce object for button 2

  switch(gState){ // switch statement for global state
    case 1: // case 1
      Serial.println("------------------------------------------"); // printing message
      Serial.println("Reaction Tester ready!! Press button 1."); // printing message
      led1.toggle(); // toggle led 1
      gState = 2; // global state
      break; // break
    case 2: // case 2
      if (btn1Bouncer.fell()){ // if button 1 fell
        gState = 3; // global state
      }
      break; // break
    case 3:
      Serial.println("Waiting for the red light..."); // printing message
      gState = 4; // global state
      break; // break
    case 4: // case 4
      led1.speedToggle(300, random(5*1000)); // speed toggle led 1
      led2.toggle(); // toggle led 2
      led1.toggle(); // toggle led 1
      start = millis(); // start time
      gState = 5; // global state
      break; // break
    case 5: // case 5
      if (btn2Bouncer.fell()){ // if button 2 fell
        stop = millis(); // stop time
        led2.toggle(); // toggle led 2
        led1.toggle(); // toggle led 1
        result = stop - start; // result
        Serial.print("Reaction time: "); // printing message
        Serial.print(result / 1000); // printing result
        Serial.println(" seconds"); // printing message
        Serial.println("------------------------------------------"); // printing message
      }
      break; // break
    default: // default case
      Serial.println("Debug: Error!"); // printing message
      break; // break
  }
}
