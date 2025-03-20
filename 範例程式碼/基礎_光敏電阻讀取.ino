/*
 * Arduino 基礎教學 - 光敏電阻讀取範例
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 * 
 * 此範例展示如何讀取光敏電阻的類比值並在序列監視器顯示
 */

void setup() {
  Serial.begin(9600);  // 初始化序列通訊
}

void loop() {
  int lightValue = analogRead(A0);  // 讀取模擬值
  Serial.print("光線強度: ");
  Serial.println(lightValue);
  delay(500);
}