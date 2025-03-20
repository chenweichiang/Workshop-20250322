/*
 * Arduino 互動專案 - 互動樂器
 * 國立臺灣師範大學 Artduino 工作坊
 * 2025年3月
 * 
 * 此專案使用超音波距離感測器和蜂鳴器製作互動樂器
 * 手部距離感測器的距離決定音符的音高
 * 按鈕用於切換不同音階模式
 */

// 針腳定義
const int trigPin = 9;       // 超音波 Trig 針腳
const int echoPin = 8;       // 超音波 Echo 針腳
const int buzzerPin = 3;     // 蜂鳴器針腳
const int buttonPin = 2;     // 模式切換按鈕針腳
const int redLedPin = 10;    // 紅色 LED (調性 1)
const int yellowLedPin = 11; // 黃色 LED (調性 2)
const int greenLedPin = 12;  // 綠色 LED (調性 3)

// 變數宣告
long duration;
int distance;
int mode = 0;  // 樂器模式 (0: C Major, 1: A Minor, 2: Pentatonic)
int buttonState = 0;
int lastButtonState = 0;

// C 大調音階頻率 (C4 to C5)
int CMajorScale[] = {262, 294, 330, 349, 392, 440, 494, 523};

// A 小調音階頻率 (A3 to A4)
int AMinorScale[] = {220, 247, 262, 294, 330, 349, 392, 440};

// 五聲音階頻率 (C4 Pentatonic)
int PentatonicScale[] = {262, 294, 330, 392, 440, 523};

void setup() {
  // 初始化針腳
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  // 初始化序列監視器
  Serial.begin(9600);
  Serial.println("互動樂器已啟動");
  
  // 初始狀態：C 大調
  digitalWrite(redLedPin, HIGH);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
}

void loop() {
  // 讀取模式切換按鈕
  buttonState = digitalRead(buttonPin);
  
  // 檢查按鈕是否被按下
  if (buttonState == LOW && lastButtonState == HIGH) {
    // 切換到下一個模式
    mode = (mode + 1) % 3;
    
    // 更新 LED 狀態
    updateModeLED();
    
    delay(50);  // 去彈跳
  }
  
  // 儲存當前按鈕狀態
  lastButtonState = buttonState;
  
  // 測量距離
  distance = measureDistance();
  
  // 顯示距離
  Serial.print("距離: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 根據距離播放音符
  playNoteByDistance(distance);
  
  delay(100);  // 短暫延遲
}

// 測量超音波距離
int measureDistance() {
  // 發送超音波脈衝
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 計算距離
  duration = pulseIn(echoPin, HIGH);
  int calculatedDistance = duration * 0.034 / 2;  // 轉換為公分
  
  // 限制最大與最小距離
  if (calculatedDistance > 50) calculatedDistance = 50;
  if (calculatedDistance < 5) calculatedDistance = 5;
  
  return calculatedDistance;
}

// 根據距離播放音符
void playNoteByDistance(int dist) {
  // 距離範圍：5cm 到 50cm
  // 將距離映射到音階索引
  
  int noteIndex;
  int freq;
  
  if (dist >= 5 && dist <= 50) {
    switch (mode) {
      case 0:  // C 大調
        noteIndex = map(dist, 5, 50, 0, 7);
        freq = CMajorScale[noteIndex];
        break;
      case 1:  // A 小調
        noteIndex = map(dist, 5, 50, 0, 7);
        freq = AMinorScale[noteIndex];
        break;
      case 2:  // 五聲音階
        noteIndex = map(dist, 5, 50, 0, 5);
        freq = PentatonicScale[noteIndex];
        break;
    }
    
    // 播放音符
    tone(buzzerPin, freq, 100);
    
    // 在序列監視器顯示頻率
    Serial.print("播放頻率: ");
    Serial.println(freq);
  } else {
    // 如果手太遠或太近，不播放音符
    noTone(buzzerPin);
  }
}

// 更新模式 LED 狀態
void updateModeLED() {
  switch (mode) {
    case 0:  // C 大調
      digitalWrite(redLedPin, HIGH);
      digitalWrite(yellowLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      Serial.println("模式: C 大調");
      break;
    case 1:  // A 小調
      digitalWrite(redLedPin, LOW);
      digitalWrite(yellowLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      Serial.println("模式: A 小調");
      break;
    case 2:  // 五聲音階
      digitalWrite(redLedPin, LOW);
      digitalWrite(yellowLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      Serial.println("模式: 五聲音階");
      break;
  }
}