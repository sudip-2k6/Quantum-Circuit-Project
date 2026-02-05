#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define BIT0 2   // LDR 1  (|0>)  → D2
#define BIT1 7   // LDR 2  (|1>)  → **D7 (changed)**
#define LASER 8  // Laser control pin

void setup() {
  pinMode(BIT0, INPUT);
  pinMode(BIT1, INPUT);
  pinMode(LASER, OUTPUT);

  digitalWrite(LASER, LOW); // laser OFF at start

  lcd.begin(16, 2);
  lcd.backlight();

  // --- Startup message ---
  lcd.setCursor(0,0);
  lcd.print("Quantum circuit");
  lcd.setCursor(0,1);
  lcd.print("undr Ranabir Sir");
  delay(1500);
  lcd.clear();
  // --- Creator message
  lcd.setCursor(0,0);
  lcd.print("by   Sudipta");
  lcd.setCursor(0,1);
  lcd.print("  Karmakar A1-28");
  delay(2000);
  lcd.clear();

  // --- Laser starting ---
  lcd.setCursor(0,0);
  lcd.print(" LASER STARTING");
  delay(2000);          // wait 1 second

  digitalWrite(LASER, HIGH); // turn ON laser

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LDR Calibration");
  lcd.setCursor(0,1);
  lcd.print("   has started   ");
  delay(1000);

  lcd.clear();
}

void loop() {

  int count0 = 0;
  int count1 = 0;
  int samples = 120;

  // take measurements
  for(int i=0; i<samples; i++){
    int b0 = digitalRead(BIT0);
    int b1 = digitalRead(BIT1);

    if(b0 == 1) count0++;
    if(b1 == 1) count1++;

    delay(5);
  }

  float p0 = (count0 * 100.0) / samples;
  float p1 = (count1 * 100.0) / samples;

  lcd.clear();

  // ---- Title line ----
  if (count0 > 0 && count1 > 0) {
    lcd.setCursor(0,0);
    lcd.print("    SUPERPOS");
  } 
  else {
    lcd.setCursor(0,0);
    lcd.print("  PROBABILITY");
  }

  // ---- Side by side probabilities ----
  lcd.setCursor(0,1);
  lcd.print("0:");
  lcd.print(p0,1);
  lcd.print("% ");

  lcd.print("1:");
  lcd.print(p1,1);
  lcd.print("%");

  delay(500);
}