#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int sensorLuzPin = A1; 
const int ledPin = 10;       
const int pinoSensorUmidade = A0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoSensorUmidade, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
}

void loop() {
  delay(1000);
  int valorRecebido;
  int luminosidade = analogRead(sensorLuzPin); 
  int umidade = analogRead(pinoSensorUmidade);


  Serial.print("Humidade: ");
  Serial.println(umidade);

  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);

  if (Serial.available()) {
    valorRecebido = Serial.read();
    if (valorRecebido == '0') {
      digitalWrite(ledPin, LOW);
    } else {
      digitalWrite(ledPin, HIGH);
    }
  }

  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);

  lcd.print("Luz: ");
  if (luminosidade < 20) {
    lcd.print("Baixa");
  } else {
    lcd.print("Adequada");
  }

  lcd.setCursor(0, 1);
  lcd.print("Humidade: ");
  lcd.print(umidade);

  delay(1000);
}

