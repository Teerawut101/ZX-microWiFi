#include <ipst.h>
#include <ZX_microWiFi.h>
ZX_microWiFi mWiFi(Serial1);
bool stLED;
void setup() {
  mWiFi.begin(); 
  mWiFi.notify("สวัสดี%20ชาวโลก");
}
void loop() {
	if(mWiFi.ready()){
		String msg = mWiFi.getMsg();
		glcdClear(); 	
    glcd(0,0,(char*)msg.c_str());  
    if(msg=="LED1"){
      stLED = ! stLED;
      mWiFi.chat("stLED1",stLED?1:0);
      out(16,stLED);
    }else if (msg=="Hi"){
      mWiFi.chat("stLED1",stLED?1:0);
      out(16,stLED);
    }
	}

  if(!in(17)){
    stLED = ! stLED;
    mWiFi.chat("stLED1",stLED?1:0);
    out(16,stLED);
    delay(10);
    while(!in(17));

  }
      
}
