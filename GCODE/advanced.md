
---

### ✅ `advanced.md`

```markdown
# 🟠 Advanced G-code Commands

## Tuning motion

| Command | Description                           | Example                   |
|-----------|-------------------------------------|---------------------------|
| M350    | Microstepping                      | `M350 X16 Y16 Z32`      |
| M906    | Motor current (mA)             | `M906 X1000 Y1000`    |
| M92     | Steps per mm                    | `M92 X80 Y80 Z400`   |
| M569   | Driver direction invert    | `M569 X0 Y1`         |

---

## Example

```gcode
M350 X16 Y16
M906 X800 Y800
M92 X80 Y80 Z400
