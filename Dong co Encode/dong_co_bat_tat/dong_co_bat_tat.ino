#define CHA 2
long count=0;
const int motor = 6;    // khai báo chân PWM điều khiển motor
const int button = 3;   // khai báo chân đọc nút bấm
int BStatus = 0;

boolean oldState = 0;   // trạng thái của nút bấm
int time;               // biến lưu thời gian
boolean state = 0;
int speedMotor = 0;     // biến lưu giữ tốc độ của motor

void setup() {
  Serial.begin(9600);   // giao tiếp Serial với 9600 baudrate.
  pinMode(motor,OUTPUT);
  pinMode(button,INPUT);

  while (!Serial);
    attachInterrupt(0, encoder, RISING );
    attachInterrupt(1, ChangeButtonStatus, RISING);
    pinMode(CHA, INPUT);
}

void loop() {
    delay(100);                     //thời gian delay để nhận tín hiệu nút bấm
    if(BStatus == 1)
    {
        if(count >= 80)
        {
          count = 0;                //reset count
          digitalWrite(motor, 0);   //tat dong co
          delay(100);
        }
        else
        {
          analogWrite(motor, 50);
        }
        
    }
    else
    {
      digitalWrite(motor, 0);
    }
    Serial.print("BStatus: ");
    Serial.println(BStatus);
    Serial.println(count);
    delay(1);
    
//  if(digitalRead(button) == 1)
//  {
//      analogWrite(motor, 40);
//      Serial.println(count);   
//  }
//  else
//    digitalWrite(motor, 0);
//  delay(1);
}


void encoder()
  {
      count+=1;
      
  }
void ChangeButtonStatus()
{
      if(BStatus == 0)
        BStatus = 1;
      else
        BStatus = 0;
}

