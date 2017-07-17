#include <ipst.h>
#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial1);
void setup() {
  mWiFi.begin(); 
  mWiFi.notify("สวัสดี");
}
void loop() {
  mWiFi.chat("Temp",knob());
  delay(500);
}
