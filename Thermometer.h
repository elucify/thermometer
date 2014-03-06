#ifndef __THERMOMETER_H
#define __THERMOMETER_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "TemperatureSensors.h"

// Default resolution 10 bits
#define THERMOMETER_RESOLUTION (10)
#define MIN_TEMP (-127.00)

// Onewire pin
#define THERMOMETERS_PIN (6)

class Thermometer {

 public:

    Thermometer(DeviceAddress address, uint8_t resolution = THERMOMETER_RESOLUTION);

    float getTemperature();

    // Onewire address
    //    DeviceAddress& getAddress();
    //    void setAddress(DeviceAddress& address);

 protected:
    DeviceAddress _address;
    static boolean _sensors_initialized;
    static OneWire _oneWire;
    static DallasTemperature _sensors;
};

#endif
