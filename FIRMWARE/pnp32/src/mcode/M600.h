#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M600. Očakáva parameter S (0–255).
void handleM600(GCodeParser &GCode);