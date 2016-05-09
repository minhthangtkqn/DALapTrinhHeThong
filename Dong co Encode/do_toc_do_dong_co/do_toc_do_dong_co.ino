const int motor = 6;    // khai báo chân PWM điều khiển motor
const int button = 8;   // khai báo chân đọc nút bấm
boolean oldState = 0;   // trạng thái của nút bấm
int time;               // biến lưu thời gian
boolean state = 0;
int speedMotor = 0;     // biến lưu giữ tốc độ của motor

void setup() {
  Serial.begin(9600);   // giao tiếp Serial với 9600 baudrate.
  pinMode(motor,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
//  if (digitalRead(button) != oldState) {  // kiểm tra thay đổi trạng thái nút bấm
//    time = millis();    // reset lại bộ timer khi nút bấm thay đổi trạng thái
//  }
//  
//  state = digitalRead(button);      // đọc giá trị nút bấm
//  int duration = millis() - time;   // đo thời gian duy trì trạng thái hiện tại
//  duration = constrain(duration,0,5000);   // 0 <= duration <= 5000 ms.
//  if (state == 1) {   //nếu đang nhấn nút
//      speedMotor = map(duration,0,5000,0,255);
//      analogWrite(motor,speedMotor);  // xuất xung PWM để điều khiển tốc độ motor
//                                      // duty cycle càng lớn thì motor quay càng nhanh
//       delay(500);
//  }
//  
//  Serial.println(speedMotor);  // in ra Serial monitor giá trị tốc độ
//  oldState = state;            // cập nhật trạng thái nút bấm.
  if(digitalRead(button) == 1)
    {
      digitalWrite(motor, 1);
      delay (10);
      digitalWrite(motor, 0);
    }
    delay(2000);
  
}
