int ledPins[] = {2, 3, 4, 5, 6, 7};
int buttonOnPin = 8;
int buttonOffPin = 9;
int buttonFuncPin = 10;
int potPin = A0;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
  pinMode(buttonFuncPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin) / 4;

  if (!digitalRead(buttonOnPin)) {
    for (int i = 0; i < 6; i++) {
      analogWrite(ledPins[i], potValue);
    }
  } else if (!digitalRead(buttonOffPin)) {
    for (int i = 0; i < 6; i++) {
      analogWrite(ledPins[i], 0);
    }
  } else if (!digitalRead(buttonFuncPin)) {
    for (int i = 0; i < 3; i++) {
      analogWrite(ledPins[i], potValue);
    }
    delay(1000);
    for (int i = 0; i < 3; i++) {
      analogWrite(ledPins[i], 0);
    }
    for (int i = 3; i < 6; i++) {
      analogWrite(ledPins[i], potValue);
    }
    delay(1000);
    for (int i = 3; i < 6; i++) {
      analogWrite(ledPins[i], 0);
    }
  } else if (Serial.available() > 0) {
    int num = Serial.parseInt();
    for (int i = 0; i < 6; i++) {
      if (i < num) {
        analogWrite(ledPins[i], potValue);
      } else {
        analogWrite(ledPins[i], 0);
      }
    }
  }
}
