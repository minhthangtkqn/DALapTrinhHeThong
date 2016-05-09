void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float raw = analogRead(A0);
  float voltRaw=map(raw, 0, 1023, 0, 5000);
  float volt = voltRaw/1000;
//  float cm=(21.61/(volt-0.1696))*1000;

 
//  double dataX = pow(10, -11)*pow(raw, 6) - 2*pow(10, -8)*pow(raw, 5) + pow(10, -5)*pow(raw,4) - 0.0033*pow(raw,3) + 0.5184*pow(raw,2) - 36.564*raw + 1150.8;
//  double dataX = pow(10, -7)*pow(raw, 4) - 0.0001*pow(raw, 3) + 0.0474*pow(raw, 2) - 3.9169*raw + 351.68;

//  double dataX = pow(10, -7)*pow(raw,4) - 0.0001*pow(raw,3) + 0.0509*pow(raw,2) - 4.2886*raw + 362.64;
//  double dataX = 0.0026*pow(raw,2) + 2.5952*raw + 65.586;
//  double dis1 = (204800/11)/(dataX);  
  
  double distance = -4.5594*pow(volt,5) + 48.465*pow(volt,4) - 199.74*pow(volt,3) + 402.36*pow(volt,2) - 409.35*volt + 189.95;       
  
  
  Serial.println(distance); 
  
  delay(150);
}
