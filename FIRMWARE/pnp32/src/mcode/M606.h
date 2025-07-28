#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M606. Expects parameter S (0–255).
void handleM606(GCodeParser &GCode);