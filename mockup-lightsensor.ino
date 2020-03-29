
int LIGHT_LEVEL_THRESHOLD = 1000;
String sunlight_status;
String last_sunlight_status;

int led = D7;

void setup() {
    pinMode(led, OUTPUT);
} 
void loop() {
    last_sunlight_status = sunlight_status; // Save the previous sunlight_status to notify if is have been changed
    int darkness = random(0, 10000); // Generate mock up data as reading data from sensor
   
    // Set status for new data collected
    if (darkness <= LIGHT_LEVEL_THRESHOLD) { 
        sunlight_status = "OFF";
    } else {
        sunlight_status = "ON";
    }
    
    // Notify user if the light status is changed
    if (sunlight_status != last_sunlight_status) {
        Particle.publish("sunlight-status-changed", sunlight_status);
    }
    
    // Data collected and processed every second.
    // Blick when data collection is finished.
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    
}