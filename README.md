# 🚮 **SMARTTRASH IoT — POWERFULL PROJECT EDITION**

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&height=180&color=0:000000,100:003366&text=SMARTTRASH%20IoT%20SYSTEM&fontColor=38e0ff&fontAlignY=45&fontSize=45&animation=fadeIn" />
</p>

<p align="center">
  <img src="https://media.giphy.com/media/3o7aD2saalBwwftBIY/giphy.gif" width="340">
</p>

---

# 🌍 **SmartTrash — Project Resmi Sistem Tempat Sampah Pintar Berbasis IoT**

SmartTrash adalah sistem IoT lengkap yang **benar-benar bekerja** sesuai implementasi di project kamu: membaca kapasitas sampah, mengontrol tutup otomatis, mengirimkan data ke Firebase/Thinger.io, dan memberikan notifikasi WhatsApp. Dokumentasi ini dibangun khusus untuk menggambarkan struktur projekmu, cara kerja kode, dan keseluruhan arsitektur dengan desain **powerful, bersih, dan modern**.

---

# ⚡ **Fitur Utama Sistem Sesuai Projek Asli**

### 🧭 **Monitoring Kapasitas Otomatis**

* Menggunakan sensor ultrasonik HC-SR04
* Mengukur jarak sampah → menentukan status: *Kosong, Setengah, Penuh*

### 🚪 **Kontrol Tutup Otomatis**

* Servo motor membuka & menutup berdasarkan jarak
* Mode manual tersedia di folder `tutupmanual/`

### 📡 **Pengiriman Data ke Cloud**

* Firebase Realtime Database (folder `Firebase_Smart/`)
* Thinger.io IoT Cloud (folder `Thinger.io/`)
* Data dikirim dari ESP8266/ESP32

### 🔔 **WhatsApp Auto Notification**

* Folder `WANotif/` berisi script WA alert
* Mengirim pesan jika sampah mencapai level tertentu

### 🔄 **Integrasi Modul Tambahan**

* Folder `MITT/` berisi modul eksperimen

---

# 🎞️ **Visualisasi Cara Kerja Sistem**

<p align="center">
  <img src="https://media.giphy.com/media/26BoCIZm8H0Lz1Xvy/giphy.gif" width="650">
</p>

---

# 🧩 **Tech Stack yang Benar-benar Dipakai di Projek Ini**

| Layer            | Teknologi                             |
| ---------------- | ------------------------------------- |
| **Hardware**     | ESP8266 / ESP32, HC-SR04, Servo SG90  |
| **Firmware**     | Arduino IDE, C++ Microcontroller Code |
| **Cloud**        | Firebase, Thinger.io                  |
| **Notification** | WhatsApp Gateway (Python/Node)        |
| **Frontend**     | Dashboard sederhana (opsional)        |

---

# 🗂️ **Struktur Projek Asli (Disesuaikan dari Repo Kamu)**

```
IoT-SmartTrash
├── SmartTrash/          # Firmware utama: sensor, servo, WiFi, cloud
├── Firebase_Smart/      # Setup Firebase + rules
├── Thinger.io/          # Setting device & bucket Thinger.io
├── WANotif/             # WhatsApp Notification Script
├── firebasecode/        # Source config + penyimpanan data
├── tutupmanual/         # Mode tutup manual via tombol
└── MITT/                # Modul opsional / fitur eksperimen
```

---

# 🧠 **Arsitektur Sistem Sesuai Cara Kerja Nyata**

```
                ╔══════════════════════╗
                ║   Sensor HC-SR04     ║
                ╚═══════╦══════════════╝
                        │ Jarak Sampah
                ╔═══════▼══════════════╗
                ║   ESP8266 / ESP32    ║
                ║  (Firmware di repo)  ║
                ╚═══════╦══════════════╝
        WiFi Data       │ Kontrol Servo
                ╔═══════▼══════════════╗
                ║     Cloud System     ║
                ║ Firebase | Thinger.io ║
                ╚═══════╦══════════════╝
                        │ Status Sampah
       ╔════════════════▼═════════════════╗
       ║   Dashboard / WhatsApp Alert     ║
       ╚══════════════════════════════════╝
```

<p align="center">
  <img src="https://media.giphy.com/media/LMcB8XospGZO8UQq87/giphy.gif" width="430">
</p>

---

# ⚙️ **Cara Instalasi & Menjalankan Sistem**

### 1️⃣ Clone Repository

```bash
git clone https://github.com/WildanFadillah1512/IoT-SmartTrash.git
```

### 2️⃣ Upload Kode ESP

Masuk folder **SmartTrash/**

* Edit SSID & PASSWORD WiFi
* Pilih board ESP8266/ESP32
* Upload melalui Arduino IDE

### 3️⃣ Setup Firebase

* Masuk folder `Firebase_Smart/`
* Ikuti petunjuk setup JSON & rules
* Masukkan API Key ke firmware

### 4️⃣ Setup Thinger.io (Opsional)

* Folder `Thinger.io/` berisi konfigurasi device + bucket

### 5️⃣ Aktivasi WhatsApp Notification

* Jalankan script di folder `WANotif/`
* Sesuaikan nomor penerima

---

# 🔮 **Future Upgrade Kemungkinan di Projek Kamu**

* AI detection untuk klasifikasi sampah
* Solar panel untuk power mandiri
* Dashboard monitoring versi mobile
* Statistik timbulan sampah
* API ke sistem Smart City

---

# 🏅 **Project Badges**

<p align="center">
  <img src="https://img.shields.io/badge/SmartTrash-IoT%20Project-003366?style=for-the-badge">
  <img src="https://img.shields.io/badge/Firebase-Connected-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Thinger.io-Integrated-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Servo-Automation-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/WildanFadillah1512-Developer-00eaff?style=for-the-badge">
</p>

---

# 👤 **Author**

**Wildan Fadillah**
[https://github.com/WildanFadillah1512](https://github.com/WildanFadillah1512)

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&height=140&color=0:000000,100:003366&section=footer&text=SMARTTRASH%20IoT%20PROJECT&fontColor=00eaff" />
</p>
