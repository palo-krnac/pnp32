#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M605. Expects parameter S (0–255).
void handleM605(GCodeParser &GCode);