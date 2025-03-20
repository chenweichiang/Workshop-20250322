/*
 * Arduino 基礎教學 - LED 閃爍範例
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 * 
 * 此範例展示如何控制 Arduino 的數位輸出來讓 LED 閃爍
 */

void setup() {
  // 初始化數位針腳 13 為輸出
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);  // 開啟 LED
  delay(1000);             // 等待 1 秒
  digitalWrite(13, LOW);   // 關閉 LED
  delay(1000);             // 等待 1 秒
}