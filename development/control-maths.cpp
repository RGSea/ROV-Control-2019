// general
	everything works based on percentage speeds
	+100 is 100% forwards
	-100 is 100% reverse


// layout

   (FL_H)      (FR_H)
        --------
(FL_V) |        | (FR_V)
       |        |
       |        |
       |        |
       |        |
(BL_V) |        | (BR_V)
		--------
   (BL_H)      (BR_H)


// control input

        (L2)		 (L1)
        (L1)         (R1)

         U            Y
       L   R        X   B
         D            A

           (Lx)  (Rx)
           (Ly)  (Ry)

Axes:
	Lx - axis - left joystick x coordinate - this axis controls x translation
	Ly - axis - left joystick y coordinate - this axis controls y translation
	Rx - axis - right joystick x coordinate - this axis controls roll
	Ry - axis - right joystick y coordinate - this axis controls pitch
	L2 - axis - left single axis trigger value - this axis controls altitude, used to descend
	R2 - axis - right single axis trigger value - this axis controls altitude, used to climb
	LB - axis - upper left single axis trigger - this axis controls yaw to the left
	RB - axis - upper right single axis trigger - this axis controls yaw to the right

Buttons:
	LT - left button
	RT - right button
	LB - left upper button
	RB - right upper button
	U  - up button on d-pad
	D  - down button on d-pad
	L  - left button on d-pad
	R  - right button on d-pad
	X  - x button
	Y  - y button
	A  - a button
	B  - b button

Data:
	Buttons will have a state of 1 when pressed and 0 when not pressed
	Dual axes follow a cartesian coordinate system with range -100 to +100
	Single axes have a value from 0 to +100


//////////////////////////
// vertical pseudo-code //
//////////////////////////


// merge vertical controls
int alt = RT - LT;
int roll = Rx;
int pitch = Ry;

// add altitude to all, add roll to left side and subtract from right side, subtract pitch from front and add to rear
int speedFL_V = alt + roll - pitch;
int speedFR_V = alt - roll - pitch;
int speedBL_V = alt + roll + pitch;
int speedBR_V = alt - roll + pitch;


// translation speeds (yaw to be added), 

int speedFR_H = Lx - Ly;
int speedFL_H = (-Ly - Lx)/2;
int speedBR_H = (Lx + Ly)/2 ;
int speedBL_H = Ly - Lx ;




























