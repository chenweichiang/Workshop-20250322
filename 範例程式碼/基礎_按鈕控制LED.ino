/*
 * Arduino 基礎教學 - 按鈕控制LED範例
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 * 
 * 此範例展示如何使用按鈕控制LED的開關
 * 使用內部上拉電阻，按下按鈕時LED亮起
 */

const int buttonPin = 2;  // 按鈕連接針腳
const int ledPin = 13;    // LED連接針腳
int buttonState = 0;      // 用於儲存按鈕狀態

void setup() {
  pinMode(ledPin, OUTPUT);          // 設置LED針腳為輸出
  pinMode(buttonPin, INPUT_PULLUP); // 設置按鈕針腳為輸入，啟用內部上拉電阻
}

void loop() {
  buttonState = digitalRead(buttonPin); // 讀取按鈕狀態
  
  if (buttonState == LOW) {  // 如果按鈕被按下（因為使用上拉電阻，按下時為LOW）
    digitalWrite(ledPin, HIGH); // 點亮LED
  } else {
    digitalWrite(ledPin, LOW);  // 關閉LED
  }
}