const int motor       = 10;
const int red         = 7;
const int green       = 6;
const int blue        = 5;
const int butaunZin   = 2;
int state             = LOW;

long previousMillis   = 0;
long timerTurnOff     = 30000; //timer to turn off (set for 1 minute for now)


void setup() {
  pinMode(butaunZin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(motor, OUTPUT);
};

void checkButton(){  
  if (digitalRead(butaunZin) == 1){
    state = !state;
  };
  delay(500);
};

void onOff(){
  unsigned long currentMillis = millis(); //Actual time in ms
  
  if (state == HIGH) {
    analogWrite(red, 0);
    analogWrite(blue, 0);
    analogWrite(green, 255);
    digitalWrite(motor, HIGH);
    if (currentMillis - previousMillis > timerTurnOff) {
      previousMillis = currentMillis; // Save actual time
      state = !state;
    }
  }
 if (state == LOW){
    previousMillis = currentMillis; // Save actual time
    analogWrite(red, 255);
    analogWrite(blue, 0);
    analogWrite(green, 0);
    digitalWrite(motor, LOW);
  };
};

void loop() {
  checkButton();
  onOff();    
};
