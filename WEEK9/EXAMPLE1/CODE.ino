
/* simple code on how we can conserve power using software-based technique by setting all pins as output, 
turning off analog pins, and turning analog comparator off */


int main()
{
char *ddrb = (char *)0x24; 
char *ddrc = (char *)0x27;
char *ddrd = (char *)0x2A;
char *adcsra = (char *)0x7A;
char *acsr = (char *)0x50;
*ddrb = 0b11111111; // setting port B pins as output
*ddrc = 0b11111111; // setting port C pins as output
*ddrd = 0b11111111; // setting port D pins as output
*adcsra = 0; // turning off analog pins 
*acsr = 1 << 7; // turning off analog comparator
for(;;)
{
}
}
