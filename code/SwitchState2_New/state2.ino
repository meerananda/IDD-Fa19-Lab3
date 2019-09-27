// This borrows code from Examples->EEPROM->eeprom_write

String textarray = "hello cornell tech!";
int endAddr;

void state2Setup() {
  digitalWrite(ledPin, LOW);
  Serial.println("Writing to EEPROM");
 
  sensorValue = analogRead(sensorPin);
  int mappedSensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  EEPROM.write(0, mappedSensorValue);

  Serial.print("Sensor Value: "); Serial.print(mappedSensorValue);
  Serial.println();

  Serial.println("String committed to EEPROM!");
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
}
