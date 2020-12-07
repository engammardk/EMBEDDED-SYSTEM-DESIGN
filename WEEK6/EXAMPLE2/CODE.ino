
  
 
int main (void) 
{

      Serial.begin(9600);
      TCCR1A = 0b00000000; // to set as normal mode ; 
      TCCR1B = 0b00000101; // set prescaler 1024 which is the maximum to slow down the timer.
    


while (1)
{

      Serial.println(TCNT1); // print values from 0 until 65536 and reset 
     
      

}
}
