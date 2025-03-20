/*
 * Arduino 感測器範例 - 光敏電阻
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 */

// 定義光敏電阻連接的針腳
const int lightSensorPin = A0;  // 類比輸入針腳 A0

// 變數宣告
int lightValue = 0;  // 儲存光線感測值

void setup() {
  // 初始化序列通訊，設定傳輸速率為 9600 bps
  Serial.begin(9600);
  Serial.println("光敏電阻感測器測試");
  Serial.println("------------------");
}

void loop() {
  // 讀取光敏電阻的值 (0-1023)
  lightValue = analogRead(lightSensorPin);
  
  // 在序列監視器顯示讀數
  Serial.print("光線強度: ");
  Serial.print(lightValue);
  
  // 顯示相對光線狀態
  if (lightValue < 200) {
    Serial.println(" - 非常暗");
  } else if (lightValue < 400) {
    Serial.println(" - 微暗");
  } else if (lightValue < 700) {
    Serial.println(" - 正常光線");
  } else if (lightValue < 900) {
    Serial.println(" - 明亮");
  } else {
    Serial.println(" - 非常亮");
  }
  
  delay(500);  // 等待 0.5 秒再讀取下一次
}