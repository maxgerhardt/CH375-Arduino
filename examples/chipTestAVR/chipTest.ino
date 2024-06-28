#include <SoftwareSerial.h>
#include "CH375.h"

#define CH375_RX 2
#define CH375_TX 3
#define CH375_INT 4
SoftwareSerial swSer(2, 3); // RX, TX
CH375 ch375(swSer, 4);

void set_baud_rate_cb() {
    swSer.begin(115200);
}

void setup() {
  Serial.begin(115200);
  Serial.println("preparing...");
  delay(5000);
  Serial.println("ready");
  swSer.begin(9600);
  if (ch375.init()) {
    Serial.println("CH375 test OK");
  } else {
    Serial.println("CH375 is not working properly");
    while (true) delay(1000);
  }
  ch375.setBaudRate(115200, &set_baud_rate_cb);
}

void loop() {
	Serial.println("Testing CH375...");
	bool test = ch375.test();
	Serial.println(test ? "OK" : "ERROR");
	if (!test) {
		while (true) delay(1000);
	}
	//delay(1000);
}
