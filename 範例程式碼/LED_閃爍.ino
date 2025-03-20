/*
 * Arduino 基本範例 - LED 閃爍
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 */

// 定義 LED 連接的針腳
const int ledPin = 13;  // 大多數 Arduino 板上有內建 LED 在針腳 13

void setup() {
  // 初始化數位針腳為輸出模式
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);   // 開啟 LED (HIGH 為高電位)
  delay(1000);                  // 等待 1 秒 (1000 毫秒)
  digitalWrite(ledPin, LOW);    // 關閉 LED (LOW 為低電位)
  delay(1000);                  // 等待 1 秒
}