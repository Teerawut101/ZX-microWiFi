#include <ipst.h>
#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial1);
void setup() {
 mWiFi.begin();
}
void loop() {
  float Temp = (analog(A1)-81.84)/3.88;
  int LDR = analog(A0);
  String buf = "";
  buf = "temp:"+ String(Temp) +",light:"+String(LDR);
  mWiFi.feed("MyFeedData",buf);
  delay(500); 
}
