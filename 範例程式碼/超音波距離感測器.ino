/*
 * Arduino 感測器範例 - 超音波距離感測器 (HC-SR04)
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 */

// 定義超音波感測器的針腳
const int trigPin = 9;  // 觸發腳位
const int echoPin = 10; // 接收腳位
const int ledPin = 13;  // LED 指示燈

// 變數宣告
long duration; // 用於記錄超音波的運行時間
int distance;  // 計算出的距離

void setup() {
  // 設置超音波感測器的針腳
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // 初始化序列通訊
  Serial.begin(9600);
  Serial.println("超音波距離感測器測試");
  Serial.println("------------------");
}

void loop() {
  // 清除 trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // 設置 trigPin 為高電位 10 微秒
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 讀取 echoPin，返回聲波行進的時間，單位為微秒
  duration = pulseIn(echoPin, HIGH);
  
  // 計算距離
  // 聲音速度在空氣中為 343m/s = 0.0343 cm/微秒
  // 需除以 2 (來回距離)
  distance = duration * 0.0343 / 2;
  
  // 顯示距離
  Serial.print("距離: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 如果距離小於 20cm，則點亮 LED
  if (distance < 20) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(500);  // 等待 0.5 秒再測量下一次
}