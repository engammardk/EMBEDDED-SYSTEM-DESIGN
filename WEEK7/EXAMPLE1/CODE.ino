
int state = 0;
const int inputpin = 19;
const int outputpin = 11;
void setup() 

{
pinMode (outputpin , OUTPUT);
pinMode (inputpin , INPUT);
 Serial.begin(9600);


   
  
}

void loop() {
   state = digitalRead(inputpin) ;

 if ( state == 1 )
  {
    digitalWrite (outputpin , HIGH);
   
  }
  else 
  {
    digitalWrite (outputpin , LOW);
  }

}
