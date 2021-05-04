int Sound = 2;
int Speaker = 12;
int Motor = 13;
int Switch = 11;
int Button = 10;

unsigned long Time = 0;


void setup()
{
  //Serial.begin(9600);
  pinMode(Motor, OUTPUT);
  pinMode(Speaker, OUTPUT);
  pinMode(Button, INPUT);
  pinMode(Switch, INPUT);
  pinMode(Sound,INPUT);
  
}

void loop()
{
  while (digitalRead(Switch)== LOW) { //clock setup
    if (digitalRead(Button)== HIGH){ //if button is pushed, adds a definite amount of delay 
        Time = Time + 3600000; //
      	delay(200); // waits before another reading ?? removes problem of long press
    }
  }
  delay(Time);
  while (digitalRead(Switch)== HIGH && digitalRead(Sound)== LOW){
     digitalWrite(Speaker, HIGH);
     digitalWrite(Motor, HIGH); // if not in setup mode and time has passed enough, the clock will start to alarm

  }
 
  digitalWrite(Speaker, LOW); //once either the setup mode is activated or input 2 is HIGH, will snooze for 50 sec before alarming again
  digitalWrite(Motor, LOW);
  Time = 0; //Clock time reset
  delay(50000); // delay
  
}