# 🌐 WOL TaiTung - 遠端開機控制器 (Wake-on-LAN with Blynk + NodeMCU)

這是一個使用 NodeMCU (ESP8266) 搭配 Blynk App 實現的遠端開機系統。透過 Wake-on-LAN 技術，你可以使用手機 App 一鍵喚醒局域網內的電腦，並透過 LED 指示燈顯示狀態。

## 📦 功能簡介

- 使用 Blynk App 控制虛擬按鈕 (V0)
- 發送 Wake-on-LAN 封包喚醒指定電腦
- 透過內建 LED 顯示開機指令是否已發送
- 支援多組 MAC 位址擴充（可選）

## 🛠️ 所需硬體

- NodeMCU (ESP8266)
- WiFi 網路
- 支援 Wake-on-LAN 的電腦（需啟用 BIOS/WOL 設定）

## 📲 所需軟體與函式庫

- [Blynk](https://blynk.io/)
- ESP8266WiFi
- BlynkSimpleEsp8266
- WakeOnLan

## ⚙️ 設定方式

1. 在 Blynk App 建立新專案，選擇裝置為 NodeMCU，連接方式為 WiFi。
2. 設定虛擬按鈕 (V0)，模式為開關。
3. 複製 Blynk App 提供的 Auth Token，貼到程式碼中。
4. 設定你的 WiFi 名稱與密碼：
   ```cpp
   char ssid[] = "TP-Link_1234";
   char pass[] = "12345678";
