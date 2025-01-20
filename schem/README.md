# Schematic

This schematic represents the complete design of the project. It outlines all key subcircuits that contribute to its functionality. We will now analyze each subcircuit in detail to understand their roles and operation.

![image](https://github.com/user-attachments/assets/d8c764d4-5326-4d2e-8b18-51b88d6bd3e0)

# Power Supply
![image](https://github.com/user-attachments/assets/0378fc6e-d056-4ee1-bd46-c0d97cd6e653)

This is the power supply stage, designed to provide stable voltages for the circuit. The LM317 voltage regulator (IC1) is configured to generate a 3.3V output using resistors R7 and R1, with capacitor C3 providing additional stability. The input to the regulator is filtered by capacitor C5 to reduce noise. Additionally, a bias voltage is generated using a resistor divider network (R2 and R8), providing an offset of approximately 1.55V. This bias voltage is further stabilized by capacitor C4, ensuring a clean reference for subsequent stages in the circuit.

# Amplifier with Offset
![image](https://github.com/user-attachments/assets/09e346fe-8508-4d01-9cf9-f7aebf39222e)

This is the amplifier stage, primarily responsible for processing the signal before it is sent to the MCU. Resistor R17 provides high input impedance to preserve the signal integrity from the bass. The bias voltage, derived from the previously discussed power supply stage, offsets the signal by approximately 1.55V. The signal then passes through the voltage follower implemented with U1A and is subsequently amplified with a gain of approximately K=5.6 in U1B. The amplified output from U1B is connected directly to the MCU for further processing.

# MCU - STM32F103C8T6
![image](https://github.com/user-attachments/assets/b7a526fa-1839-4dd0-95df-f8d2deb914fb)

This is the MCU stage, centered around the STM32F103C8T6 microcontroller, which handles signal processing and wave generation. The crystal oscillator (Y1) and its accompanying capacitors (C7 and C8) provide an 8 MHz clock for precise operation. The NRST pin is connected to a reset circuit, comprising a pull-up resistor (R3), a decoupling capacitor (C11), and a push-button (SW4) for manual resets.

For boot mode selection, the BOOT pin is configured using SW5 and pull-down resistor R15. The programming interface is accessible via J4, which connects the SWDIO and SWCLK lines for debugging and firmware uploads. Power stability is ensured with decoupling capacitors close to the MCU power pins, while pull-up resistor R4 supports proper initialization of the SWDIO line. Together, this stage forms the control hub of the system.

# Triangle Wave & Wave Selection
![image](https://github.com/user-attachments/assets/df4698e5-ad41-4753-bd61-02598cf24c67)

This is the triangle wave generator and wave selection stage. The input signal is chosen using the SPDT switch SW1, which selects between FX1 (2x frequency multiplier) and FX2 (4x frequency multiplier), sending the selected signal to the square wave output (SQR_OUT). The square wave is processed by a resistor-capacitor network (R5, R6, and C1), that basically removes the DC component of the signal so it can be fed into the integrator circuit implemented with U2A (LM358), which generates a triangle wave.

The SPDT switch SW2 allows selection between the square wave and triangle wave output. The chosen waveform is buffered by U2B, ensuring proper drive strength and signal integrity. The final output, labeled as 'Effect_out,' is conditioned by a resistor network (R9, R10) which decreases the amplitude of it to 10%, and decoupling capacitor C6 for stability and signal shaping. This stage provides the flexibility to toggle between waveforms.

# Effect Toggle - 3PDT
![image](https://github.com/user-attachments/assets/ce397643-1a83-4f6f-8fe7-9fcd4d6e580a)

This is the toggling effect stage, which determines whether the signal bypasses the effect or passes through it. When the effect is activated, the LED illuminates, the input jack is connected to the effect input, and the effect output is routed to the output jack.

When toggled off, the LED turns off, the effect input is grounded to discharge any capacitors, and the input and output jacks are directly connected, bypassing the effect entirely and routing the signal straight to the amplifier.

# MCU Pin Headers
![image](https://github.com/user-attachments/assets/2aaf107c-7623-48d6-acda-98720cfc05ae)

In this section, the MCU pins are directly routed to headers, enabling the use of the circuit as a versatile 'Pedal Effect' development board. This design allows users to create custom effects by programming the MCU and connecting the desired pins to the board for their specific effects. The SPDT switch (SW1) facilitates toggling between two effects, allowing up to two effects to be used simultaneously with seamless switching.




