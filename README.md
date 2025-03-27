# 📱 STM32 NEC IR Remote Decoder

This project implements an **NEC IR remote decoder** using an **STM32 microcontroller**. It captures and processes IR signals from an **NEC protocol remote**, enabling control of various peripherals like LEDs, motors, or displays.

---

## 📚 Overview

📌 **Key Features:** ✅ **STM32 LL (Low Layer) API-based implementation** ✅ **Decodes NEC IR protocol** (Start pulse, Address, Command, Repeat) ✅ **External Interrupt Handling for IR Signal Capture** ✅ **Uses Timer for accurate signal timing** ✅ **Can control GPIO pins based on remote commands**

📌 **Why This Project?** This project is ideal for **learning embedded systems**, **interrupts**, **timers**, and **NEC IR communication protocols**.

---

## 🚀 Getting Started

### 🛠️ **Hardware Requirements**

- 🔹 **STM32 Development Board** (STM32F103, STM32F4xx, or similar)
- 🔹 **IR Receiver Module** (TSOP1738, VS1838B, or equivalent)
- 🔹 **NEC-Compatible IR Remote**
- 🔹 **LEDs, Resistors, and Jumper Wires**

### 💻 **Software Requirements**

- 🔹 **STM32CubeIDE** (or Keil uVision, IAR Embedded Workbench)
- 🔹 **STM32CubeMX** (Optional for configuring peripherals)
- 🔹 **ST-Link V2** (For debugging & programming)

---

## 🔧 Circuit Diagram

📌 **Connections (STM32 & IR Receiver - TSOP1738)**

| IR Receiver Pin | STM32 Pin             | Description     |
| --------------- | --------------------- | --------------- |
| **VCC**         | **3.3V / 5V**         | Power Supply    |
| **GND**         | **GND**               | Ground          |
| **OUT**         | **PA1 (EXTI Line 1)** | IR Signal Input |

---

## 📝 **Code Breakdown**

### 🏰 **1. Initialization (NEC\_Decoder\_Init)**

This function initializes **GPIO, EXTI (External Interrupts), and Timer**.

```c
void NEC_Decoder_Init(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  SystemClock_Config();
  GPIO_Init();
  NEC_Timer_Init();
}
```

### 🏰 **2. GPIO & EXTI Configuration (GPIO\_Init)**

Configures the **GPIO pin for the IR receiver** and sets up an **external interrupt (EXTI)**.

```c
static void GPIO_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  LL_EXTI_InitTypeDef EXTI_InitStruct = {0};

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

  GPIO_InitStruct.Pin = LL_GPIO_PIN_5;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTB, LL_SYSCFG_EXTI_LINE5);
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_5;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  NVIC_SetPriority(EXTI9_5_IRQn, 5);
  NVIC_EnableIRQ(EXTI9_5_IRQn);
}
```

---

## 📈 **NEC Protocol Overview**

| Signal Type       | Timing (µs)              | Description         |
| ----------------- | ------------------------ | ------------------- |
| **Start Pulse**   | 9000µs HIGH + 4500µs LOW | Initial signal      |
| **Bit "1"**       | 562µs HIGH + 1687µs LOW  | Represents binary 1 |
| **Bit "0"**       | 562µs HIGH + 562µs LOW   | Represents binary 0 |
| **Repeat Signal** | 9000µs HIGH + 2250µs LOW | Repeat command      |

---

## 🚦 **Example Output (UART Debugging)**

When an IR remote button is pressed, the **decoded output** (Address & Command) is displayed via **UART**:

```
NEC Signal Received:
Address: 0x00FF
Command: 0x20DF
```

---

## 🔧 **How to Run the Project**

### 1️⃣ **Clone the Repository**

```sh
git clone https://github.com/yourusername/STM32-NEC-IR-Decoder.git
cd STM32-NEC-IR-Decoder
```

### 2️⃣ **Open in STM32CubeIDE**

- Import the project into **STM32CubeIDE**.
- Compile the project (`Build → Clean & Build`).
- Flash it to the STM32 board using **ST-Link**.

### 3️⃣ **Test the IR Receiver**

- Open a serial terminal (e.g., **PuTTY**, **Tera Term**).
- Set baud rate: **115200**.
- Press buttons on the **NEC Remote** and check the decoded signals.

---

## 🛠️ **Future Improvements**

🔹 Add **support for more IR remote control protocols** (Sony, RC5, etc.) 🔹 Integrate **FreeRTOS** for multitasking 🔹 Use **DMA (Direct Memory Access)** for optimized efficiency

---

## 📚 **License**

This project is licensed under the **MIT License**.

---

## 💬 **Contributions & Support**

💡 Found a bug? Have suggestions? Feel free to **open an issue** or submit a **pull request**.

🚀 **Follow & Star this repo** if you find it useful!

