const int motor        = 10;
const int red        = 7;
const int blue        = 6;
const int green        = 5;
const int butaunZin    = 2;
int state            = LOW;


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
  delay(500); //delay para evitar muitas alterações seguidas
};

void onOff(){
  if (state == HIGH) {
    analogWrite(red, 0);
    analogWrite(blue, 0);
    analogWrite(green, 255);
    digitalWrite(motor, HIGH);
  } else {
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
