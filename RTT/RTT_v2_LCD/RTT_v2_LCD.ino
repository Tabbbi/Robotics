/*
LCD-Pins:
GND -> GND
VCC -> 5V
SDA -> A4
SCL -> A5
*/

#include <Bounce2.h> // including library Bounce2
#include <LiquidCrystal_I2C.h> // including library LiquidCrystal_I2C

LiquidCrystal_I2C lcd(0x27, 20, 4); // instantiate a LiquidCrystal_I2C object

#define btn1 13 // button 1
#define btn2 12 // button 2

class Led { // class Led
  int pin; // pin
  bool state; // state

  public: // public functions
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
    } // end while
  } // end speed toggle
}; // end class Led

int gState = 1; // global state
long start; // global start time
long stop; // global stop time
double result; // global result

Bounce btn1Bouncer = Bounce(); // creating Bounce object for button 1
Bounce btn2Bouncer = Bounce(); // creating Bounce object for button 2

void setup(){ // setup function
  lcd.init(); // initialize LCD
  lcd.backlight(); // turn on LCD backlight

  btn1Bouncer.attach(btn1, INPUT_PULLUP); // attaching button 1 to Bounce object
  btn2Bouncer.attach(btn2, INPUT_PULLUP); // attaching button 2 to Bounce object
  btn2Bouncer.interval(25); // setting interval for button 2
  btn1Bouncer.interval(25); // setting interval for button 1
}

Led led1(10); // creating Led object for led 1
Led led2(11); // creating Led object for led 2

void loop(){ // loop function
  btn1Bouncer.update(); // updating Bounce object for button 1
  btn2Bouncer.update(); // updating Bounce object for button 2

  switch(gState){ // switch statement for global state
    case 1: // case 1
      lcd.clear(); // clear LCD
      lcd.setCursor(0, 0); // set cursor to 0, 0
      lcd.print("RTT is ready!"); // print to LCD
      lcd.setCursor(0, 1); // set cursor to 0, 1
      lcd.print("Press button 1"); // print to LCD
      led1.toggle(); // toggle led 1
      gState = 2; // global state
      break; // break
    case 2: // case 2
      if (btn1Bouncer.fell()){ // if button 1 fell
        gState = 3; // global state
      } // end if
      break; // break
    case 3: // case 3
      lcd.setCursor(0, 2); // set cursor to 0, 2
      lcd.print("Wait for red light.."); // print to LCD
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
        lcd.setCursor(0, 3); // set cursor to 0, 3
        lcd.print(result / 1000); // print to LCD
        lcd.print(" seconds"); // print to LCD
      }
      break; // break
    default: // default case
      lcd.setCursor(0, 0); // set cursor to 0, 0
      lcd.print("Debug: Error!"); // print to LCD
      break; // break
 } // end switch statement
} // end loop function