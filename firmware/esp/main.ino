void setup() {
    Serial.begin(115200);
    // TODO: initialize WiFi bridge
}

void loop() {
    // Placeholder loop
    if (Serial.available()) {
        String line = Serial.readStringUntil('\n');
        Serial.println(line);
    }
}
