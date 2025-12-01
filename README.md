🚮 SmartTrash IoT System
<p align="center"> <img src="https://capsule-render.vercel.app/api?type=waving&height=250&color=0:003973,100:000000&text=SMARTTRASH%20IoT&fontColor=ffffff&fontSize=60&fontAlignY=40&animation=fadeIn" /> </p> <p align="center"> <img src="https://media.giphy.com/media/U3qYN8S0j3bpK/giphy.gif" width="280"> </p>
🌑 Smart Waste Management Powered by IoT

Modern • Automated • Efficient • Real-Time Monitoring

🧭 Overview

SmartTrash adalah sistem IoT pintar yang memonitor kapasitas tempat sampah secara otomatis menggunakan sensor ultrasonik dan mikrokontroler ESP. Data dikirim ke cloud dan ditampilkan secara real-time melalui dashboard atau WhatsApp alert.

Proyek ini mendukung lingkungan modern dan berkelanjutan untuk konsep Smart City ♻️

✨ Features

🚨 Real-time Monitoring

📡 Kirim data via WiFi ke Cloud

🔥 Firebase Realtime / Thinger.io Support

🔔 Notifikasi WhatsApp otomatis

⚙️ Mode otomatis & manual

🧠 Scalable untuk Smart City

🎬 System Animation
<p align="center"> <img src="https://media.giphy.com/media/H7wajFPnZGdRWaQeu0/giphy.gif" width="550"> </p>
🧩 Tech Stack
Layer	Teknologi
Hardware	ESP8266 / ESP32, HC-SR04 Ultrasonic Sensor, Servo
Firmware	Arduino IDE / PlatformIO
Cloud	Firebase, MQTT, Thinger.io
Frontend	HTML, CSS, JavaScript
Notification	WhatsApp Gateway
🗂️ Project Structure
📁 IoT-SmartTrash  
├── SmartTrash/        # Firmware utama (ESP8266/ESP32)  
├── Firebase_Smart/    # Setup Firebase  
├── Thinger.io/        # Integrasi IoT cloud  
├── WANotif/           # Service notifikasi WhatsApp  
├── firebasecode/      # API & Rules Firebase  
├── tutupmanual/       # Kontrol manual  
└── MITT/              # Modul tambahan

🧠 System Architecture
                 ┌──────────────────────────┐
                 │      HC-SR04 Sensor      │
                 └────────────┬─────────────┘
                              │
                    reads distance
                              │
                 ┌────────────▼────────────┐
                 │      ESP8266/ESP32      │
                 └────────────┬────────────┘
                              │
                          sends data
                              │ WiFi
                 ┌────────────▼────────────┐
                 │    IoT Cloud Server     │
                 │ Firebase / MQTT / API   │
                 └────────────┬────────────┘
                              │
                     triggers events
                              │
        ┌─────────────────────▼─────────────────────┐
        │     Dashboard Web / WhatsApp Alert        │
        └───────────────────────────────────────────┘

<p align="center"> <img src="https://media.giphy.com/media/du3J3cXyzhj75IOgvA/giphy.gif" width="430"> </p>
⚙️ Installation
1️⃣ Clone Repository
git clone https://github.com/WildanFadillah1512/IoT-SmartTrash.git

2️⃣ Upload Firmware

Buka folder: SmartTrash/

Edit SSID & Password WiFi

Upload via Arduino IDE

3️⃣ Setup Firebase / MQTT

Import file dari folder Firebase_Smart/

Masukkan API key ke dalam firmware

4️⃣ Aktifkan WhatsApp Alert

Konfigurasikan gateway di folder WANotif/

🔮 Future Enhancements

🤖 AI-based trash classification

☀️ Solar-powered system

🚛 GPS tracking armada pengangkut

🌐 Smart City Integration API

📊 Dashboard analytics dengan grafik real-time

🏅 Badges
<p align="center"> <img src="https://img.shields.io/badge/IoT-SmartTrash-003973?style=for-the-badge"> <img src="https://img.shields.io/badge/Firebase-Integrated-orange?style=for-the-badge"> <img src="https://img.shields.io/badge/ESP8266/32-Supported-blue?style=for-the-badge"> <img src="https://img.shields.io/badge/Made%20By-WildanFadillah1512-00b894?style=for-the-badge"> </p>
👤 Author

Wildan Fadillah
🔗 GitHub: https://github.com/WildanFadillah1512

<p align="center"> <img src="https://capsule-render.vercel.app/api?type=waving&height=200&color=0:000000,100:003973&section=footer" /> </p>
