// Pulse Sensor setup
const int pulsePin = A0;       // Analog input pin for Pulse Sensor
int signal;                    // Holds the analog signal value
int threshold = 550;           // Adjust based on your sensor's output

// Timing variables
unsigned long lastBeatTime = 0;
int BPM;
int beatCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pulsePin, INPUT);
}

void loop() {
  signal = analogRead(pulsePin);

  if (signal > threshold) {
    unsigned long currentTime = millis();
    if (currentTime - lastBeatTime > 300) { // debounce to avoid false beats
      BPM = 60000 / (currentTime - lastBeatTime);
      lastBeatTime = currentTime;
      Serial.print("Heartbeat detected! BPM: ");
      Serial.println(BPM);
    }
  }

  delay(100); // Small delay to stabilize readings
}
