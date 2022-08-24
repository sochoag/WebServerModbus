#include <Arduino.h>

#include "AsyncWebHandlerCustom.h"
#include "ModbusHandleCustom.h"
#include "WifiManagerCustom.h"

void setup()
{
  Serial.begin(115200);
  if(WiFisetup())
  {
    AWebSetup();
  }
  ModbusSetup();
}

void loop()
{
  ModbusLoop();
}