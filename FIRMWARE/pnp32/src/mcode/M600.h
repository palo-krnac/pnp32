#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M600. Expects parameter S (0–255).
void handleM600(GCodeParser &GCode);