#define CHA 2
long count=0;
long lastStatus = 0;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    while (!Serial);
    attachInterrupt(0, encoder, RISING );
    pinMode(CHA, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//  if(digitalRead(CHA) == 1 && lastStatus == 0)
//  {
//      encoder();
//      lastStatus = 1;
//  }
//  else{
//    if(digitalRead(CHA) == 0 && lastStatus == 1)
//    {
////      encoder();
//      lastStatus = 0;
//    }
//  }
  
  Serial.println(count);
  delay(100);
}

void encoder()
  {
      count+=1;
      
    }
