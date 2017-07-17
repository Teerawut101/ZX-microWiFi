#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial);
void setup() {
  mWiFi.begin();
  mWiFi.notify("helloTest");
}
void loop() {
}
