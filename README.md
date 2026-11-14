# Go Baby Go — Accessible Ride-On Vehicle Control System

**Assistive Technology · Embedded Systems · Motor Control · Power Electronics**

A collaborative University of Houston Biomedical Engineering Society (UH BMES) project (2024–2025) focused on adapting an electric ride-on vehicle for children with mobility impairments. The team's electrical architecture combined accessible control inputs, microcontroller-based motor commands, and regulated power distribution.

> **Project status:** This repository documents the team design and early setup/testing reported in the available records. It does **not** claim completed vehicle certification, verified speed performance, quantified electrical noise reduction, or final safety validation.

## Engineering Overview

The design integrates an **Arduino Mega** controller, **RoboClaw 2x60A** dual-channel motor driver, two geared DC drive motors, a DC-DC buck converter, and an accessible start/stop, speed, and steering console. **4N35 optocouplers** are specified at the *start/stop button input interfaces* to the Arduino.

### Design Goals

- Controlled speed selections in the **1–3 mph** range (**design target**, not measurement)
- Dedicated stop input, forward/reverse control and accessible steering
- Electrical interfacing between operator controls, MCU and drive electronics
- Regulated auxiliary power for control and steering electronics

## Hardware Architecture

| Component | Documented role |
| --- | --- |
| Arduino Mega | Reads operator inputs and issues drive/steering commands |
| RoboClaw 2x60A | Dual-channel motor driver |
| Two 24 V-rated geared DC motors | Rear-wheel propulsion |
| 12 V battery | Main supply in the documented design; final operating compatibility not verified |
| DC-DC buck converter | Lower-voltage auxiliary power |
| 4N35 optocouplers | Start/stop button input interfacing to the Arduino |
| Rotary encoder and controls | Steering and operator inputs |
| 40 A inline fuse | Specified battery-side protection |

**Engineering distinction:** Optocouplers at the control-input interface do not establish that the *motor supply* is galvanically isolated from the MCU. Isolation claims depend on the actual complete wiring and shared-ground topology.

## System Overview

```text
Accessible control console
  ├── Start/Stop ── 4N35 input interface ──┐
  ├── Speed / Direction ──────────────────┤
  └── Steering ───────────────────────────┤
                                          v
                                     Arduino Mega
                                       /       \
                              PWM / direction   Steering
                                    |             |
                               RoboClaw 2x60A    Servo
                                 /       \
                            DC Motor 1  DC Motor 2

12 V battery ── power distribution ── RoboClaw
                           └───────── buck converter ── auxiliary rails
```

*Conceptual block diagram only; not an as-built wiring schematic.*

## My Contributions

My contributions focused on **optocoupler-based control-input interfacing and supporting motor-control/power circuitry**, with attention to electrical integration and safety-oriented design. This was a team project; the broader design and implementation are not represented as solely my work.

## Documented Progress

- System and wiring design recorded for Arduino Mega, RoboClaw, 4N35 inputs, buck converter, drive motors and steering hardware.
- The February 21, 2025 meeting report states that initial power and motor setup was completed.
- That report describes a buck converter adjusted using a 9 V input to obtain a 5 V output.
- Detailed completed safety, noise-reduction or long-term reliability test results were not identified in the reviewed materials.

See [Technical Notes](TECHNICAL_NOTES.md), [System Architecture](docs/SYSTEM_ARCHITECTURE.md), [Project Status & Evidence](docs/PROJECT_STATUS.md), and **[Archived Arduino Firmware](firmware/README.md)**.

## Repository Contents

```text
.
├── README.md
├── TECHNICAL_NOTES.md
├── LICENSE-NOTES.md
├── .gitignore
├── docs/
│   ├── SYSTEM_ARCHITECTURE.md
│   └── PROJECT_STATUS.md
├── hardware/
│   └── README.md
└── firmware/
    └── README.md
```

This public repository contains **attributed engineering documentation and four archived Arduino development sketches** transcribed from team documents. These examples are **not a verified or integrated final firmware build**. The original shared Drive reports, images, and CAD files have not been republished.

## Skills Demonstrated

Arduino · Motor Control · Optocouplers · Electrical Interfacing · PWM · Power Regulation · Hardware Integration · Assistive Technology · Technical Documentation

## Portfolio

[Return to Leziga's Electrical Engineering Portfolio](https://github.com/LezBe/Leziga_Portfolio)
