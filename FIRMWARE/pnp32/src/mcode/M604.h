#pragma once
#include <GCodeParser.h>
#include "config.h"

// Handler for M604. Expects parameter S (0–255).
void handleM604(GCodeParser &GCode);