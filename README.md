# SmartTrafficSignalController
SmartTrafficSignalController
📘 Smart Traffic Signal Controller (C → Embedded C Project)
Overview
This project is a console-based Smart Traffic Signal Controller developed in C and later extended using Arduino and Embedded C.
The project simulates traffic management at road intersections and gradually evolves into a smart traffic system capable of handling:
•	Traffic signal operations
•	Traffic density management
•	Pedestrian crossing requests
•	Emergency vehicle prioritization
•	Vehicle detection sensors
•	Adaptive signal control
________________________________________
Learning Goals
C Programming
•	Structures (struct)
•	Functions
•	File Handling
•	State Machines
•	Simulation Design
•	Data Processing
Embedded C
•	GPIO
•	LED Control
•	Button Inputs
•	Serial Communication
•	EEPROM
•	Interrupts
•	Sensor Interfacing
•	Real-Time Decision Making
________________________________________
Project Roadmap
________________________________________
Problem Set 1: Traffic Signal Display
Features
•	Display RED signal
•	Display GREEN signal
•	Display YELLOW signal
Improvement
•	Show current active signal status continuously
Skills Covered
•	Variables
•	Console Output
•	Program Structure
________________________________________
Problem Set 2: Signal Transition System
Features
•	Automatic signal sequence
RED
↓
GREEN
↓
YELLOW
↓
RED
Improvement
•	Run continuously for multiple cycles
Skills Covered
•	Loops
•	Control Flow
________________________________________
Problem Set 3: Custom Signal Timings
Features
•	User enters: 
o	Red duration
o	Green duration
o	Yellow duration
Improvement
•	Validate timing values
Skills Covered
•	Input Handling
•	Validation
________________________________________
Problem Set 4: Signal Countdown Timer
Features
•	Display remaining signal time
Example:
GREEN : 10
GREEN : 9
GREEN : 8
Improvement
•	Show countdown for all signals
Skills Covered
•	Nested Loops
•	Timer Logic
________________________________________
Problem Set 5: Modular Signal Controller
Features
•	Separate logic for: 
o	Red Signal
o	Green Signal
o	Yellow Signal
Improvement
•	Reusable functions
Skills Covered
•	Functions
•	Modular Programming
________________________________________
Problem Set 6: Traffic Statistics
Features
Track:
•	Total cycles
•	Total green duration
•	Total red duration
•	Total yellow duration
Improvement
•	Display statistics report
Skills Covered
•	Counters
•	Data Tracking
________________________________________
Problem Set 7: Four-Way Junction Simulation
Features
Manage signals for:
•	North Road
•	South Road
•	East Road
•	West Road
Improvement
•	Independent road control
Skills Covered
•	Structures
•	State Management
________________________________________
Problem Set 8: Vehicle Density Simulation
Features
Store vehicle count for each road.
Example:
Road A = 25 Vehicles
Road B = 10 Vehicles
Improvement
•	Simulate changing traffic volumes
Skills Covered
•	Arrays
•	Data Modeling
________________________________________
Problem Set 9: Dynamic Signal Allocation
Features
•	Increase green time for busy roads
•	Reduce green time for less busy roads
Improvement
•	Automatic signal optimization
Skills Covered
•	Decision Making
•	Resource Allocation
________________________________________
Problem Set 10: Pedestrian Crossing System
Features
•	Allow pedestrian crossing request
Improvement
•	Safe crossing interval
Skills Covered
•	State Transitions
•	Event Handling
________________________________________
Problem Set 11: Emergency Vehicle Priority
Features
•	Emergency request activation
•	Immediate green signal allocation
Improvement
•	Priority override system
Skills Covered
•	Priority Scheduling
•	Event Management
________________________________________
Problem Set 12: Traffic Log System
Features
Store:
•	Vehicle counts
•	Signal timings
•	Events
Improvement
•	Historical traffic records
Skills Covered
•	File Handling
•	Data Persistence
________________________________________
Problem Set 13: Traffic Dashboard
Features
Display:
•	Active Road
•	Signal Status
•	Vehicle Count
•	Current Cycle
Improvement
•	Summary analytics
Skills Covered
•	Reporting
•	Data Processing
________________________________________
Embedded Extension Roadmap
________________________________________
Problem Set 14: LED Traffic Signal Controller
Features
Use LEDs as:
•	Red Signal
•	Yellow Signal
•	Green Signal
Improvement
•	Real hardware implementation
Skills Covered
•	GPIO
•	Arduino Basics
________________________________________
Problem Set 15: Hardware Traffic Sequencing
Features
•	Implement complete traffic sequence using LEDs
Improvement
•	Match software simulation behavior
Skills Covered
•	Embedded Logic
•	Timing Control
________________________________________
Problem Set 16: Serial Monitoring
Features
Display signal status on Serial Monitor
Improvement
•	Real-time monitoring
Skills Covered
•	UART Communication
________________________________________
Problem Set 17: Runtime Configuration
Features
Change timings using Serial Monitor
Improvement
•	Dynamic configuration
Skills Covered
•	Serial Input Processing
________________________________________
Problem Set 18: EEPROM Storage
Features
Save signal timings permanently
Improvement
•	Load values after restart
Skills Covered
•	EEPROM
•	Persistent Memory
________________________________________
Problem Set 19: Pedestrian Push Button
Features
•	Request pedestrian crossing using switch
Improvement
•	Queue crossing requests
Skills Covered
•	Digital Inputs
________________________________________
Problem Set 20: Traffic Alert Buzzer
Features
•	Audio indication during crossing
Improvement
•	Warning alerts
Skills Covered
•	Actuator Control
________________________________________
Problem Set 21: Emergency Override Switch
Features
•	Emergency vehicle simulation
Improvement
•	Immediate signal switching
Skills Covered
•	Priority Handling
________________________________________
Problem Set 22: Interrupt-Based Emergency Detection
Features
•	Detect emergency request using interrupts
Improvement
•	Faster response system
Skills Covered
•	Interrupts
•	Real-Time Embedded Systems
________________________________________
Problem Set 23: Vehicle Detection System
Features
•	Detect vehicles using IR sensors
Improvement
•	Track road occupancy
Skills Covered
•	Sensor Interfacing
________________________________________
Problem Set 24: Vehicle Counting System
Features
•	Count passing vehicles
Improvement
•	Road-wise statistics
Skills Covered
•	Sensor Processing
________________________________________
Problem Set 25: Smart Traffic Density Analysis
Features
•	Calculate traffic density from sensor data
Improvement
•	Real-time traffic analysis
Skills Covered
•	Embedded Algorithms
________________________________________
Problem Set 26: Adaptive Traffic Signal Controller
Features
•	Automatically adjust signal timings
Improvement
•	Smart traffic management
Skills Covered
•	Real-Time Decision Making
•	Embedded Control Logic
________________________________________
Skills Covered
C Programming
•	Variables
•	Functions
•	Arrays
•	Structures
•	File Handling
•	State Management
•	Data Processing
Software Design
•	Simulation Development
•	Event Handling
•	Traffic Modeling
•	Reporting Systems
Embedded C
•	GPIO
•	UART
•	EEPROM
•	Interrupts
•	Sensors
•	Timing Control
•	Real-Time Systems
Arduino
•	LED Control
•	Buttons
•	Buzzer
•	IR Sensors
•	Serial Communication
•	Hardware Integration
________________________________________
Expected Progression
Problem Sets 1–6 → Beginner C
Problem Sets 7–13 → Intermediate C
Problem Sets 14–20 → Beginner Embedded C
Problem Sets 21–26 → Intermediate Embedded C

