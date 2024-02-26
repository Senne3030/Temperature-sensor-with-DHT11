#include <DHT11.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DHT11 dht11_1(2);
DHT11 dht11_2(3);

void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {

  int CurrentMillis = millis();

  int temperature = dht11_1.readTemperature();
  int temperature2 = dht11_2.readTemperature();

  if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT) {
    Serial.print("Temperature inside: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Temperature Outside: ");
    Serial.print(temperature2);
    Serial.println(" °C");

    lcd.setCursor(0, 0);
    lcd.print("Binnen: ");
    lcd.setCursor(8, 0);
    lcd.print(temperature);
    lcd.setCursor(11, 0);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Buiten: ");
    lcd.setCursor(8, 1);
    lcd.print(temperature2);
    lcd.setCursor(11, 1);
    lcd.print("C");

  } else {

    Serial.println("Error: Something was wrong");
  }
}
