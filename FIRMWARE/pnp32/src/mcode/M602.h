#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M602. Expects parameter S (0–255).
void handleM602(GCodeParser &GCode);