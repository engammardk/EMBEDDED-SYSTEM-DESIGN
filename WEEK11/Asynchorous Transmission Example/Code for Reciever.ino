volatile char* pinb = (char*) 0x23;
int main() //void setup() for Arduino
{
Serial.begin(9600);
while(1)
{
unsigned char data = Receive(2000); //Get the incoming data
Serial.println(data);//Print the received data
  
}
}

char Receive(unsigned long BaudRate)
{
unsigned long delay_us = 1000000/BaudRate;
bool previous = ((*pinb) & (1 << 2)); //previous = digitalRead(10);
while(previous==((*pinb) & (1 << 2))) //Wait for start-bit
{
//As long as there is no change from the idle state, keep waiting.
}
delayMicroseconds(delay_us * 1.1); //Wait a bit longer than required span
//in order to avoid transition periods
char ReceivedData;
for (int i=7; i>=0; i--) //MSB first (decrementing loop)
{
if ((*pinb) & (1 << 2)) //If PB2 (data pin) is HIGH
{
ReceivedData |= 1 << i; //Set the ith bit
}
else
{
ReceivedData &= ~(1 << i); //Clear the ith bit
}
delayMicroseconds(delay_us);
}
return ReceivedData;
}
*portb &= ~(1 << 2); //Send stop bit (LOW)
delayMicroseconds(delay_us);
}
