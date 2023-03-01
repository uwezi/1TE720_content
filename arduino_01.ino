#define LED_PIN 12    // Pin D12 kommer styra en lysdiod

//-----------------------------------------------------------
// initialisering
//-----------------------------------------------------------
void setup() 
{
  Serial.begin(115200);        // dataöverföring till datorn
  
  pinMode(LED_PIN, OUTPUT);    // definierar LED_PIN som utgång
}

//-----------------------------------------------------------
// repeterande uppgifter
//-----------------------------------------------------------
void loop() 
{
  digitalWrite(LED_PIN, HIGH); // sätter LED_PIN till +5 V
  
  delay(500);                  // väntar 500 ms 

  digitalWrite(LED_PIN, LOW);  // sätter LED_PIN till 0 V 

  delay(500);                  // väntar 500 ms

  Serial.println(millis());    // skickar den aktuella tiden i ms
}
