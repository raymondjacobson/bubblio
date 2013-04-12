/*
    Section:
    Date:
    File name:
    Program description:
*/

#include <c8051_SDCC.h>
#include <stdio.h>

/* Global Variables */

unsigned int desired = 0;           // set this value
unsigned int actual = 0;            // set this value
unsigned int kp = 0;                // set this value
unsigned int kd = 0;                // set this value
int pw_neut = 0;                    // set this value
int previous_error = 0;             // set this value
int error = 0;                      // set this value
int temp_motorpw_2byte = 0;
long temp_motorpw_alg1 = 0;
long temp_motorpw_alg2 = 0;
long temp_motorpw_alg3 = 0;
long temp_motorpw_alg4 = 0;
long temp_motorpw_alg5 = 0;
long temp_motorpw_alg6 = 0;

void main()
{
    Sys_Init();
    putchar(' ');
    error = desired-actual;
//  two byte calculation
    temp_motorpw_2byte = pw_neut+kp*error+kd*(error-previous_error);
    printf("The two byte calculation of motorpw is %d \r\n",temp_motorpw_2byte);
//  equation form 1, long ints
    temp_motorpw_alg1 = pw_neut+kp*error+kd*(error-previous_error);
    printf("Algorithm 1, four byte calculation of motorpw is %ld \r\n",temp_motorpw_alg1);
//  equation form 2, long ints
    temp_motorpw_alg2 = pw_neut+(long)kp*error+kd*(error-previous_error);
    printf("Algorithm 2, four byte calculation of motorpw is %ld \r\n",temp_motorpw_alg2);
//  equation form 3, long ints
    temp_motorpw_alg3 = (long)( pw_neut + kp * (error) + kd * (error - previous_error));
    printf("Algorithm 3, four byte calculation of motorpw is %ld \r\n",temp_motorpw_alg3);
//  equation form 4, long ints
    temp_motorpw_alg4 = pw_neut+kp*(int)(error)+kd*(int)(error-previous_error);
    printf("Algorithm 4, four byte calculation of motorpw is %ld \r\n",temp_motorpw_alg4);
//  equation form 5, long ints
    temp_motorpw_alg5 = (long)pw_neut+(long)(kp*(error))+(long)(kd*(error-previous_error));
    printf("Algorithm 5, four byte calculation of motorpw is %ld \r\n",temp_motorpw_alg5);
//  equation form 6, long ints
    temp_motorpw_alg6 = (long)pw_neut+(long)kp*(long)error+(long)kd*(long)(error-previous_error);
    printf("Algorithm 6, four byte calculation of motorpw is %ld \r\n",temp_motorpw_alg6);
}
