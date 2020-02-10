#include <Arduino.h>
#define ON   0
#define OFF  1

class PumpController {
    public:
    int pump_1_pin = 0;
    int pump_2_pin = 0;
    int pump_3_pin = 0;
    int pump_4_pin = 0;

    PumpController(int pump_1_pin, int pump_2_pin, int pump_3_pin, int pump_4_pin ){
        this->pump_1_pin = pump_1_pin;
        this->pump_2_pin = pump_2_pin;
        this->pump_3_pin = pump_3_pin;
        this->pump_4_pin = pump_4_pin;

        pinMode(this->pump_1_pin, OUTPUT);
        pinMode(this->pump_2_pin, OUTPUT);
        pinMode(this->pump_3_pin, OUTPUT);
        pinMode(this->pump_4_pin, OUTPUT);
        this->set_status(OFF,OFF,OFF,OFF);
    };

    void set_status(unsigned char status_1, unsigned char status_2, unsigned char status_3,unsigned char status_4){
        digitalWrite(this->pump_1_pin, status_1);
        digitalWrite(this->pump_2_pin, status_2);
        digitalWrite(this->pump_3_pin, status_3);
        digitalWrite(this->pump_4_pin, status_4);
    };

};