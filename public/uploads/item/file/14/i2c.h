/*  Copy this header file to: C:\Program Files\SDCC\include\mcs51
    This has the functions to use the SMBus and functions for the LCD
	display and number pad.  */


/*  #include <stdio.h> this line should already be in your .c code */
#include <stdarg.h>
#include <stdlib.h>  /* this may alraedy be in your .c code  */
#include <string.h>

//------------------------------------------------------------------------------
// Value Definitions  - sometimes these are useful
//------------------------------------------------------------------------------

#define	TRUE	0x01			// Value representing TRUE
#define	FALSE	0x00			// Value representing FALSE
#define	ON		0x01			// Value representing ON
#define	OFF		0x00			// Value representing OFF
#define	HIGH	0x01			// Value representing ON
#define	LOW		0x00			// Value representing OFF


//------------------------------------------------------------------------------
// I2C Bus (SMBus) register bit definitions 
//------------------------------------------------------------------------------
/* The following lines are an example of setting up sbit names for the SMBus
   the c8051F020.h file creates the sbit names that are used in this code */

sbit at	0xC7	BUS_BUSY;		// SM Bus Busy (bit 7)
sbit at 0xC6	BUS_EN;			// SM Bus Enable (bit 6)
sbit at 0xC5	BUS_START;		// SM Bus Start (bit 5)
sbit at 0xC4	BUS_STOP;		// SM Bus Stop (bit 4)
sbit at 0xC3	BUS_INT;		// SM Bus Interrupt (bit 3)
sbit at 0xC2	BUS_AA;			// SM Bus ACK (bit 2)
sbit at 0xC1	BUS_FTE;		// SM Bus Clock timeout - high (bit 1)
sbit at 0xC0	BUS_TOE;		// SM Bus Clock timeout - low (bit 0)
sbit at 0x83	BUS_SCL;

//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------

#define DELAY_WRITE		5000			// approx. 5 ms delay write time (about 1000 cycles / ms)
#define DELAY_BLINK		50000			// Value for delay time - blink 

//-----------------------------------------------------------------------------
// Global VARIABLES
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------

#define high_byte(x)		((x & 0xFF00) >> 8)		//define a high byte as a shift right

extern void delay_time (unsigned long time_end);	//Delay function


extern void lcd_print(const char *fmt, ...);		//Print to LCD screen
extern void lcd_clear();							//Clear LCD screen

//extern void lcd_cursor(bit show);    //unused


extern void key_test();			//Test the functionality of the Keypad, unused

unsigned char i2c_read(void);
unsigned char i2c_stop_and_read(void);
void i2c_write(unsigned char output_data);
void i2c_write_and_stop(unsigned char output_data);
void i2c_write_data(unsigned char addr, unsigned char start_reg, unsigned char *buffer, unsigned char num_bytes);
void i2c_read_data(unsigned char addr, unsigned char start_reg, unsigned char *buffer, unsigned char num_bytes);
unsigned char i2c_read_and_stop(void);
void i2c_start(void);


void lcd_print(const char *fmt, ...)
{
	unsigned char len, i;			//assign counter variables
	unsigned static char xdata text[80];	//character array
	va_list ap;			//initilize a pointer

	if ( strlen(fmt) <= 0 ) return;	//If there is no data to print, return

	va_start(ap, fmt);		
	vsprintf(text, fmt, ap);	
	va_end(ap);

	len = strlen(text);			
	for(i=0; i<len; i++)
	{
		if(text[i] == (unsigned char)'\n')
			text[i] = 13;
	}

	i2c_write_data(0xC6, 0x00, text, len);

}




void lcd_clear()
{
	unsigned char NumBytes=0, Cmd[2];

	while(NumBytes < 64)
		i2c_read_data(0xC6, 0x00, &NumBytes, 1);

	Cmd[0] = 12;
	i2c_write_data(0xC6, 0x00, Cmd, 1);
}


char read_keypad()
{
	
	unsigned char i=0, Data[2];		//Initialize variables

	i2c_read_data(0xC6, 0x01, Data, 2);		//Read I2C data on address 192, register 1. 2 bytes of data.
	

	for(i=0; i<8; i++)						//loop 8 times
	{
		if(Data[0] & (0x01 << i))				//find the ascii value of the keypad reading.if it is the current loop value
			return i+49;			
	}

	if(Data[1] & 0x01)		//if the value is equal to 9 return 9.
		return '9';

	if(Data[1] & 0x02)		//if the value is equal to the star. 
		return '*';

	if(Data[1] & 0x04)		//if the value is equal to the 0 key
		return '0';

	if(Data[1] & 0x08)		//if the value is equal to the pound key
		return '#';

	return -1;
}


////////////////////////////////////////////////////////////////////////////////
// 	Routine:	delay_time
//	Inputs:		counter value to stop delaying
//	Outputs:	none
//	Purpose:	To pause execution for pre-determined time
////////////////////////////////////////////////////////////////////////////////
void delay_time (unsigned long time_end)
{
	unsigned long index;		//counter variable
	for (index = 0; index < time_end; index++);		//for loop delay
}


void i2c_start(void)
{
	while(BUSY);                                             //Wait until SMBus0 is free
	STA = 1;                                                 //Set Start Bit
	while(!SI);                                              //Wait until start sent
	STA = 0;                                                 //Clear start bit
	SI = 0;                                                  //Clear SI
}


void i2c_write(unsigned char output_data)
{
	SMB0DAT = output_data;                                   //Data to be written put into register
	while(!SI);                                              //Wait until send is complete
	SI = 0;                                                  //Clear SI
}

 

void i2c_write_and_stop(unsigned char output_data)
{
	SMB0DAT = output_data;                                   //Data to be written put into register
	STO = 1;                                                 //Set stop bit
	while(!SI);                                              //Wait until send is complete
	SI = 0;                                                  //clear SI
}

unsigned char i2c_read(void)
{
	unsigned char input_data;
	while(!SI);                                              //Wait until we have data to read
	input_data = SMB0DAT;                                    //Read the data
	SI = 0;                                                  //Clear SI
	return input_data;                                       //Return the read data
}


unsigned char i2c_read_and_stop(void)
{
	unsigned char input_data;
	while(!SI);                                              //Wait until we have data to read
	input_data = SMB0DAT;                                    //Read the data
	SI = 0;                                                  //Clear SI
	STO = 1;                                                 //Set stop bit
	while(!SI);                                              //wait for stop
	SI = 0;                                                                                         
	return input_data;                                       //Return the read data
}

void i2c_write_data(unsigned char addr, unsigned char start_reg, unsigned char *buffer, unsigned char num_bytes)
{
	unsigned char i;					//counter variable

	i2c_start();				//initiate I2C transfer
	i2c_write(addr & ~0x01);			//write the desired address to the bus
	i2c_write(start_reg);		//write the start register to the bus
	for(i=0; i<num_bytes-1; i++)		//write the data to the register(s)
		i2c_write(buffer[i]);
	i2c_write_and_stop(buffer[num_bytes-1]);		// Stop transfer
}

void i2c_read_data(unsigned char addr, unsigned char start_reg, unsigned char *buffer, unsigned char num_bytes)
{
    unsigned char j;
	i2c_start();											// Start I2C transfer
	i2c_write(addr & ~0x01);								// Write address of device that will be written to, send 0
	i2c_write_and_stop(start_reg);							// Write and stop the first register to be read
	i2c_start();											// Start I2C transfer
	i2c_write(addr | 0x01);									// Write address again, this time indicating a read operation
	for(j = 0; j < num_bytes - 1; j++)
	{
		AA = 1;												// Set acknowledge bit
		buffer[j] = i2c_read();								// Read data, save it in buffer
	}
	AA = 0;
	buffer[num_bytes - 1] = i2c_read_and_stop();			// Read the last byte and stop, save it in the buffer
} // end function 