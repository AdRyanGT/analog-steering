//Arduino competition design

#define HosLPWM 5
#define HosLDIR 10 
#define HosRPWM 6 
#define HosRDIR 9 
/*#define HDzwigPWM  
#define HDzwigDIR  */
#define motorPin1 13
#define motorPin2 12 
#define motorPin3 11 
#define motorPin4 2 
#define AnalogY A2 
#define AnalogX A1 
/*int But1 =  ;
int But2 =  ; */
int But3 = 3 ; //To jest pod serwo :D
int But4 = 4 ;

int motor_Speed = 4; //Stepper
int motor_Step; 
int val1 = 0;
int val2 = 0;

int DzwigSpeed = 16;
int DzwigDelay = 100;

int vertical = 0;
int horizontal = 0;
int deadzone = 20;
int dir_delay = 200;

void setup() {
  
  Serial.begin(9600);
  pinMode(HosLPWM, OUTPUT);
  pinMode(HosLDIR, OUTPUT);
  pinMode(HosRPWM, OUTPUT);
  pinMode(HosRDIR, OUTPUT);
 /* pinMode(HDzwigPWM, OUTPUT);
  pinMode(HDzwigDIR, OUTPUT); */
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  /* pinMode(But1, INPUT_PULLUP);
  pinMode(But2, INPUT_PULLUP); */
  pinMode(But3, INPUT_PULLUP);
  pinMode(But4, INPUT_PULLUP);
}

  // put your setup code here, to run once:


void loop()
{

/* if (digitalRead(But1 == LOW)){               // if button is pushed
 
 analogWrite(HDzwigPWM, DzwigSpeed);
 digitalWrite(HDzwigDIR, HIGH);
 delay(DzwigDelay);

 }
 if (digitalRead(But2 == LOW)) {                             //if another button is pushed
 
 analogWrite(HDzwigPWM, DzwigSpeed);
 digitalWrite(HDzwigDIR, LOW);
 delay(DzwigDelay);
 
 } */

  val1 = digitalRead(But3);
  if (val1 == LOW)
  {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(motor_Speed);
   digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delay(motor_Speed);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(motor_Speed);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(motor_Speed);
  
    } 

   val2 = digitalRead(But4);
   if (val2 == LOW)

  {
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(motor_Speed);
   digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  delay(motor_Speed);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, HIGH);
  delay(motor_Speed);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(motor_Speed);
  digitalWrite(motorPin4, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  delay(motor_Speed);
  }

 vertical = analogRead(AnalogY);
 vertical = map(vertical, 0, 1023, 255, -255);
 Serial.print("Y ");
 Serial.println(vertical);

 horizontal = analogRead(AnalogX);
 horizontal = map(horizontal, 0, 1023, 255, -255);
 Serial.print("X ");
 Serial.println(horizontal);

 if ((vertical >= -deadzone) && (vertical <=deadzone) && (horizontal >= -deadzone) && (horizontal <= deadzone)) //Hamuj KURWA!
{
  
 analogWrite (HosLPWM, LOW);
 analogWrite (HosLDIR, LOW);

 analogWrite (HosRPWM, LOW);
 analogWrite (HosRDIR, LOW);
 
}
else if ((vertical > deadzone) && (horizontal <= deadzone) && (horizontal >= -deadzone)) //Przod
 {
  
 analogWrite (HosLPWM, abs(vertical));
 analogWrite (HosLDIR, 0);

 analogWrite (HosRPWM, abs(vertical));
 analogWrite (HosRDIR, 0);
 }
 else if ((vertical > deadzone) && (horizontal > deadzone)) //Prawo w przod
 {
 
 analogWrite (HosRPWM, abs(vertical));
 analogWrite (HosRDIR, 0);

 analogWrite (HosLPWM, (255-abs(horizontal)));
 analogWrite (HosLDIR, 0);
 
 }
 else if ((vertical <= deadzone) && (vertical >= -deadzone) && (horizontal > deadzone)) //Ostro w prawo
 {
  
 analogWrite (HosRPWM, abs(horizontal));
 analogWrite (HosRDIR, 0);

 analogWrite (HosLPWM, 0);
 analogWrite (HosLDIR, 0);
 }
 else if ((vertical < -deadzone) && (horizontal > deadzone)) //Prawo w tył
 {
  
 analogWrite (HosLPWM, 0);
 analogWrite (HosLDIR, abs(vertical));

 analogWrite (HosRPWM, 0);
 analogWrite (HosRDIR, (255-abs(horizontal)));
 }
 else if ((vertical < -deadzone) && (horizontal >= -deadzone) && (horizontal <= deadzone)) //Tył
 {
  
 analogWrite (HosLDIR, abs(vertical));
 analogWrite (HosLPWM, 0);

 analogWrite (HosRDIR, abs(vertical));
 analogWrite (HosRPWM, 0);
 }
 else if ((vertical < -deadzone) && (horizontal < -deadzone)) //Lewo w tył
 {
 
 analogWrite (HosLPWM, 0);
 analogWrite (HosLDIR, (255-abs(horizontal)));

 analogWrite (HosRPWM, 0);
 analogWrite (HosRDIR, abs(vertical));
 }
 else if ((vertical >= -deadzone) && (vertical <= deadzone) && (horizontal < -deadzone)) //Ostro w lewo
 {
 
 analogWrite (HosLPWM, abs(horizontal));
 analogWrite (HosLDIR, 0);

 analogWrite (HosRPWM, 0);
 analogWrite (HosRDIR, 0);
 }
  else if ((vertical > deadzone ) && (horizontal < -deadzone)) //Lewo w przód
 {
 
 analogWrite (HosLPWM, abs(vertical));
 analogWrite (HosLDIR, 0);

 analogWrite (HosRPWM, (255-abs(horizontal)));
 analogWrite (HosRDIR, 0);
 }
 

} //void loop
