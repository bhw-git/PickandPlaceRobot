# PickandPlaceRobot
P&P Robot (5 DOF Pick and Place Robot)

Overview:-
- This project controls a 5 DOF pick-and-place robotic arm (plus gripper) via a custom Bluetooth mobile app.
- The app allows manual control, teaching (saving) positions, and automatic playback of saved sequences.
- The robot uses external SMPS power for stable servo operation.

Features:-
Manual control of:
- Gripper Arm
- Pitch Arm
- Roll Arm
- Elbow Arm
- Shoulder Arm
- Waist Arm

- Save button: Store current servo positions (up to 50 steps).
- Run button: Play saved positions in sequence.
- Stop button: Halt playback at any time.
- Speed control: Increase or decrease motion delay.

Hardware RequirementsL:-
- Arduino (Uno – tested with Uno)
- 6x Servo motors (e.g., MG996R & SG90)
- Bluetooth module (HC-05)
- External SMPS (230V AC → 12V DC)
- Voltage regulators (one per servo motor)
- Jumper wires & breadboard (as needed)

Wiring:-
Servo	Arduino Pin
- Waist Arm	          Pin 7
- Shoulder Arm	      Pin 5
- Elbow Arm	          Pin 6
- Roll Arm	          Pin 9
- Pitch Arm	          Pin 10
- Gripper	            Pin 11
- Bluetooth TX	      Pin 0 (RX)
- Bluetooth RX	      Pin 1 (TX)

<img width="954" height="865" alt="image" src="https://github.com/user-attachments/assets/7c8c4cec-1a75-4d13-aaba-994c5557bcbf" />

⚠ Important:
- Servos are powered from an external SMPS with voltage regulators.
- You cannot power all servos directly from Arduino — The output current of the arduino board is insufficient for the servo motors to lift the load.

Custom mobile app with:
-Bluetooth Connect / Disconnect

Two buttons per axis (clockwise & counterclockwise movement)
- Save
- Run
- Stop
- Speed + / Speed -

How to Use:-
- Connect Bluetooth from the app to the Arduino.
- Manually move each servo to the desired position using control buttons.
- Press Save to store the current position.
- Repeat steps 2–3 to save multiple steps (up to 50).
- Press Run to execute the saved sequence.
- Press Stop to halt playback.
- Adjust speed using Speed+ / Speed- buttons.

Code Notes:-
- All saved positions are stored in:
cpp

Playback is loop-based and stops immediately when the Stop button is pressed.
int savedPositions[50][6];

Speed variable adjusts delay between movements.

License
This project is open-source. You may use and modify it for personal or educational purposes.
