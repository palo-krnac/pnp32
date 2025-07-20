
##G0 & G1: Move

###Description

Add a straight line movement to the planner.

- **G0**: Rapid Move (fast, non-precise)
- **G1**: Linear Move (controlled, precise)

---

###Usage

G0 Xnnn Ynnn Znnn Ennn Fnnn Snnn
G1 Xnnn Ynnn Znnn Ennn Fnnn Snnn


---

###Parameters

| Parameter | Description                                                    |
|-------------|----------------------------------------------------------------|
| Xnnn       | Target position on the X axis                           |
| Ynnn       | Target position on the Y axis                           |
| Znnn       | Target position on the Z axis                           |
| Ennn      | Amount to extrude between start and end           |
| Fnnn      | Feedrate (mm/min) for the move                       |
| Hnnn     | Endstop check flag (RepRapFirmware)            |
| Rnnn     | Restore point number (RepRapFirmware)     |
| Snnn     | Laser power or similar (context-specific)  |

> ℹ️ **Note:** Not all parameters are required, but at least one position parameter must be specified.

---

###Examples

```gcode
G0 X12               ; Move rapidly to X = 12 mm
G0 F1500             ; Set rapid feedrate to 1500 mm/min
G1 X90.6 Y13.8 E22.4 ; Move and extrude

## G21

## G90

## G92
## M114

## M115
