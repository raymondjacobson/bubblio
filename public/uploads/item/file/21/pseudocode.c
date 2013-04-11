// PSEUDOCODE - Lab 5
// Brigid Angelini, Laura Curro, Galen Scrhetlen, Raymond Jacobson


function declarations
global variables
main
	while(1)
		check slide switch
		display PickDriveGain on LCD
		read drive inputs
		setDriveGain
		display PickSteerGain on LCD
		read steer inputs
		setSteerGain
		if LCD timer
			display x and y accelerations
			if (LCDinput = 'i') GainConst+=interval
				if (GainConst > max) GainConst = max
			if (LCDinput = 'd') GainConst-=interval
				if (GainConst < min) GainConst = min
			if (LCDinput = 'c') GainConst = default
		if 20ms
			update accelerometer
			startDriveSteer
	endwhile
endmain

update accelerometer
	Clear the averages avg_gx = 0; avg_gy = 0;
	For 8 iterations (or maybe 16)
		Wait one 20ms cycle to avoid hitting the SMB too frequently and locking it up
		Read status_reg_a into Data[0] (register 0x27, status_reg_a, indicates when data is ready)
		Make sure the 2 LSbits are high: (Data[0] & 0x03) == 0x03
		Read 4 registers starting with 0x28
			i2c_read_data(addr_accel, 0x28|0x80, Data, 4);
		avg_gy += ((Data2[3] << 8 | Data2[2]) >> 4);
	Done with 8 iterations
	Finish calculating averages.
		avg_gx = avg_gx/8 (or use >> 3 for faster execution)
		avg_gy = avg_gy/8 (or use >> 3 for faster execution)
	Set global variables and remove constant offset, if known.
		gx = avg_gx (or = avg_gx - x0 if nominal gx offset is known)
		gy = avg_gy (or = avg_gy - y0 if nominal gy offset is known)

startDriveSteer
	steering_pw = steering_pw_center - ks * gx (ks is the steering feedback gain)
	drive_pw = drive_pw_neutral + kdy * gy
	drive_pw += kdx * abs(gx) (kdx is the x-axis drive feedback gain)