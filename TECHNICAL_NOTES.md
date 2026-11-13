# Technical Notes — Electrical and Control System

## Design context

The project sought to modify a battery-powered ride-on vehicle for accessible operation. The team's design specified two geared drive motors controlled through a RoboClaw 2x60A, with the Arduino Mega interpreting user input.

## Start/Stop Interface

The team technical document specifies **4N35 optocoupler** interfacing for the start/stop buttons:
- Start button → Arduino digital pin 2 through an optocoupler collector interface.
- Stop button → Arduino digital pin 3 through an optocoupler collector interface.

This locates the optocoupler circuit at the **input control interface**, not conclusively between the MCU and drive power supply. Electrical separation depends on the full ground and power topology; there is no published isolation-withstand verification in the reviewed records.

## Motor Control

- **Motor driver:** RoboClaw 2x60A dual channel.
- **MCU:** Arduino Mega.
- **Command architecture:** PWM and direction signals described in the technical document.
- **Motors:** Two geared drive motors listed as 24 V-rated.
- **Main power:** 12 V battery described in the design.

The difference between motor rating and supply voltage should be verified before making performance claims.

## Auxiliary Power and Protection

- Buck converter specified to supply auxiliary/control and steering hardware.
- Meeting notes dated February 21, 2025 describe an exercise adjusting converter output to **5 V with 9 V input**.
- A **40 A inline fuse** was included in the documented protection plan.
- Thermal management provisions include cooling hardware for drive/control power components.

## Design Targets vs Results

| Topic | Target or specification | Verified outcome in reviewed source? |
| --- | --- | --- |
| Speed control | 1–3 mph sequence | No speed test result identified |
| Stop button | Stop vehicle on command | No quantified response measurement identified |
| Optocoupler interface | 4N35 at start/stop inputs | Documented wiring, no isolation test result |
| Buck conversion | Regulated auxiliary supply | Meeting-reported 9 V → 5 V adjustment exercise |
| Power/motor integration | Early bench setup | Meeting-reported initial setup completion |
| Noise suppression | Potential design benefit | No before/after measurement identified |

## Engineering Limitations

This is a **documentation-focused project portfolio** and should not be used as a construction, safety certification or clinical mobility-device guide. Actual circuit design must be reviewed against approved schematics and as-built hardware before testing with a child or user.

[Back to README](README.md)
