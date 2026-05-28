<div align="center">
  
# 🍎 Smart Fruit Sorting System 🍏
**1st Place Winner @ Arduino End Game Hackathon**

[![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Computer Vision](https://img.shields.io/badge/Computer_Vision-5C3EE8?style=for-the-badge&logo=opencv&logoColor=white)](https://opencv.org/)

A cute but mighty automated conveyor belt system designed to support Palestinian farmers by sorting crops based on quality and size in real-time! 🚜✨

</div>

---

## 🎥 See it in Action!

Watch the hardware and computer vision logic working together to sort the fruit:

<div align="center">
  <a href="https://youtube.com/shorts/e4Xua6-JjoE">
    <img src="https://img.youtube.com/vi/e4Xua6-JjoE/0.jpg" width="400" alt="Fruit Sorter Demo"/>
  </a>
  <br>
  <i>Click the image to watch the YouTube Short! 👆</i>
</div>

---

## 🌱 What is it?
This repository contains the C/C++ firmware for the **Smart Fruit Sorting System**. Built as a rapid prototype during the Arduino End Game Hackathon (where it took home **1st Place** 🏆), this project bridges the gap between software intelligence and mechanical hardware.

The system uses **Computer Vision** to analyze incoming fruit on a moving conveyor belt. Based on size and quality parameters, the Arduino microcontrollers physically route the fruit into the correct bins. 

**The best part?** It's designed with sustainability in mind. Any fruit rejected by the system is automatically diverted to be repurposed as organic fertilizer. ♻️

## ⚙️ How It Works
1. **Vision:** A camera feed processes the incoming fruit using a lightweight CV script to determine size and detect any visual defects.
2. **Logic:** The quality data is sent to the Arduino via serial communication.
3. **Action:** The Arduino triggers specific servo motors along the custom-built conveyor belt to intercept the fruit and gently push it into its designated sorting bin.

## 🛠️ Hardware & Tech Stack
* **Microcontroller:** Arduino Mega / Uno
* **Language:** C/C++ (Arduino IDE)
* **Mechanics:** Custom-built conveyor belt, continuous rotation servos, positional servos.
* **Sensors:** Standard web camera for CV feed.

## 🚀 Running the Code
1. Clone this repository: `git clone https://github.com/SimplyRuba/smart-fruit-sorter.git`
2. Open the `.ino` file in the **Arduino IDE**.
3. Ensure you have the standard `Servo.h` library installed.
4. Select your Arduino board and COM port, then click **Upload**.

---
<div align="center">
  <i>Built with ❤️ and a lot of coffee by <a href="https://github.com/SimplyRuba">Ruba Aldaghamin</a>.</i>
</div>
