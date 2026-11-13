# System Architecture

## Functional Interfaces

| Source | Destination | Purpose | Evidence level |
| --- | --- | --- | --- |
| Start/stop buttons | 4N35 interface → Arduino Mega | User commands | Specified in wiring instructions |
| Arduino Mega | RoboClaw PWM/direction inputs | Drive control | Specified in wiring instructions |
| RoboClaw | Geared DC motors | Traction power | Design documentation |
| Battery | RoboClaw and buck converter | Power distribution | Design documentation |
| Buck converter | Steering and control electronics | Auxiliary regulated voltage | Design documentation |
| Steering control | Arduino → servo | Directional control | System-level description |

## Signal Flow

```text
Operator input ──────> Arduino Mega ──────> motor driver ──────> motors
      |                      |
  4N35 interface         steering command ──────> servo
  (start/stop)
```

## Interpretation

The optocoupler interface is documented for the start and stop button signals. The source materials do not establish complete galvanic isolation of the motor supply or a verified circuit-level isolation rating. This page is **not a final schematic**.

[Back to README](../README.md)
