# Archived Arduino Firmware Examples

The following **original Arduino sketches** were transcribed from four separate Go Baby Go project Google Docs. Their statements, constants, and logic were preserved rather than merged or repaired.

**These files are archived development examples, not a verified final firmware build. Do not upload them to an occupied or powered ride-on vehicle without engineering review, a safe bench setup, appropriate emergency stop hardware, and validation.**

## Source sketches

| File | Original source | Description |
| --- | --- | --- |
| [RoboClaw motor test](examples/roboclaw_motor_test/roboclaw_motor_test.ino) | *Motor driver (Robotclaw) code* | Arduino Mega Serial1 at 38400 baud; sends forward commands to both motors in `setup()` |
| [PWM/direction sample](examples/pwm_direction_test/pwm_direction_test.ino) | *Sample Code for PWM and Switch SET-UP* | Sets two direction outputs and two PWM outputs based on a digital toggle input |
| [Button prototype](examples/button_control_prototype/button_control_prototype.ino) | *Button Code:* | Early Go/Stop button counter; **incomplete C++** |
| [Servo example](examples/servo_potentiometer_test/servo_potentiometer_test.ino) | *Servo Code:* | Reads potentiometer on A0 and maps to servo angle |

## Critical limitations

- **RoboClaw example:** commands motion once in `setup()`; the `loop()` is empty. It has no stop-command logic or safety interlock. The source comment describes 54 as 50% speed on a 127-count scale, but 54/127 is about 43%; the comment is retained to reflect the source.
- **PWM example:** writes a maximum PWM value of 255 continuously and has no separate stop logic. It is a separate approach from the serial RoboClaw example, not proven to be the correct RoboClaw mode.
- **Button example:** the original source has an unmatched `else{}` after a standalone `if`, plus an incomplete stop-button implementation. It is intentionally preserved **as noncompiling source** rather than disguised as working firmware.
- **Servo example:** demonstrates a *potentiometer* input on A0, whereas the vehicle design calls for a *rotary encoder*. The Google Doc also contained a document heading, separator, and '/ C++ code' prose line; those non-code lines are excluded from the `.ino` file.
- **Pin conflicts:** the documents propose incompatible pin assignments if combined directly: Arduino pins 2/3 are assigned to start/stop optocouplers in the technical document, but pins 2/3 serve as motor direction outputs in the PWM sample; pin 9 is used by the PWM sample and servo example.
- No evidence was found of a merged final sketch, complete compilation, verified speed calibration, or integrated emergency-stop performance.

## Source and attribution

These examples were extracted from separate *Go Baby Go (2024–2025)* team-authored Google Drive documents. The code remains attributed to the **collaborative University of Houston Biomedical Engineering Society project**; individual authorship and licensing have not been established.

Only these requested code examples were copied; no full team reports, images, or other shared files were republished. If collaborators restrict redistribution, remove or replace the affected sketches with permission-cleared originals.

## Suggested future development

Create a separate `firmware/integrated/` design only after confirming final hardware pin mapping, RoboClaw operating mode, electrical protection, and permissions. Keep archival examples unchanged.

[Back to project README](../README.md)
