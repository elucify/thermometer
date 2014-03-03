#include <OneWire.h>
#include <DallasTemperature.h>
#include <Thermometer.h>

// statics
OneWire Thermometer::_oneWire(THERMOMETERS_PIN);
DallasTemperature Thermometer::_sensors(&(Thermometer::_oneWire));

// ctor
Thermometer::Thermometer(DeviceAddress address, uint8_t resolution)
{
    // Remember the address of this device
    memcpy(_address, address, sizeof(DeviceAddress));
    _sensors.setResolution(address, resolution);
}

float Thermometer::getTemperature()
{
    float tempC = _sensors.getTempC(_address);

    // FIXME: Define MIN_TEMP as enum for namespace
    if (tempC <= MIN_TEMP) {
        Serial.print("Error getting temperature");
        return MIN_TEMP;
    }
    return DallasTemperature::toFahrenheit(tempC);
}
