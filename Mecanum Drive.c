#pragma config(Motor,  port2,           backLeft,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeft,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           backRight,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           frontRight,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           shooterLift,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           leftShooter,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           rightShooter,  tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Mecanum Drive - Basic
- This program allows you to remotely control a robot with mecanum wheels.
- The left joystick Y-axis controls the robot's forward and backward movement.
- The left joystick X-axis controls the robot's left and right movement.
- The right joystick X-axis controls the robot's rotation.

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        frontRight          VEX Motor             Front Right motor -2
Motor Port 3        backRight           VEX Motor             Back Right motor -5
Motor Port 4        frontLeft           VEX Motor             Front Left motor -3
Motor Port 5        backLeft            VEX Motor             Back Left motor -4
----------------------------------------------------------------------------------------------------*/

task main()
{
  //Loop Forever
  while(1 == 1)
  {
    //Remote Control Commands

    motor[frontRight] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
    motor[backRight] =  vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];
    motor[frontLeft] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
    motor[backLeft] =  vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];

    if(vexRT[Btn6UXmtr2] == 1) { //intake
    	motor[leftShooter] = 60;
    	motor[rightShooter] = 60;
    } else if(vexRT[Btn6DXmtr2] == 1) { //outtake
    	motor[leftShooter] = -60;
    	motor[rightShooter] = -60;
    } else if (vexRT[Btn5UXmtr2] == 1) { //Rotate cube left
    	motor[leftShooter] = -60;
    	motor[rightShooter] = 60;
  	} else if (vexRT[Btn5DXmtr2] == 1) { //Rotate cube right
  		motor[leftShooter] = 60;
  		motor[rightShooter] = -60;
 		}	else {
    	motor[leftShooter] = 0;
    	motor[rightShooter] = 0;
    }

    if(vexRT[Btn8RXmtr2] == 1) {
    	motor[shooterLift] = 70;
    } else if(vexRT[Btn8DXmtr2] == 1) {
   		motor[shooterLift] = -70;
   	} else {
   		motor[shooterLift] = 0;
  	}



  }
}
