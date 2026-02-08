# ⚛️ Quantum Circuit Probability Display (Arduino)

A simple **quantum-inspired optical experiment** using **Arduino UNO**,
a **laser beam splitter**, and **LM393 LDR sensors** to visualize
probabilistic outcomes on a **16x2 I2C LCD**.

> ⚠️ This is **not a real quantum computer** --- it simulates
> quantum-like probability behavior using light and sensors.

------------------------------------------------------------------------

## ✨ Features

-   Laser controlled by Arduino 
-   Dual light-path detection using **two LM393 LDR modules**\
-   Real-time probability display: **P(0)** and **P(1)**\
-   Shows **`SUPERPOS`** when both paths are detected simultaneously

------------------------------------------------------------------------

## 🧰 Hardware Required

-   Arduino UNO\
-   16x2 I2C LCD\
-   Laser module\
-   Beam splitter\
-   2 × LM393 LDR sensor modules\
-   Breadboard + jumper wires

------------------------------------------------------------------------

## 🔌 Wiring (Quick Guide)

  Component   Arduino Pin
  ----------- -------------
-  Laser VCC   D8
- LDR #1 DO   D2
- LDR #2 DO   D7
- LCD SDA     A4
- LCD SCL     A5
- All VCC     5V
- All GND     GND

------------------------------------------------------------------------

## 🧠 How It Works

1.  Laser passes through a **beam splitter**, creating two paths.\
2.  Each path hits an LDR sensor.\
3.  Arduino samples both sensors repeatedly.\
4.  It computes detection probabilities.\
5.  LCD displays either:
    -   `P0: xx%  P1: yy%` **or**\
    -   `SUPERPOS` (when both sensors detect light).

------------------------------------------------------------------------

## 📺 LCD Output Example

    P0: 65%   P1: 35%

or

    SUPERPOS

------------------------------------------------------------------------

## ✅ Result

This setup visually demonstrates light-based probabilistic behavior with
simple electronics and clear LCD feedback.



