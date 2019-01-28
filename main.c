/*
 * PWM_workshop.c
 *
 * Created: 24-01-2019 19:00:04
 * Author : SAHIL
 */ 

#include <avr/io.h>

void pwm_init(){
	TCCR0|=(1<<WGM00)|(1<<WGM01); //Set PWM to Fast PWM Mode
	TCCR0|=(1<<COM00)|(1<<COM01); //Set Fast PWM to inverting mode
	TCCR0|=(1<<CS01) //Prescale 8 bit counter to prescaling of 8 to count till 2048 counting (>100)(coz ICR1 is 1000 and hence couter must be greater than 1000)
	TCCR0&=~(1<<CS02)
	ICR1=1000; //Sets ICP1(Reference to 1000)(Although it is called ICP1
}

void move_forward(){
	PORTA|=(1<<PINA2)|(1<<PINA4);
	PORTA&=~(1<<PINA3);
	PORTA&=~(1<<PINA5);
	OCR1A=1000;//Run Motor 1 at 100% of ICR1(Reference) value
	OCR1B=1000;//Run Motor 2 at 100% of ICR1(Reference) value
}

void move_backward(){
	PORTA|=(1<<PINA3)|(1<<PINA5);
	PORTA&=~(1<<PINA2);
	PORTA&=~(1<<PINA4);
	OCR1A=1000;//Run Motor 1 at 100% of ICR1(Reference) value {Reverse}
	OCR1B=1000;//Run Motor 2 at 100% of ICR1(Reference) value {Reverse}
}

void turn_left(){
	PORTA|=(1<<PINA2)|(1<<PINA4);
	PORTA&=~(1<<PINA3);
	PORTA&=~(1<<PINA5);
	OCR1A=1000;//Run Motor 1 at 100% of ICR1(Reference) value
	OCR1B=450;//Run Motor 2 at 45% of ICR1(Reference) value
}

void turn_right(){
	PORTA|=(1<<PINA2)|(1<<PINA4);
	PORTA&=~(1<<PINA3);
	PORTA&=~(1<<PINA5);
	OCR1A=450;//Run Motor 1 at 45% of ICR1(Reference) value
	OCR1B=1000;//Run Motor 2 at 100% of ICR1(Reference) value
}

void turn_left_hard(){
	PORTA|=(1<<PINA2)|(1<<PINA5);
	PORTA&=~(1<<PINA3);
	PORTA&=~(1<<PINA4);
	OCR1A=750;//Run Motor 1 at 100% of ICR1(Reference) value
	OCR1B=750;//Run Motor 2 at 100% of ICR1(Reference) value {Reverse}
}

void turn_right_hard(){
	PORTA|=(1<<PINA3)|(1<<PINA4);
	PORTA&=~(1<<PINA2);
	PORTA&=~(1<<PINA5);
	OCR1A=750;//Run Motor 1 at 75% of ICR1(Reference) value {Reverse}
	OCR1B=750;//Run Motor 2 at 75% of ICR1(Reference) value

int main(void)
{
    /* Replace with your application code */
	DDRA=0b00111100
    while (1) 
    {
		
    }
}

