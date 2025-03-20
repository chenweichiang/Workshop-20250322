/*
  水銀開關傾斜感測器範例
  當感測器傾斜時，LED 會亮起
  
  硬體連接：
  - 水銀開關一端接 D2（上拉電阻連接到 5V）
  - 水銀開關另一端接 GND
  - LED 正極接 D13
  - LED 負極經過 220Ω 電阻接 GND
*/

const int tiltPin = 2;     // 水銀開關連接的腳位
const int ledPin = 13;     // LED 連接的腳位

void setup() {
  pinMode(tiltPin, INPUT_PULLUP);  // 設定水銀開關腳位為輸入，並啟用內建上拉電阻
  pinMode(ledPin, OUTPUT);         // 設定 LED 腳位為輸出
  
  Serial.begin(9600);             // 初始化序列通訊，用於除錯
  Serial.println("水銀開關傾斜感測器測試");
}

void loop() {
  // 讀取水銀開關狀態
  int tiltState = digitalRead(tiltPin);
  
  // 當感測器傾斜時（開關閉合），LED 亮起
  if (tiltState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.println("感測器傾斜！");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("感測器平放");
  }
  
  delay(100);  // 短暫延遲以避免讀取過於頻繁
} 