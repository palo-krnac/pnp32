## Air blower codes

### M8 - air blower enable
| Command | Parameter | Description         |
|---------|-----------|---------------------|
| M8      | Pn        | air ON              |

Examples

    M8 P1   ; enable air blower P1

### M9 - air blower disable
| Command | Parameter | Description         |
|---------|-----------|---------------------|
| M9      | Pn        | air OFF             |

Examples

    M9 P1   ; disable air blower P1

## Vacuum codes

### M10 - vacuum pump enable
| Command | Parameter | Description         |
|---------|-----------|---------------------|
| M10     | Pn        | vacuum ON           |

Examples

    M10 P1   ; enable vacuum pump P1

### M11 - vacuum pump disable
| Command | Parameter | Description         |
|---------|-----------|---------------------|
| M11     | Pn        | vacuum OFF           |

Examples

    M11 P1   ; disable vacuum pump P1

## Solenoids codes

### M380 - enable solenoids
| Command | Parameter | Description         |
|---------|-----------|---------------------|
| M380    | Sn        | solenoid ON         |

Examples

    M380 P1   ; set pump to No.1 nozzle

### M381 - disable solenoids
| Command | Parameter | Description         |
|---------|-----------|---------------------|
| M380    | Sn        | solenoid OFF        |

Examples
 
    M381 P1   ; set pump to No.1 nozzle

## Lights codes

### M150 - set led color

|Command  | Parameter | Description         |
|---------|-----------|---------------------|
| M150    | Rnnn      | Red component       |
| M150    | Unnn      | Green component     |
| M150    | Bnnn      | Blue component      |
| M150    | Wnnn      | White component     |
| M150    | Pnnn      | Brightness (0–255)  |
| M150    | Snnn      | Number of individual LEDs to set to these colours|
| M150    | Fn        | Following command action. F0 (default) means this is the last command for the LED strip, so the next M150 command starts at the beginning of the strip. F1 means further M150 commands for the remainder of the strip follow this one. |

Examples

    M150 R255 P128 S20 F1    ; set first 20 LEDs to red, half brightness, more commands for the strip follow
    M150 U255 B255 P255 S20  ; set next 20 LEDs to cyan, full brightness, finished programming LED strip

## Sounds codes

### M300 - play beep sound

|Command  | Parameter | Description              |
|---------|-----------|--------------------------|
| M300    | Snnn      | frequency in Hz          |
| M300    | Pnnn      | duration in millisecond  |
| M300    | Vnnn      | volume in rage 0 - 1     |

Examples

    M300 P153 S659 ; MUSIC Start
    M300 P149 S659
    M300 P148 S0
    M300 P148 S659
    M300 P154 S0
    M300 P149 S523
    M300 P148 S659
    M300 P149 S0
    M300 P154 S784 ; MUSIC END