#include "cpu_6502.h"

extern uint8_t curkey;
extern uint8_t RAM[RAM_SIZE];

void serout(uint8_t val)
{
	Serial.write(val);
}

uint8_t getkey(void)
{
	return(curkey);
}

void clearkey(void)
{
	curkey = 0;
}

void printhex(uint16_t val)
{
	Serial.print(val, HEX);
	Serial.println();
}

void setup()
{
    Serial.begin(115200);

    //PSRAM Initialisation
    if(psramFound() != false)
    {
        Serial.println("[APP] : PSRAM Founds");
        if (psramInit() != false) {
            Serial.println("[APP] : PSRAM Inited");
        } else {
            Serial.println("[ERR] : PSRAM does not work");
        }
    }else{
        Serial.println("[ERR] : PSRAM Dose not Founds!");
    }

#ifndef EnBASIC_6502_USE
    memset(&RAM[0], 0x00, sizeof(RAM_SIZE));
    Serial.println("[APP] : 6502 Emulator on ESP32 Ver1.0.0 by mqyoiInu");
#else
    Serial.println("[APP] : 6502 Emulator And EnBASIC V2.22 Run on ESP32 Ver1.0.0 by mqyoiInu");
#endif

    // (DEBUG)
    log_d("[LOG]:6502 RAM Size = %d(define = %d)\n", sizeof(RAM), RAM_SIZE);

    reset6502();
}

void loop()
{
    exec6502(100); //if timing is enabled, this value is in 6502 clock ticks. otherwise, simply instruction count.

    if (Serial.available()) {
      curkey = Serial.read() & 0x7F;
    }
}

