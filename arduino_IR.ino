#define motor_left1 11
#define motor_left2 10
#define motor_right1 5
#define motor_right2 6
int error = 0 ; 



void mdrive(int left_m_speed , int right_m_speed){
  if(left_m_speed > 0){
  analogWrite(motor_left1, left_m_speed);
  digitalWrite(motor_left2, 0);
  }else{
  digitalWrite(motor_left1, 0);
  analogWrite(motor_left2, left_m_speed*-1);
  }
  if(right_m_speed > 0){
  analogWrite(motor_right1,right_m_speed);
  digitalWrite(motor_right2, 0); 
  }else{
  digitalWrite(motor_right1,0);
  analogWrite(motor_right2, right_m_speed*-1);
  }
}



void setup() {
  // put your setup code here, to run once:
pinMode(motor_left1,OUTPUT);
pinMode(motor_left2,OUTPUT);
pinMode(motor_right1,OUTPUT);
pinMode(motor_right2,OUTPUT);
Serial.begin(9600);
pinMode(8,INPUT);
pinMode(9,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//mdrive(-255,100);
int x =  digitalRead(8);
int y =  digitalRead(9);
Serial.print(x);
Serial.print("   ");
//Serial.println(y);
Serial.println(error);

if(x==1){
  error= 150;
}
else if(y==1){
  error= -150;
}
else{
  error=0;
}

mdrive(60-error,60+error);

}

