#ifndef ZX_MICROWIFI_H
#define ZX_MICROWIFI_H
#include <Arduino.h>
typedef Stream PlatformStream;

class ZX_microWiFi {

private:
    PlatformStream *_stream;
    String _msg;
public:
	ZX_microWiFi(PlatformStream &s);
    ZX_microWiFi(PlatformStream *s);

	String getMsg(String);

	String getMsg();
	int ready();

	bool feed(char*, char*);
	bool feed(char*, String);

	bool chat(char*, char*);
	bool chat(char*, int);
	bool chat(char*, double);
	bool chat(char*, float);
	bool chat(char*, String);

	bool notify(char*);
	bool notify(String);

	void ZX_microWiFi::begin();
	void ZX_microWiFi::println(String);
};
#endif