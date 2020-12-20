/* conserving power consumptiom using software-based technique through sleeping 
 command with BOD disabled */

 
int main()
{
DeepSleep();
for(;;)
{
}
}
void DeepSleep()
{
char *smcr = (char *)0x53;
volatile char *mcucr = (char *) 0x55;
*smcr = 5; //Sleep mode = POWER DOWN, Sleep Enable = True
*mcucr = 0b01100000; //Set Both BODS and BODSE
*mcucr = 0b01000000; //Set BODS and clear BODSE
asm("sleep"); //Invoke in line assembler to sleep
}
