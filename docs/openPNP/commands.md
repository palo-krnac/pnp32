# Default

## CONNECT_COMMAND

    G21 ; Set millimeters mode
    G90 ; Set absolute positioning mode

## ENABLE_COMMAND

    G21 ; Set millimeters mode
    G90 ; Set absolute positioning mode
    M82 ; extruder in absolute mode
    M300 P153 S659 ; MUSIC Start
    M300 P149 S659
    M300 P148 S0
    M300 P148 S659
    M300 P154 S0
    M300 P149 S523
    M300 P148 S659
    M300 P149 S0
    M300 P154 S784 ; MUSIC END

## DISABLE_COMMAND

    M114; Report position
    M84; DISABLE MOTORS

## HOME_COMMAND

    M300 P149 S400; Beep
    G1 A0 B0; Rotate A B nozzles to 0°
    M400;
    M114; Report position
    M84; Disable motors
    G4 P1000; Pause 1.0s
    M204 S1000; Set homing acceleration
    G28 X Y A B; Homing X Y A B
    M400; Finish moves
    G92 X0 Y352 A0 B0; Set X Y A B home position
    M114; Report redefined position
    G1 X95 Y334 F12000; Move X Y to safe zone where nozzle can go to the lowest point.
    G28 Z; Homing Z
    G1 Z1.2; Move Z to middle height(Adjust if needed)
    M400; Finish moves
    G92 Z0 ; Set current Z height to 0(Middle)
    M114; Report redefined position
    G1 Z0; Move Z to middle height
    M400; Finish moves
    G92 Z0; Set Z home position to 0
    M114; Report redefined position

## COMMAND_CONFIRM_REGEX

    ^ok.*

## POSITION_REPORT_REGEX

    ^.*X:(?<X>-?\d+\.\d+) Y:(?<Y>-?\d+\.\d+) Z:(?<Z>-?\d+\.\d+) A:(?<A>-?\d+\.\d+) B:(?<B>-?\d+\.\d+).*

## COMMAND_ERROR_REGEX

    ^ok.*

