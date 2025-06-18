void setup() {
    Serial.begin(115200);      // debug console
    Serial1.begin(115200);     // link to Arduino Due
    Serial.println("ESP bridge ready");
}

void loop() {
    if (Serial.available()) {
        String line = Serial.readStringUntil('\n');
        Serial1.println(line);      // forward to Due
        Serial.print("TX: ");
        Serial.println(line);
    }
    if (Serial1.available()) {
        String line = Serial1.readStringUntil('\n');
        Serial.print("RX: ");
        Serial.println(line);
    }
}
