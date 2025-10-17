# ATtiny85 USB Brute-Force PIN Cracker

A minimalist USB brute-force tool developed using V-USB and an ATtiny85 microcontroller. Emulates a USB HID keyboard to try 4-digit PIN combinations sequentially (0000–9999).

---

### 🔧 Developed By:
**CHRIZ**  
Website:
Instagram: [@chriz_3656](https://instagram.com/chriz_3656)  
GitHub: [chriz](https://github.com/chrizmonsaji.github.io)

---

### ⚙️ Features
- 4-digit brute-force using HID emulation
- Dynamic generation (no memory storage of codes)
- Fully autonomous when plugged in
- Uses V-USB for software-based USB on ATtiny85

---

### 🛠️ Built With
- C (AVR-GCC)
- V-USB (by Objective Development)
- ATtiny85 Microcontroller

---

### ⚠️ Disclaimer
This tool is for **educational and ethical use only**. Do not use on unauthorized systems. The author is not responsible for any misuse. Attempting unauthorized access is illegal in most jurisdictions.

---

### 📋 Prerequisites

- **Hardware**: ATtiny85 microcontroller, USB-to-ISP programmer (e.g., USBasp)
- **Software**: `avr-gcc`, `avr-libc`, `avrdude`
- **V-USB Library**: Download from [obdev.at/vusb](https://www.obdev.at/products/vusb/download.html) and place the `usbdrv/` folder in this project directory.

---

### 🚀 Installation & Usage

1. **Clone the repository**:
   ```bash
   git clone https://github.com/chriz3656/ATtiny85-USB-Brute-Force-PIN.git
   cd ATtiny85-USB-Brute-Force-PIN
