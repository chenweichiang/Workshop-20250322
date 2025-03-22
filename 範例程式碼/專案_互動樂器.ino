/*
 * 互動樂器專案
 * 使用可變電阻控制音高，水銀開關切換音色
 */

// 定義針腳
const int POTENTIOMETER_PIN = A0;    // 可變電阻
const int MERCURY_SWITCH_1 = 8;      // 水銀開關 1
const int MERCURY_SWITCH_2 = 9;      // 水銀開關 2
const int BUZZER_PIN = 3;            // 蜂鳴器
const int MODE_BUTTON = 2;           // 模式切換按鈕
const int MUTE_BUTTON = 4;           // 靜音按鈕
const int LED_RED = 10;              // 紅色 LED
const int LED_YELLOW = 11;           // 黃色 LED
const int LED_GREEN = 12;            // 綠色 LED

// 音階頻率定義
const int NOTES[] = {
  262, 294, 330, 349, 392, 440, 494, 523  // C4 到 C5
};

// 變數
int currentMode = 0;     // 當前模式（0-3）
bool isMuted = false;    // 靜音狀態
int lastPotValue = 0;    // 上一次的可變電阻值
bool lastSwitch1State = false;  // 上一次的開關1狀態
bool lastSwitch2State = false;  // 上一次的開關2狀態
bool lastModeButtonState = false;  // 上一次的模式按鈕狀態
bool lastMuteButtonState = false;  // 上一次的靜音按鈕狀態

void setup() {
  // 設定輸入輸出
  pinMode(MERCURY_SWITCH_1, INPUT_PULLUP);
  pinMode(MERCURY_SWITCH_2, INPUT_PULLUP);
  pinMode(MODE_BUTTON, INPUT_PULLUP);
  pinMode(MUTE_BUTTON, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
  // 初始化串列通訊（用於除錯）
  Serial.begin(9600);
}

void loop() {
  // 讀取感測器狀態
  int potValue = analogRead(POTENTIOMETER_PIN);
  bool switch1State = !digitalRead(MERCURY_SWITCH_1);  // 反轉邏輯，傾斜時為 true
  bool switch2State = !digitalRead(MERCURY_SWITCH_2);
  bool modeButtonState = !digitalRead(MODE_BUTTON);
  bool muteButtonState = !digitalRead(MUTE_BUTTON);
  
  // 處理模式切換
  if (modeButtonState && !lastModeButtonState) {
    currentMode = (currentMode + 1) % 4;
    updateLEDs();
    delay(50);  // 消除彈跳
  }
  
  // 處理靜音切換
  if (muteButtonState && !lastMuteButtonState) {
    isMuted = !isMuted;
    if (isMuted) {
      noTone(BUZZER_PIN);
    }
    delay(50);  // 消除彈跳
  }
  
  // 如果沒有靜音，處理聲音輸出
  if (!isMuted) {
    // 根據可變電阻值映射到音階
    int noteIndex = map(potValue, 0, 1023, 0, 7);
    int baseFreq = NOTES[noteIndex];
    
    // 根據模式和開關狀態產生不同效果
    switch (currentMode) {
      case 0:  // 基本音階模式
        if (abs(potValue - lastPotValue) > 5) {  // 只在變化明顯時更新
          tone(BUZZER_PIN, baseFreq);
        }
        break;
        
      case 1:  // 顫音模式
        if (switch1State) {
          tone(BUZZER_PIN, baseFreq * 1.05);  // 稍微提高音高
        } else {
          tone(BUZZER_PIN, baseFreq);
        }
        break;
        
      case 2:  // 和弦模式
        if (switch1State && switch2State) {
          tone(BUZZER_PIN, baseFreq * 1.25);  // 三和弦最高音
        } else if (switch1State) {
          tone(BUZZER_PIN, baseFreq * 1.2);   // 三和弦中音
        } else {
          tone(BUZZER_PIN, baseFreq);         // 基本音
        }
        break;
        
      case 3:  // 打擊樂模式
        if (switch1State != lastSwitch1State || switch2State != lastSwitch2State) {
          if (switch1State || switch2State) {
            tone(BUZZER_PIN, baseFreq, 100);  // 短促的音符
          }
        }
        break;
    }
  }
  
  // 更新上一次的狀態
  lastPotValue = potValue;
  lastSwitch1State = switch1State;
  lastSwitch2State = switch2State;
  lastModeButtonState = modeButtonState;
  lastMuteButtonState = muteButtonState;
  
  // 輸出除錯資訊
  Serial.print("Mode: ");
  Serial.print(currentMode);
  Serial.print(" Pot: ");
  Serial.print(potValue);
  Serial.print(" SW1: ");
  Serial.print(switch1State);
  Serial.print(" SW2: ");
  Serial.println(switch2State);
  
  delay(10);  // 小延遲以穩定讀取
}

// 更新 LED 顯示
void updateLEDs() {
  digitalWrite(LED_RED, currentMode == 1 || currentMode == 3);
  digitalWrite(LED_YELLOW, currentMode == 2 || currentMode == 3);
  digitalWrite(LED_GREEN, currentMode == 0 || currentMode == 2);
}