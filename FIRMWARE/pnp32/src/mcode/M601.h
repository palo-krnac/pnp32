#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M601. Expects parameter S (0–255).
void handleM601(GCodeParser &GCode);