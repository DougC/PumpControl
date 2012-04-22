

const unsigned int RELAY_PIN = 6;
const unsigned int CONTROL_PIN = 12;
const unsigned int BAUD_RATE = 9600;

// This is the time at which the pump was last switched on
long lastPumpOnTime = 0;

// The time at which we last switched the pump off
long lastPumpOffTime = 0;

unsigned int isPumpOn = 0;

// Length of time to run pump, in ms
const unsigned int ON_PERIOD = secondsInMillis(60);

// Period before circuit is active again, in ms
const unsigned int INACTIVE_PERIOD = minutesInMillis(5);

void setup () {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(CONTROL_PIN, INPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {
  if (isPumpOn) {
    if (millis() - lastPumpOnTime > ON_PERIOD) {
      turnPumpOff();
    }
  } else {
    if (digitalRead(CONTROL_PIN) == HIGH) {
       if (lastPumpOffTime == 0 || millis() - lastPumpOffTime > INACTIVE_PERIOD) {
         turnPumpOn();
       }
    }
  }
}

long minutesInMillis(long mins) {
  return mins * 60 * 1000;
}

long secondsInMillis(long seconds) {
  return seconds * 1000;
}

void turnPumpOff() {
  digitalWrite(RELAY_PIN, LOW);
  isPumpOn = 0;
  lastPumpOffTime = millis();
  Serial.println("Pump off");
}

void turnPumpOn() {
  isPumpOn = 1;
  lastPumpOnTime = millis();
  digitalWrite(RELAY_PIN, HIGH);
  Serial.println("Pump on");
}
