char* ddrb = (char*) 0x24;
char* portb = (char*) 0x25;
int main() //void setup() for Arduino
{
*ddrb |= (1 << 2); //PB2 is Data line. This code is same as pinMode(10, OUTPUT);
*ddrb |= (1 << 3); //PB3 is clock line. This code is same as pinMode(11, OUTPUT);
Transmit(24, 100000); //Transmit 00011000 at 100kBd.
}

void Transmit(unsigned char data, unsigned long BaudRate)
{
unsigned long delay_us = 1000000/BaudRate; //Delay in microseconds
unsigned long clock_delay = delay_us / 2; //Period of CLK is half of signal
for (int i=7; i>=0; i--) //Start with 7th bit (MSB) first
{
if (data & (1 << i)) //If the ith bit is HIGH
{
*portb |= 1 << 2; //Make PB2 HIGH
}
else
{
*portb &= ~(1 << 2); //Make PB2 LOW
}
*portb |= 1 << 3; //Make CLK HIGH
delayMicroseconds(clock_delay);
*portb &= ~(1 << 3); //Make CLK LOW;
delayMicroseconds(delay_us - clock_delay);
}
*portb &= ~(1 << 2); //Done. Make PB2 back to LOW
}
