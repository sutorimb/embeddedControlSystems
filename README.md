# Embedded-Control-Systems
University of Michigan Embedded Control Systems Lab
# OVERVIEW: 
Learned how to use a microprocessor as a component of an embedded control system. Used a haptic interface, which uses force feedback to enable a human to interact with a computer through the sense of touch. 
# Lab Topics:
• Sampling. Position and Velocity Measurements. Encoders. Quadrature Decoding. 
• The MPC5643L eTimer and its Quadrature Decoding function. • Pulse Width Modulation (PWM). Frequency response of PWM signals. DC motors. Ampliﬁers. Interface electronics.
• Haptic interfaces. Virtual worlds. Human-computer interaction. Applications to games, manufactur-ing and robotics, drive-by-wire aircraft and automobiles, ﬂight and surgery simulators, video editing. “Artifacts” due to microprocessor implementation of the virtual world.
• Algorithms. Feedback systems. PID control. Logic control and ﬁnite state machines. Numerical integration. Implementing a virtual world on a microprocessor.
• Concepts from real time operating systems. Interrupts. Shared data. Latency. Round-robin architec-tures. Single vs. multitasking. Semaphores.
• Real time computation. Rate monotonic scheduling.
• Modeling. Use of MATLAB/Simulink/Stateﬂow to simulate the interaction of a virtual world with a human operator through the haptic interface.
• Networking. Control Area Network (CAN) vs. Ethernet protocol. The CAN unit on the MPC5643L. 
• Rapid prototyping and autocode generation.
# Laboratory
Develop an embedded controller for a haptic interface in C. Implemented the controller over a CAN network to study performance degradation due to networking delay. Recreated our work using rapid prototyping tools to generate C code directly from a Simulink model of the haptic virtual world.
# Project
Developed an adaptive cruise control system allowing diﬀerent lab groups to interact over the network and receive both visual feedback from a computer monitor as well as haptic feedback.   