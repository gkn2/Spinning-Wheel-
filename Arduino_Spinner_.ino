int count = 0;
#include <Arduino.h>
#include <Servo.h>
#include <TM1637TinyDisplay.h>

Servo   myServo;




// Define Digital Pins
#define DIO 10
#define CLK 8



// Initialize TM1637TinyDisplay
TM1637TinyDisplay display(CLK, DIO);

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
// set the starting score
int score = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  display.setBrightness(BRIGHT_HIGH);

  myServo.attach(7);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    if (count < 5) {
      s12();
      count++;    
    } else {
      // Clear Screen

       score = 0;
       // Clear Count 
       count = 0;
       display.clear();
       delay(800);
       
    }
  } 
}


void s12(){
  display.showNumber(score);
int randomNumber = random(1,5);

  if(randomNumber == 1){
    myServo.write(35);
    score = score - 35;

    display.showNumber(score);

  }
  if(randomNumber == 2){
    myServo.write(70);
    score = score + 20;

    display.showNumber(score);

  }
  if(randomNumber == 3){
    myServo.write(105);
    score = score - 30;
  
    display.showNumber(score);

  }
  if(randomNumber == 4){
    myServo.write(140);
    score = score + 100;
  
        display.showNumber(score);
  }
  
  delay(2000);
  myServo.write(180);
  delay(2000);
  
}
 
