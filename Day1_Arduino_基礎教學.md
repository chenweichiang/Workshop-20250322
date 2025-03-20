# Arduino 基礎教學 - 第一天
版本：0.0.3
最後更新：2024/03/22

## 環境設置
### 安裝 Arduino IDE
1. 根據您的作業系統 (Windows/macOS) 下載並安裝 [Arduino IDE](https://www.arduino.cc/en/software)
2. 安裝完成後，連接您的 Arduino 板
3. 選擇正確的板子型號和連接埠
   - 工具 > 開發板 > Arduino Uno
   - 工具 > 連接埠 > 選擇對應的 COM 埠 (Windows) 或 /dev/cu.usb... (macOS)

### 安裝 VS Code 與 Arduino 擴充功能
1. 下載並安裝 [VS Code Insiders](https://code.visualstudio.com/insiders/)
2. 在 VS Code 擴充功能市集中安裝：
   - Arduino 擴充功能
   - C/C++ 擴充功能
   - GitHub Copilot（需要訂閱）

### 設定 VS Code Arduino 開發環境
1. 開啟 VS Code 設定（Cmd+, 或 Ctrl+,）
2. 搜尋 "Arduino"
3. 設定 Arduino 路徑：
   - Windows：通常在 `C:\Program Files (x86)\Arduino`
   - macOS：通常在 `/Applications/Arduino.app`
4. 設定開發板和連接埠（在 VS Code 狀態列）

### 啟用 GitHub Copilot
1. 使用 GitHub 帳號登入 VS Code
2. 確認 GitHub Copilot 訂閱狀態
3. 在程式碼編輯時，Copilot 會自動提供建議
4. 使用 `Tab` 鍵接受建議，`Esc` 鍵拒絕建議

## Arduino 基本概念
### Arduino 簡介
- Arduino 是開源的電子原型平台
- 包含硬體（各種電路板）和軟體（IDE）
- 適合初學者與專業人士
- 應用廣泛：藝術裝置、互動設計、自動化控制等

### 硬體認識
- Arduino Uno 板子介紹
  - 微控制器：ATmega328P
  - 數位針腳 (D0-D13)
  - 類比針腳 (A0-A5)
  - 電源針腳 (5V, 3.3V, GND)
  - USB 連接埠
- 麵包板使用方法
- 基本電子元件介紹

## 程式語言基礎概念
### 變數與資料型態
- 整數 (int)：例如 `int ledPin = 13;`
- 浮點數 (float)：例如 `float voltage = 3.3;`
- 布林值 (boolean)：例如 `boolean isOn = true;`
- 常數 (const)：例如 `const int buttonPin = 2;`

### 條件判斷（if-else）
```cpp
if (條件) {
    // 當條件成立時執行
} else {
    // 當條件不成立時執行
}
```
範例：
```cpp
if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
} else {
    digitalWrite(ledPin, LOW);
}
```

### 迴圈結構
1. for 迴圈
```cpp
for (初始值; 條件; 更新) {
    // 重複執行的程式碼
}
```
範例：
```cpp
// LED 漸亮
for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(10);
}
```

2. while 迴圈
```cpp
while (條件) {
    // 當條件成立時重複執行
}
```

### 實作練習：LED 呼吸燈
結合以上概念，製作 LED 呼吸效果：
```cpp
void loop() {
    // 漸亮
    for (int brightness = 0; brightness <= 255; brightness++) {
        analogWrite(ledPin, brightness);
        delay(10);
    }
    
    // 漸暗
    for (int brightness = 255; brightness >= 0; brightness--) {
        analogWrite(ledPin, brightness);
        delay(10);
    }
}
```

## 第一個程式：LED 閃爍
### 硬體連接
- 將 LED 正極連接到 Arduino 的數位針腳 13
- 負極連接到 GND
- 中間加一個 220Ω 電阻

### 程式碼
請參考範例檔案：[基礎_LED閃爍.ino](範例程式碼/基礎_LED閃爍.ino)

## 感測器基礎
### 光敏電阻使用
- 連接方式：一端接 5V，一端通過 10K 電阻接 GND，中間連接到 A0
- 範例程式：[基礎_光敏電阻讀取.ino](範例程式碼/基礎_光敏電阻讀取.ino)

### 按鈕控制 LED
- 按鈕連接到數位針腳 2
- LED 連接到數位針腳 13
- 參考範例：[基礎_按鈕控制LED.ino](範例程式碼/基礎_按鈕控制LED.ino)

### 水銀開關傾斜感測
- 水銀開關是一種簡單的傾斜感測器
- 工作原理：當傾斜時，內部的水銀會流動並接通電路
- 連接方式：
  - 一端接數位針腳（使用內建上拉電阻）
  - 另一端接 GND
- 應用場景：
  - 傾斜感測
  - 姿態檢測
  - 安全開關
- 參考範例：[基礎_水銀開關傾斜感測.ino](範例程式碼/基礎_水銀開關傾斜感測.ino)

## 進階控制
### PWM 輸出控制 LED 亮度
- 使用數位針腳 9 連接 LED
- 使用 analogWrite() 控制亮度
- 參考範例：[基礎_PWM控制LED亮度.ino](範例程式碼/基礎_PWM控制LED亮度.ino)

## 實作練習
1. 使用光敏電阻控制 LED 亮度
2. 製作一個簡單的交通信號燈
3. 使用按鈕控制 LED 閃爍模式
4. 製作一個傾斜感應的警示燈
   - 使用水銀開關檢測傾斜
   - 當傾斜時 LED 閃爍警示
   - 可選擇添加蜂鳴器發出警示聲

## 課後作業
思考並設計一個簡單的互動裝置，包含：
- 至少一個感測器輸入
- 至少一個執行器輸出
- 互動形式說明