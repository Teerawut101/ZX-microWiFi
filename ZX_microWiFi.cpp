#include "ZX_microWiFi.h"
#include <Arduino.h>
ZX_microWiFi::ZX_microWiFi(PlatformStream &s){
  _stream = &s;
}

ZX_microWiFi::ZX_microWiFi(PlatformStream *s){
  _stream = s;
}
String ZX_microWiFi::getMsg(String msg){
	return _msg = _msg + msg;
}
String ZX_microWiFi::getMsg(){
	String msg = _msg;
	_msg = "";
	return msg ;
}
bool ZX_microWiFi::feed(char* feedname,char* data) {
    //reinterpret_cast<HardwareSerial *>(_stream)->println("netpieFeed "+String(feedname)+" "+data);
    _stream->println("netpieFeed "+String(feedname)+" "+String(data));
	return 1;
}
bool ZX_microWiFi::feed(char* feedname, String data) {
    //reinterpret_cast<HardwareSerial *>(_stream)->println("netpieFeed "+String(feedname)+" "+data);
    _stream->println("netpieFeed "+String(feedname)+" "+data);
	return 1;
}
bool ZX_microWiFi::chat(char* topic, char * message) {
	_stream->println("netpieChat "+String(topic)+" "+String(message));
	return 1;
}
bool ZX_microWiFi::chat(char* topic, int message) {
	_stream->println("netpieChat "+String(topic)+" "+String(message));
	return 1;
}
bool ZX_microWiFi::chat(char* topic, double message) {
	_stream->println("netpieChat "+String(topic)+" "+String(message));
	return 1;
}
bool ZX_microWiFi::chat(char* topic, float message) {
	_stream->println("netpieChat "+String(topic)+" "+String(message));
	return 1;
}
bool ZX_microWiFi::chat(char* topic, String message) {
	_stream->println("netpieChat "+String(topic)+" "+message);
	return 1;
}
bool ZX_microWiFi::notify(String data) {
	_stream->println("line "+data);
	return 1;
}
bool ZX_microWiFi::notify(char * data) {
	_stream->println("line "+String(data));
	return 1;
}
int ZX_microWiFi::ready(){
   while (_stream->available()) {
    char inChar = (char)_stream->read();
    if (inChar == '\n') {
       return 1;
     }
    _msg += inChar;
	}
	return 0;
}
void ZX_microWiFi::begin(){
 // #if defined (ARDUINO_PLATFORM)
    reinterpret_cast<HardwareSerial *>(_stream)->begin(9600);
 // #endif
}
void ZX_microWiFi::println(String data){
 // #if defined (ARDUINO_PLATFORM)
    _stream->println(data);
 // #endif
}