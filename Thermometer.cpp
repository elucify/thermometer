#include <OneWire.h>
#include <DallasTemperature.h>
#include <Thermometer.h>

// statics
OneWire Thermometer::_oneWire(THERMOMETERS_PIN);
DallasTemperature Thermometer::_sensors(&(Thermometer::_oneWire));
boolean Thermometer::_sensors_initialized = false;


// To assign the addresses of your 1-Wire temp sensors,
// see the tutorial on how to obtain these addresses:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html

// ctor
Thermometer::Thermometer(DeviceAddress address, uint8_t resolution)
{
    // Initialize sensors
    if (!_sensors_initialized) {
        _sensors_initialized = true;
        _sensors.begin();
    }

    // Remember the address of this device
    memcpy(_address, address, sizeof(DeviceAddress));
    _sensors.setResolution(address, resolution);
}

float Thermometer::getTemperature()
{
    _sensors.requestTemperatures();

    float tempC = _sensors.getTempC(_address);

    // FIXME: Define MIN_TEMP as enum for namespace
    if (tempC <= MIN_TEMP) {
        //        Serial.print("Error getting temperature");
        return MIN_TEMP;
    }
    return DallasTemperature::toFahrenheit(tempC);
}
