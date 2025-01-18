#include <LeaphyBLE.h>
#include <ArduinoBLE.h>

LeaphyBLE LeaphyBLE;
void onBluetoothConnection(BLEDevice device) {
  Serial.println("Hello!");
}

void onBluetoothDisconnection(BLEDevice device) {
  Serial.println("Bye!");
}

void leaphyProgram() {
  BLE.setEventHandler(BLEConnected, onBluetoothConnection);
  BLE.setEventHandler(BLEDisconnected, onBluetoothDisconnection);
  LeaphyBLE.addBinaryCharacteristic("LED", true);
  LeaphyBLE.addStringCharacteristic("DISPLAY", "Hello");
  LeaphyBLE.getCharacteristicByName("LED")->setEventHandler(BLEWritten, [](BLEDevice central, BLECharacteristic characteristic) {
    Serial.println(*LeaphyBLE.getCharacteristicByName("LED")->value() == 1);
  });
  LeaphyBLE.getCharacteristicByName("DISPLAY")->setEventHandler(BLEWritten, [](BLEDevice central, BLECharacteristic characteristic) {
    Serial.println((char *)LeaphyBLE.getCharacteristicByName("DISPLAY")->value());
  });
  LeaphyBLE.initialize("Leaphy");
}

void setup() {
	Serial.begin(115200);
  leaphyProgram();
}

void loop() {
  BLE.poll();
}