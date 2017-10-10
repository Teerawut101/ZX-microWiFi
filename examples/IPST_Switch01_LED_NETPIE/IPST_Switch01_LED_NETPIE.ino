#include <ipst.h>
#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial1);
void setup() {
  mWiFi.begin();
  mWiFi.notify("IPST_Started");
}
void loop() {
  if (in(17)) {
    mWiFi.chat("LED16",1);
    out(16, 1);
  } else {
    mWiFi.chat("LED16",0);
    out(16, 0);
  }
  delay(500);
}

