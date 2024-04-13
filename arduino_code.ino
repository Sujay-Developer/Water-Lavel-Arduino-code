#include <Capacitor.h>
Capacitor cap1(7,A2);
int kondenzator=0;
int w = 0;
void SendString(byte InstrNo, int MValue) {
  Serial.print('#');
  Serial.print(InstrNo);
  Serial.print('M');
  Serial.print(MValue);
  Serial.print('<');
}

void setup() 
{ 
Serial.begin(9600);
}

void loop() 
{
kondenzator = (cap1.Measure())*100;
 //Serial.print(kondenzator);  // Measure the capacitance (in pF), print to Serial Monitor
  int w = map(kondenzator, 130, 330, 0, 500); 
 // Serial.print(w);
    SendString(1,w);       // Instrument #01
    SendString(2,w);       // Instrument #02
    SendString(3,w);       // Instrument #03
    delay(500);
  } 
