# Bass-Synth-Pedal
A budget-friendly bass synthesizer pedal with square and triangle wave generation, designed and built for a university project. The objective of this project is to design and build a bass synthesizer pedal within a 20-euro budget. This budgetary constraint was not chosen out of necessity but as a deliberate design decision to limit the project's complexity and emphasize resourceful engineering.

The resulting pedal, named Son of Coulomb, processes the sinusoidal input signal from a bass guitar and offers several unique features. A dedicated switch allows the user to transform the input signal into either a triangular or square waveform. Another switch enables frequency multiplication, offering the option to shift the output one or two octaves higher (frequency multiplied by 2x or 4x).

The PCB design includes exposed pins for a microcontroller, allowing users to develop and upload custom effects. By connecting the microcontroller via jumpers, you can replace the default effect, which shifts the input signal one or two octaves up, with any custom effect of your choice through programming. This feature enhances the pedal's versatility and adaptability for creative experimentation.

Additionally, the pedal includes a 3PDT true bypass functionality, providing the user with seamless control to toggle between the unprocessed bass sound and the synthesized effect. This combination of simplicity, functionality, and cost-efficiency makes the Son of Coulomb an excellent showcase of analog signal processing and creative circuit design.

# How It Works: Flow Overview

To provide a clear understanding of the pedal's operation, the following workflow diagram outlines the core processes involved. This simple representation breaks down the system into distinct functional blocks, offering an intuitive overview of how the components interact. Below the diagram, each block is explained in detail to highlight its role within the system. Let’s explore each block step by step to understand how the Son of Coulomb transforms the input signal into the synthesized effect.

![image](https://github.com/user-attachments/assets/83aed728-75ff-45c2-9c80-5049d6592d68)

**Pre-Amplifier:** Before connecting the bass signal directly to the microcontroller, the signal must be amplified and offset to ensure compatibility with the microcontroller's input voltage range of 0 to 3.3V. Since the bass signal typically ranges between -100 mV and 100 mV, it is first offset to 1.65V (the midpoint of the microcontroller's input range) and then amplified to bring the signal within the acceptable voltage levels for accurate processing.

**MCU:** Within the microcontroller, the input signal is processed to extract its frequency. This frequency is then used to generate a PWM signal on two separate output pins, with the frequency scaled by a factor of 2 or 4, depending on the selected mode.

**SW1:** This switch simply selects whether the input frequency is multiplied by a factor of 2 or 4.

**Triangle Generator:** As the name suggests, the incoming signal from the microcontroller is converted from a square wave to a triangular wave using an integrator op-amp configuration.

**SW2:** This switch simply selects either a square or triangle wave, and its output goes directly to the effect output.

**Effect Bypass:** The effect bypass block, controlled by a 3PDT switch, determines whether the effect is active or bypassed. When the effect is enabled, the LED turns on, and the bass-guitar signal passes through the effect circuit. If the effect is bypassed, the signal is routed directly to the output jack, as depicted in the diagram.

**More details of the circuit can be seen in the "schematic" folder!**








