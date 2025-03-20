# VS Code 與 GitHub Copilot 開發指南

## 安裝與設置 VS Code
### 安裝步驟
1. 前往 [VS Code 官網](https://code.visualstudio.com/) 下載適合您作業系統的版本
   - Windows 用戶選擇 .exe 或 .zip 檔案
   - macOS 用戶選擇 .dmg 檔案
2. 安裝 VS Code Insiders 版本（支援最新的 Copilot 功能）
   - 前往 [VS Code Insiders](https://code.visualstudio.com/insiders/) 下載

### 安裝 Arduino 擴充功能
1. 在 VS Code 中，點擊左側擴充功能圖示
2. 搜尋 "Arduino"
3. 安裝 "Arduino" 官方擴充功能
4. 重新載入 VS Code

## GitHub 帳號設置
1. 前往 [GitHub](https://github.com/) 註冊帳號
2. 確認您的電子郵件地址
3. 設置安全的密碼及啟用雙因素認證（建議）

## GitHub Copilot 設置
### 訂閱 GitHub Copilot
1. 前往 [GitHub Copilot](https://github.com/features/copilot)
2. 點擊 "Get Started with Copilot"
3. 選擇適合您的訂閱方案（學生可能有免費方案）

### 在 VS Code 中設置 GitHub Copilot
1. 安裝 GitHub Copilot 擴充功能
   - 在擴充功能市集中搜尋 "GitHub Copilot"
   - 安裝官方擴充功能
2. 使用 GitHub 帳號登入
   - 點擊左下角設定圖示，選擇 "Settings"
   - 搜尋 "Copilot"
   - 點擊 "Sign in to GitHub"

## 使用 GitHub Copilot 開發 Arduino 專案
### 基本使用方法
1. 創建一個新的 Arduino 檔案 (.ino)
2. 開始輸入註解或基本程式碼
3. GitHub Copilot 會開始提供建議
4. 按下 Tab 鍵接受建議

### 提升 Copilot 效能的技巧
1. 寫清晰的註解
   ```cpp
   // 使用超音波感測器 HC-SR04 來測量距離
   // 當距離小於 10cm 時，亮起 LED
   ```

2. 定義明確的函數名稱與變數名稱
   ```cpp
   void readUltrasonicDistance() {
     // Copilot 會根據函數名稱提供相關實現
   }
   ```

3. 建立模板代碼框架
   ```cpp
   // 設置針腳定義
   const int trigPin = 9;
   const int echoPin = 10;
   const int ledPin = 13;
   
   // 變數宣告
   long duration;
   int distance;
   
   void setup() {
     // Copilot 將提供適當的設置程式碼
   }
   ```

## 實用範例：使用 Copilot 開發 LED 控制程式
### 步驟 1：編寫清晰的需求註解
```cpp
// Arduino 程式：透過超音波感測器控制 LED 亮度
// - 超音波感測器連接到針腳 9 (Trig) 和 10 (Echo)
// - LED 連接到 PWM 針腳 3
// - 當物體越接近，LED 越亮
// - 使用 Serial 監視器顯示測量的距離
```

### 步驟 2：讓 Copilot 生成基本程式框架
*[Copilot 會提供針腳定義和基本函數]*

### 步驟 3：添加細節並請求特定功能
```cpp
// 添加一個函數來計算距離並轉換為 LED 亮度
```

## 使用 GitHub 儲存與分享您的專案
1. 創建新的 GitHub 儲存庫
2. 使用 VS Code 內建的 Git 功能將專案推送到 GitHub
3. 與他人協作和分享您的程式碼

## 實作練習
1. 使用 VS Code 和 GitHub Copilot 創建一個簡單的 Arduino 程式
2. 使用 Copilot 幫助優化已有的 Arduino 專案
3. 將您的專案推送到 GitHub