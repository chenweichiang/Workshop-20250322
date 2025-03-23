# Arduino 互動裝置工作坊

![version](https://img.shields.io/badge/版本-0.0.6-blue)
![update](https://img.shields.io/badge/更新日期-2024.03.25-green)

![Arduino Logo](https://www.arduino.cc/en/uploads/Trademark/ArduinoCommunityLogo.png)

# 師大 Artduino 工作坊教材
版本：0.0.6
最後更新：2024/03/25

## 🚀 快速開始
1. 檢查[材料清單](材料清單.md)，準備所需器材
2. 依照[環境設定說明](環境設定說明.md)安裝必要軟體
3. 開始動手實作！

## 📚 課程簡介
這是一個為藝術家設計的 Arduino 工作坊，為期兩天，將從基礎的電子電路知識開始，逐步學習 Arduino 程式設計，最終完成互動裝置的製作。

## 📖 課程內容
### [Day 1 - Arduino 基礎教學](Day1_Arduino_基礎教學.md)
- 環境設置與基本概念
- 基礎電子元件認識
- Arduino 程式設計入門
- 基礎感測器使用
  - LED 控制
  - 按鈕輸入
  - 光敏電阻
  - 水銀開關（傾斜感測）
- PWM 輸出控制

### [Day 2 - 互動專案實作](Day2_互動專案實作.md)
- 互動式燈光裝置
  - 光線感應自動調光
  - 多模式切換
  - RGB LED 控制
- 互動樂器專案
  - 可變電阻音高控制
  - 水銀開關音色切換
  - 多種演奏模式
  - LED 狀態指示
- 自由創作專案規劃與實作

## 🛠️ 開發環境需求
### 必要軟體
1. [Arduino IDE](https://www.arduino.cc/en/software)
2. [VS Code Insiders](https://code.visualstudio.com/insiders/) 或 [Cursor](https://cursor.sh/)（推薦）

### VS Code/Cursor 擴充功能
- Arduino
- C/C++
- GitHub Copilot（選配）

### 硬體需求
- Arduino Uno 開發板
- USB 連接線
- 基本電子元件（詳見[材料清單](材料清單.md)）

## 🔧 安裝說明
詳細的軟體安裝與環境設定步驟，請參考：
1. [環境設定說明](環境設定說明.md)
2. [VS Code 與 GitHub Copilot 指南](VS_Code與GitHub_Copilot指南.md)

## 🎯 專案範例
### 1. 互動式燈光裝置
- 功能：根據環境光線自動調整亮度，並可透過按鈕切換不同燈光模式
- 使用元件：RGB LED、光敏電阻、按鈕
- 程式碼：[專案_互動式燈光裝置.ino](範例程式碼/專案_互動式燈光裝置.ino)

### 2. 互動樂器
- 功能：
  - 使用可變電阻控制音高
  - 透過水銀開關切換音色
  - 四種演奏模式：基本音階、顫音、和弦、打擊樂
  - LED 模式指示
- 使用元件：可變電阻、水銀開關、蜂鳴器、LED
- 程式碼：[專案_互動樂器.ino](範例程式碼/專案_互動樂器.ino)

## 📄 授權資訊
本教材採用 MIT 授權條款。詳細內容請參考 [LICENSE](LICENSE) 檔案。

## 📅 更新紀錄
### v0.0.6 (2024/03/25)
- 更新互動樂器專案，改用可變電阻和水銀開關實現
- 移除超音波距離感測器和 LCD 顯示器相關內容
- 優化專案範例說明
- 更新材料清單

### v0.0.5 (2024/03/25)
- 新增 Day2 互動專案實作詳細內容
- 優化文件結構
- 新增專案範例說明

### v0.0.4 (2024/03/22)
- 新增 VS Code 與 GitHub Copilot 使用指南
- 更新環境設定說明
- 新增 Cursor IDE 安裝說明

### v0.0.3 (2024/03/22)
- 新增水銀開關相關內容
- 更新材料清單
- 優化 Day1 教學內容

### v0.0.2 (2024/03/20)
- 新增基礎感測器使用說明
- 完善 Day1 課程內容
- 新增範例程式碼

### v0.0.1 (2024/03/20)
- 初始版本
- 基本架構建立
- 環境設定說明

## 工作坊時間與地點
- 日期：2024年3月22-23日
- 地點：國立臺灣師範大學
- 教室：科技學院 3F Arduino 教室

## 🎨 學員作品展示
### 2024/03/22-23 工作坊作品

1. **搖擺紙鶴互動裝置**
   - 作者：錢昱昕（設計系 博一）
   - 專案：Arduino 控制紙鶴搖擺
   - [GitHub 連結](https://github.com/dawnchien/20250322)

2. **RhythmicGlow 韻律光影**
   - 作者：楊欣芸（碩一 61368004T）、曾玟心（碩一 61368020T）
   - [GitHub 連結](https://github.com/papa1916/RhythmicGlow)

3. **Arduino Mario Music Player**
   - 作者：昀蓁 Mia
   - 專案：馬力歐音樂播放器
   - [GitHub 連結](https://github.com/j6mp/arduino-mario-music-player)

4. **小象心跳控制**
   - 作者：朱玉瑋（博士班一年級 81368003T）
   - 專案：模擬小象心跳的互動裝置
   - [GitHub 連結](https://github.com/Wei4055/Wei-file)

5. **互動燈光裝置**
   - 作者：王柏景
   - [GitHub 連結](https://github.com/wang-589/0322wang)

6. **機械感知裝置**
   - 作者：陳廷恩
   - [GitHub 連結](https://github.com/41268031t/mechanical-perception)

7. **燒焦味地震感測器**
   - 作者：
     - 許芷珊（設計碩一 61368027T）
     - 黃彩雲（設計碩一 61368028T）
   - [GitHub 連結](https://github.com/Alexman1208/Workshop)

8. **腦筋急轉彎情緒燈**
   - 作者：張文馨、林語柔
   - [GitHub 連結](https://github.com/CC0401-ux/20250322)

9. **Humm 互動裝置**
   - 作者：顏亞玫（41268003T）
   - [GitHub 連結](https://github.com/mememeii/humm)

每個專案都展現了獨特的創意思維，結合了 Arduino 的技術與藝術表現，創造出令人驚艷的互動作品。這些作品充分展現了工作坊的學習成果，也展示了技術與藝術結合的無限可能。

---

*最後更新：2024年3月25日*