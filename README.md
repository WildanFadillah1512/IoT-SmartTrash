# 🚮 SmartTrash IoT System

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&height=240&color=0:001f3f,100:001020&text=SMARTTRASH%20IoT&fontColor=ffffff&fontSize=55&fontAlignY=40&animation=fadeIn" />
</p>

<p align="center">
  <img src="https://media.giphy.com/media/U3qYN8S0j3bpK/giphy.gif" width="260">
</p>

---

## 🌑 Smart Waste Management Powered by IoT

<p align="center"><i>Modern • Automated • Efficient • Real-Time Monitoring</i></p>

---

# ✨ What Makes SmartTrash Different?

<p align="center">
  <img src="https://media.giphy.com/media/xTiTnxpQ3ghPiB2Hp6/giphy.gif" width="400">
</p>

SmartTrash adalah solusi IoT generasi baru yang menggabungkan:

✔ Sensor cerdas
✔ Automasi real-time
✔ Notifikasi langsung
✔ Cloud-connected system
✔ Desain scalable untuk Smart City

---

# 🚀 Features

### 🎯 Core Intelligence

* 🚨 Real-time Monitoring mendeteksi tinggi sampah secara akurat
* 🤖 Smart Decision System untuk membuka & menutup tutup otomatis
* 🔋 Optimasi daya untuk pemakaian jangka panjang

### 🌐 Connectivity

* 📡 Pengiriman data melalui WiFi ke Cloud
* ☁️ Mendukung Firebase, MQTT, dan Thinger.io
* 🔔 WhatsApp Alert saat sampah penuh

### 🛠️ Flexibility

* ⚙️ Mode manual & otomatis
* 🔧 Mudah integrasi ke API Smart City
* 🧩 Mudah dikembangkan ulang

---

# 🎬 System Animation

<p align="center">
  <img src="https://media.giphy.com/media/H7wajFPnZGdRWaQeu0/giphy.gif" width="600">
</p>

---

# 🧩 Tech Stack

| Layer            | Teknologi                             |
| ---------------- | ------------------------------------- |
| **Hardware**     | ESP8266 / ESP32, HC-SR04, Servo Motor |
| **Firmware**     | Arduino IDE / PlatformIO              |
| **Cloud**        | Firebase, MQTT, Thinger.io            |
| **Frontend**     | HTML, CSS, JavaScript                 |
| **Notification** | WhatsApp API Gateway                  |

---

# 🗂️ Project Structure

```
📁 IoT-SmartTrash  
├── SmartTrash/          # Firmware utama (ESP8266/ESP32)  
├── Firebase_Smart/      # Setup Firebase  
├── Thinger.io/          # Integrasi IoT cloud  
├── WANotif/             # WhatsApp notification system  
├── firebasecode/        # API Rules & konfigurasi Firebase  
├── tutupmanual/         # Mode kontrol manual  
└── MITT/                # Modul tambahan
```

---

# 🧠 System Architecture (Interactive View)

```
                 ┌──────────────────────────┐
                 │      HC-SR04 Sensor      │
                 └────────────┬─────────────┘
                              │ distance
                 ┌────────────▼────────────┐
                 │      ESP8266/ESP32      │
                 └────────────┬────────────┘
                              │ WiFi
                 ┌────────────▼────────────┐
                 │     IoT Cloud Server    │
                 │ Firebase / MQTT / API   │
                 └────────────┬────────────┘
                              │ event
        ┌─────────────────────▼─────────────────────┐
        │     Dashboard Web / WhatsApp Alert        │
        └───────────────────────────────────────────┘
```

<p align="center">
  <img src="https://media.giphy.com/media/du3J3cXyzhj75IOgvA/giphy.gif" width="420">
</p>

---

# ⚙️ Installation Guide

### 1️⃣ Clone Repository

```bash
git clone https://github.com/WildanFadillah1512/IoT-SmartTrash.git
```

### 2️⃣ Setup Firmware

* Masuk ke folder: **SmartTrash/**
* Edit SSID & Password WiFi
* Upload ke ESP8266/ESP32 via Arduino IDE

### 3️⃣ Setup Cloud

* Import Firebase config dari **Firebase_Smart/**
* Masukkan API key ke firmware

### 4️⃣ WhatsApp Notification

* Konfigurasikan gateway di **WANotif/**

---

# 🔮 Future Enhancements

* 🤖 AI-based trash type classification
* ☀️ Solar-powered autonomous system
* 🚛 GPS tracking untuk armada pengangkut
* 🌐 Integrasi penuh Smart City API
* 📊 Dashboard analytics dengan visualisasi real-time

---

# 🏅 Badges

<p align="center">
  <img src="https://img.shields.io/badge/IoT-SmartTrash-001f3f?style=for-the-badge">
  <img src="https://img.shields.io/badge/Firebase-Connected-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/ESP8266/ESP32-Ready-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Developed%20By-WildanFadillah1512-00c896?style=for-the-badge">
</p>

---

# 👤 Author

**Wildan Fadillah**
[https://github.com/WildanFadillah1512](https://github.com/WildanFadillah1512)

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&height=200&color=0:001020,100:001f3f&section=footer" />
</p>
