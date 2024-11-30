#ifndef _LEAPHY_BLE_H
#define _LEAPHY_BLE_H

#include <ArduinoBLE.h>
class LeaphyBLE
{
public:
  bool initialize(const char *deviceName);
  BLEBoolCharacteristic addBinaryCharacteristic(const char *name, bool initialValue);
};

#endif
