#include <ros.h>
#include <std_msgs/Float32.h>

#include <Arduino.h>

ros::NodeHandle nh;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int togPin = 5; // enable locked-antiphase mode by applying HIGH to PWM pin and PWM to Dir pin
char incomingByte = 0;
 
// Default pin9 output is 31KHz, good enough
 
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int cs  = A3;
int dio = A5;
int clk = A4;
int count = 0;
int lastcount = 0;
int currentcount = 0;
double pose = 0;

std_msgs::Float32 msg;

ros::Publisher chatter("x_pose", &msg);
 
void init_as5134(void){
  digitalWrite(cs, LOW);
  digitalWrite(clk, LOW);
  pinMode(cs,  OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(dio, INPUT);
}
int read_as5134(void){
  int clock_p;
  unsigned int data=0;
  digitalWrite(cs,LOW);
  digitalWrite(clk,LOW);
  digitalWrite(cs,HIGH);
  delay(1);
  for(clock_p=21;clock_p--;clock_p>0){
    digitalWrite(clk,LOW);
    delay(1);
    digitalWrite(clk,HIGH);
    delay(1);
    if(clock_p<9){
      if(digitalRead(dio))
        data+=(1<<(clock_p));
    }
  }
  digitalWrite(clk,LOW);
  digitalWrite(cs,LOW);
  return data;
}
 
void setPwmFrequency(int pin, int divisor) 
{
	byte mode;
	if( pin == 6 || pin == 9 || pin == 10)
	{
		switch(divisor)
		{
			case 1: mode = 0x01; break;
			case 8: mode = 0x02; break;
			case 64: mode = 0x03; break;
			case 256: mode = 0x04; break;
			case 1024: mode = 0x05; break;
			default: return;
		}
		if(pin == 5 || pin == 6)
		{
			TCCR0B = TCCR0B & 0b11111000 | mode;
		}
		else
		{
			TCCR1B = TCCR1B & 0b11111000 | mode;
		}
	}
	else if(pin == 3 || pin == 11)
	{
		switch(divisor)
		{
			case 1: mode = 0x01; break;
			case 8: mode = 0x02; break;
			case 32: mode = 0x03; break;
			case 64: mode = 0x04; break;
			case 128: mode = 0x05; break;
			case 256: mode = 0x06; break;
			case 1024: mode = 0x07; break;
			default: return;
		}
		TCCR2B = TCCR2B & 0b11111000 | mode;
	}
}
 
void setup() {
	// initialize serial communications at 9600 bps:
	pinMode(togPin, OUTPUT);           // set pin to input
	setPwmFrequency(9, 1);
	init_as5134();
	Serial.begin(57600);
	digitalWrite(togPin, HIGH);       // turn on pullup resistors

	nh.initNode();
	nh.advertise(chatter);
 
}
 
void loop() {
	currentcount = read_as5134();
	pose = pose + (static_cast<double>(currentcount)  - (double)(1.0*lastcount))/360 * 0.04;
	lastcount = currentcount;
	
	msg.data = pose;
	chatter.publish( &msg );
	nh.spinOnce();
	//Serial.println(lastcount);  
	delay(1);



	// read the analog in value:
	sensorValue = analogRead(analogInPin);
	// map it to the range of the analog out:
	outputValue = map(sensorValue, 0, 1023, 0, 255);
	// change the analog out value:
	analogWrite(analogOutPin, outputValue);

	if (Serial.available() > 0)
	{
		// read the incoming byte:
		incomingByte = Serial.read();

		// say what you got:
		//  Serial.print(“I received: “);
		//  Serial.println(incomingByte, DEC);
		if (incomingByte == 'a')
		{
			digitalWrite(togPin, HIGH);
			//Serial.print("Driving Forward.");
		}
		if (incomingByte == 'b')
		{
			digitalWrite(togPin, LOW);
			//Serial.print("Driving Backward.");
		}
	}
//Serial.print(digitalRead(togPin));
// print the results to the Serial Monitor:
//
 
// wait 2 milliseconds before the next loop for the analog-to-digital
// converter to settle after the last reading:
}