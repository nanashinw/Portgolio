//define pin motor
#define PWM_L 	3
#define PWM_R 	11
#define DIR_L 	4
#define DIR_R 	10

//define pin distance
#define RR 2
#define R 6
#define M 14
#define L 7
#define LL 5
 
//define pin IR sensor
#define Light_L A1
#define Light_R A2


#define nashi(x) digitalRead(x)

//pin diff swich
#define MODE A6
//Battery Voltage
#define VBATT 	A7

//start module
#define START digitalRead(2)
#define wait_SW8()\
  while(START == 1)\
  ;

//start module remote
#define REMOTE digitalRead(13)

