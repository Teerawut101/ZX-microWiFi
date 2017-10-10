#include <ipst.h>
#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial1);
void setup() {
  mWiFi.begin();
  mWiFi.notify("สวัสดี%20ชาวโลก");
  glcdClear();
}
void loop() {
  if (mWiFi.ready()) {
    String msg = mWiFi.getMsg();
    glcdClear();
    glcd(0, 0, (char*)msg.c_str());
    if (msg == "LED16ON") {
      out(16, 1);
      mWiFi.chat("LED16", 1);
    } else if (msg == "LED16OFF") {
      out(16, 0);
      mWiFi.chat("LED16", 0);
    }
  }
}
