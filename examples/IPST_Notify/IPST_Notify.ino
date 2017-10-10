#include <ipst.h>
#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial1);
void setup() {
  mWiFi.begin();
  mWiFi.notify("helloTest");
}
void loop() {
}

