# ROV-Control-2019
Code for 2019 ROV competition.

# Organisation of Code
Each area of the system generally is kept as its own file containing various functions which can then be called 
upon by the main program - for example communications between surface and onboard is its own file. A set of 
programs in the onboard and surface folders are called upon by the corresponding main program. This way the 
code is organised and each area is kept seperate. Use the development folder to keep and work on new modules 
of code which are yet to be integrated to the main programs.

Log any changes to the main program in the changelog.

# Current Goals
- Implement control input from controller (Tim)
- Produce mathematical model for control algorithm and implement as code (Fraser)
- Produce hardware and software for a simple information display / menu (unassigned)

# Completed Goals
- Implement communications protocol between onboard and surface microcontrollers
- Write a simple test program for ESCs to check they all work
