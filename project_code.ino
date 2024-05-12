
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;
int relayPin = 3; // Define the pin number for the relay

void setup() {
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  //rtc.adjust(DateTime(2024, 4, 10, 17, 36, 0)); // (year, month, day, hour, minute, second)
  pinMode(relayPin, OUTPUT); 
 
  // Set relay pin as an output
}

void loop() {
  DateTime now = rtc.now();
  
  digitalWrite(relayPin, LOW);
  

  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);
  //delay(1000);
  // Check schedule based on the day of the week
  if (now.dayOfTheWeek() == 1) { // Monday
    if ((now.hour() == 8 && now.minute() == 15 && now.second() == 0) ||
        (now.hour() == 9 && now.minute() == 0 && now.second() == 0) ||
        (now.hour() == 9 && now.minute() == 5 && now.second() == 0) ||
        (now.hour() == 9 && now.minute() == 50 && now.second() == 0) ||
        (now.hour() == 9 && now.minute() == 55 && now.second() == 0) ||
        (now.hour() == 10 && now.minute() == 40 && now.second() == 0) ||
        (now.hour() == 10 && now.minute() == 45 && now.second() == 0) ||
        (now.hour() == 11 && now.minute() == 30 && now.second() == 0) ||
        (now.hour() == 11 && now.minute() == 35 && now.second() == 0) ||
        (now.hour() == 12 && now.minute() == 25 && now.second() == 0) ||
        (now.hour() == 12 && now.minute() == 55 && now.second() == 0) ||
        (now.hour() == 13 && now.minute() == 40 && now.second() == 0) ||
        (now.hour() == 13 && now.minute() == 45 && now.second() == 0) ||
        (now.hour() == 14 && now.minute() == 30 && now.second() == 0) ||
        (now.hour() == 16 && now.minute() == 30 && now.second() == 0) ||
        (now.hour() == 18 && now.minute() == 30 && now.second() == 0)) {
      // Activate the relay for 6.5 seconds
      digitalWrite(relayPin, HIGH);
      delay(6500);
      digitalWrite(relayPin, LOW);
    }
  } else if (now.dayOfTheWeek() >= 2 && now.dayOfTheWeek() <= 6) { // Tuesday to Saturday
    if ((now.hour() == 8 && now.minute() == 0 && now.second() == 0) ||
        (now.hour() == 8 && now.minute() == 45 && now.second() == 0) ||
        (now.hour() == 8 && now.minute() == 50 && now.second() == 0) ||
        (now.hour() == 9 && now.minute() == 35 && now.second() == 0) ||
        (now.hour() == 9 && now.minute() == 40 && now.second() == 0) ||
        (now.hour() == 10 && now.minute() == 25 && now.second() == 0) ||
        (now.hour() == 10 && now.minute() == 30 && now.second() == 0) ||
        (now.hour() == 11 && now.minute() == 15 && now.second() == 0) ||
        (now.hour() == 11 && now.minute() == 20 && now.second() == 0) ||
        (now.hour() == 12 && now.minute() == 5 && now.second() == 0) ||
        (now.hour() == 12 && now.minute() == 35 && now.second() == 0) ||
        (now.hour() == 13 && now.minute() == 20 && now.second() == 0) ||
        (now.hour() == 13 && now.minute() == 25 && now.second() == 0) ||
        (now.hour() == 14 && now.minute() == 10 && now.second() == 0) ||
        (now.hour() == 16 && now.minute() == 30 && now.second() == 0) ||
        (now.hour() == 18 && now.minute() == 30 && now.second() == 0)) {
      // Activate the relay for 6.5 seconds
      digitalWrite(relayPin, HIGH);
      delay(6500);
      digitalWrite(relayPin, LOW);
    }
  }
}
