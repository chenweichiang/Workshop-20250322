/*
 * Arduino 互動專案 - 互動式燈光裝置
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 * 
 * 此專案可依環境光線亮度自動調整 LED 亮度，並透過按鈕切換不同燈光模式
 * - 按鈕1：切換燈光模式（單色/漸變/閃爍）
 * - 按鈕2：切換顏色
 * - 光敏電阻：感測環境光線，自動調整燈光亮度
 */

// 針腳定義
const int redPin = 9;      // 紅色 LED 連接針腳
const int greenPin = 10;   // 綠色 LED 連接針腳
const int bluePin = 11;    // 藍色 LED 連接針腳
const int lightSensorPin = A0;  // 光敏電阻連接針腳
const int button1Pin = 2;  // 模式切換按鈕
const int button2Pin = 3;  // 亮度調整按鈕

// 變數宣告
int lightValue = 0;        // 儲存光線感測值
int lightMode = 0;         // 燈光模式（0:單色, 1:漸變, 2:閃爍）
int brightness = 255;      // LED 亮度
int colorIndex = 0;        // 目前顯示的顏色

// 按鈕狀態追蹤
int button1State = 0;
int button2State = 0;
int lastButton1State = 0;
int lastButton2State = 0;

void setup() {
  // 設置輸出針腳
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // 設置輸入針腳
  pinMode(lightSensorPin, INPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  
  // 初始化序列監視器
  Serial.begin(9600);
}

void loop() {
  // 讀取光感測器值
  lightValue = analogRead(lightSensorPin);
  
  // 將光線值映射到 LED 亮度 (較暗環境讓 LED 更亮)
  brightness = map(lightValue, 0, 1023, 255, 50);
  
  // 讀取按鈕狀態
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  
  // 檢查按鈕 1 是否按下 (模式切換)
  if (button1State == LOW && lastButton1State == HIGH) {
    lightMode = (lightMode + 1) % 3; // 切換到下一個模式
    Serial.print("模式變更為: ");
    Serial.println(lightMode);
    delay(50); // 去彈跳
  }
  
  // 檢查按鈕 2 是否按下 (顏色切換)
  if (button2State == LOW && lastButton2State == HIGH) {
    colorIndex = (colorIndex + 1) % 7; // 切換到下一個顏色
    Serial.print("顏色變更為: ");
    Serial.println(colorIndex);
    delay(50); // 去彈跳
  }
  
  // 儲存當前按鈕狀態
  lastButton1State = button1State;
  lastButton2State = button2State;
  
  // 根據不同模式設置燈光
  switch (lightMode) {
    case 0:  // 單色模式
      setColor(colorIndex, brightness);
      break;
    case 1:  // 漸變模式
      fadeColors(brightness);
      break;
    case 2:  // 閃爍模式
      blinkColor(colorIndex, brightness);
      break;
  }
}

// 設置特定的顏色 (根據顏色索引)
void setColor(int colorIdx, int bright) {
  int r = 0, g = 0, b = 0;
  
  // 根據索引選擇顏色 (RGB 組合)
  switch (colorIdx) {
    case 0: r = 255; g = 0; b = 0; break;    // 紅
    case 1: r = 0; g = 255; b = 0; break;    // 綠
    case 2: r = 0; g = 0; b = 255; break;    // 藍
    case 3: r = 255; g = 255; b = 0; break;  // 黃
    case 4: r = 0; g = 255; b = 255; break;  // 青
    case 5: r = 255; g = 0; b = 255; break;  // 紫
    case 6: r = 255; g = 255; b = 255; break;// 白
  }
  
  // 套用亮度調整
  r = map(r, 0, 255, 0, bright);
  g = map(g, 0, 255, 0, bright);
  b = map(b, 0, 255, 0, bright);
  
  // 設置 LED 顏色
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

// 顏色漸變效果
void fadeColors(int bright) {
  // 紅色淡入
  for (int r = 0; r < bright; r++) {
    analogWrite(redPin, r);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(5);
  }
  
  // 紅色淡出，綠色淡入
  for (int i = 0; i < bright; i++) {
    analogWrite(redPin, bright - i);
    analogWrite(greenPin, i);
    analogWrite(bluePin, 0);
    delay(5);
  }
  
  // 綠色淡出，藍色淡入
  for (int i = 0; i < bright; i++) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, bright - i);
    analogWrite(bluePin, i);
    delay(5);
  }
  
  // 藍色淡出
  for (int i = bright; i >= 0; i--) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, i);
    delay(5);
  }
}

// 閃爍效果
void blinkColor(int colorIdx, int bright) {
  setColor(colorIdx, bright);
  delay(200);
  setColor(colorIdx, 0);  // 全暗
  delay(200);
}