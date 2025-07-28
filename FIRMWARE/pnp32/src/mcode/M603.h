#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M603. Expects parameter S (0–255).
void handleM603(GCodeParser &GCode);