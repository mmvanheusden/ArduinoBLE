#include "LeaphyBLE.h"
#include <ArduinoBLE.h>

#define LEAPHY_BLE_SERVICE_UUID "a3a671c0-a063-444d-86b9-34fd0255d897" // This Bluetooth service should be the same for all Leaphy devices. It can be used to separate them from other Bluetooth devices.

BLEService leaphyService(LEAPHY_BLE_SERVICE_UUID);

bool LeaphyBLE::initialize(const char *deviceName)
{
  if(!BLE.begin()) {
    return false;
  }

  BLE.setLocalName(deviceName);
  BLE.addService(leaphyService);
  BLE.setAdvertisedService(leaphyService);
  return true;
}