
int A_count=0;
int B_count=0;
int C_count=0;
int D_count=0;
int E_count=0;


void setup() {

  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  Serial.print("A="),Serial.print("0"),
  Serial.print(" B="),Serial.print("0"),
  Serial.print(" C="),Serial.print("0"),
  Serial.print(" D="),Serial.print("0"),
  Serial.print(" E="),Serial.println("0");

  
}

void loop()
{
int A_state = digitalRead(2);
int B_state = digitalRead(3);
int C_state = digitalRead(4);
int D_state = digitalRead(5);
int E_state = digitalRead(6);

if (A_state ==0){
    A_count ++;
  
}
else 
{}
if (B_state ==0){
    B_count ++;
  
}
else 
{}
if (C_state ==0){
    C_count ++;
   
}
else 
{}
if (D_state ==0){
    D_count ++;
  
}
else 
{}if (E_state ==0){
      E_count ++;
}
else 
{}
  if (A_state ==0 || B_state ==0 || C_state ==0 || D_state ==0 || E_state ==0 )
  {Serial.print("A="),Serial.print(A_count),
  Serial.print(" B="),Serial.print(B_count),
  Serial.print(" C="),Serial.print(C_count),
  Serial.print(" D="),Serial.print(D_count),
  Serial.print(" E="),Serial.println(E_count);
  delay (1000);
  
  }
  else
  {}
}
