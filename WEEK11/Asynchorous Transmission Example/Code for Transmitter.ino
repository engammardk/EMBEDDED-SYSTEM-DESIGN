char* ddrb = (char*) 0x24;
char* portb = (char*) 0x25;
int main() //void setup() for Arduino
{
*ddrb |= (1 << 2); //PB2 is Data line. This code is same as pinMode(10, OUTPUT);
Transmit(16, 2000); //Transmit 00010000 at 2kBd.
}
void Transmit(unsigned char data, int BaudRate)
{
unsigned long delay_us = 1000000/BaudRate;
*portb |= 1 << 2; //Send start bit (HIGH)
delayMicroseconds(delay_us);
for (int i=7; i>=0; i--) //MSB first (decrementing loop)
{
if (data & (1 << i)) //If the ith bit is HIGH
{
*portb |= 1 << 2; //Send HIGH bit
}
else
{
*portb &= ~(1 << 2); //Send LOW bit
}
delayMicroseconds(delay_us);
}
*portb &= ~(1 << 2); //Send stop bit (LOW)
delayMicroseconds(delay_us);
}
