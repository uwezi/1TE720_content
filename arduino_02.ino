#define LED_PIN    12 // Pin D12 är en indikator
#define CHARGE_PIN  2 // Pin D2 kommer vara en spänningsskälla
#define VOLTMETER   7 // PIN A7 ska vara vår mätingång

uint32_t startTime;
uint32_t timeStep;
double   value;

//-----------------------------------------------------------
// initialisering
//-----------------------------------------------------------
void setup() 
{
  Serial.begin(115200);
}

//-----------------------------------------------------------
// hjälpfunktion konverterar avläsning till spänning
//-----------------------------------------------------------
double voltage(uint8_t channel) 
{
  return analogRead(channel) * (5.0/1023);
}

//-----------------------------------------------------------
// repeterande uppgifter
//-----------------------------------------------------------
void loop() 
{
  
  digitalWrite(LED_PIN, HIGH); // slå på LEDn som indikator
  Serial.println("#***************************************");

  // ladda upp kondensatorn:
  
  pinMode(CHARGE_PIN, OUTPUT);    // slå på spänningskälla
  
  digitalWrite(CHARGE_PIN, HIGH); // välj 5V (=HIGH)

  while (voltage(VOLTMETER) < 5.0)
  {
    // vänta tills kondensatorn är laddad till +5 V
  }
  
  delay(100);                  // vänta 100 ms extra

  Serial.println("# time [s]   voltage [V]");
  
  digitalWrite(LED_PIN, LOW);  // slå av lysdioden
  
  // slå av spänningskällan
  pinMode(CHARGE_PIN, INPUT);
  digitalWrite(CHARGE_PIN, LOW);
  
  startTime = millis();        // kom ihåg starttiden

  do                           // mät urladdningen 
  {
    timeStep = millis()-startTime;
    value = voltage(VOLTMETER);
    Serial.print(timeStep/1000.0, 3);
    Serial.print("   ");
    Serial.println(value, 3);
    delay(1);
  } while ((timeStep < 100000) && (value > 0)); 
  
  Serial.println("#***************************************");
  Serial.println("# Ready.  ny mätning om 5 sekunder");
  delay(5000);  // vänta i 5 sekunder
}
