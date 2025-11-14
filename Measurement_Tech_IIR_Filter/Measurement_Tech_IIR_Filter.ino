// ----------------------------------------------------------
// Low-Pass IIR Filter (Exponential Moving Average)
// Filters the signal from analog input A0
// y[k] = alpha * x[k] + (1 - alpha) * y[k-1]
// ----------------------------------------------------------

const int sensorPin = A0;

// Smoothing factor (0 < alpha < 1)
// Smaller alpha = more smoothing (slower response)
// Larger alpha = less smoothing (faster response)
float alpha = 0.1;      // Adjust as needed

float filteredValue = 0;   // Stores the filtered output
bool firstRun = true;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("IIR Low-Pass Filter Started");
}

void loop() {
  // Read raw value from A0 (0–1023)
  int rawValue = analogRead(sensorPin);

  // Initialize filter on first run
  if (firstRun) {
    filteredValue = rawValue;
    firstRun = false;
  }

  // Apply IIR filter
  filteredValue = alpha * rawValue + (1.0 - alpha) * filteredValue;

  // Print results
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print("   Filtered: ");
  Serial.println(filteredValue);

  // Sample rate control (adjust as needed)
  delay(10);
}

