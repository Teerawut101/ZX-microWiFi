#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial);
void setup() {
  mWiFi.begin();
  char buf[20];
  sprintf(buf,"temp:%d,val:%d",10,9);
  mWiFi.feed("myFeed0",buf);
  mWiFi.feed("myFeed1","temp:12.5");
  mWiFi.chat("stled1",12.345);
  mWiFi.chat("stled1",12345);
  mWiFi.chat("stled1","12345");
  mWiFi.notify("helloTest");
}

void loop() {
  if(mWiFi.ready()){
    mWiFi.println(mWiFi.getMsg());
 }
}
