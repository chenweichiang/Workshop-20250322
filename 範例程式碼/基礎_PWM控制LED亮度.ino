/*
 * Arduino 基礎教學 - PWM控制LED亮度
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 * 
 * 此範例展示如何使用analogWrite()和PWM控制LED亮度
 * 讓LED呈現漸亮和漸暗的效果
 */

const int ledPin = 9;  // LED連接到支援PWM的針腳

void setup() {
  pinMode(ledPin, OUTPUT);  // 設置LED針腳為輸出
}

void loop() {
  // 漸亮
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);  // 設置LED亮度
    delay(10);                       // 小延遲使變化更明顯
  }
  
  // 漸暗
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);  // 設置LED亮度
    delay(10);                       // 小延遲使變化更明顯
  }
}