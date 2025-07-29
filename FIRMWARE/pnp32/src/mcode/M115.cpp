#include "M115.h"
#include <Arduino.h>
#include "config.h"

void handleM115(GCodeParser &GCode) {
  char detect_firmware[256];
  snprintf(detect_firmware, sizeof(detect_firmware),
           "FIRMWARE_NAME:%s %s SOURCE_CODE_URL:%s PROTOCOL_VERSION:%s MACHINE_TYPE:%s EXTRUDER_COUNT:%d UUID:%s",
           FIRMWARE_NAME,
           FIRMWARE_VERSION,
           SOURCE_CODE_URL,
           PROTOCOL_VERSION,
           MACHINE_TYPE,
           EXTRUDER_COUNT,
           FIRMWARE_UUID 
  );
  Serial.println(detect_firmware);
  Serial.println(COMMAND_CONFIRM_REGEX);

}
