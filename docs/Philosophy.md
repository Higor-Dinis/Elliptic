# Eliptic Language Philosophy

*Higor Dinis, 01/07/2025*

---

## **The Vision**

**Eliptic** was born with a simple premise: to make **microcontroller programming** faster, simpler, and less error-prone. The primary goal of the language is to provide a reliable structure for writing code that can run on a wide variety of microcontrollers.

**It is not a general-purpose language** and does not aim to replace languages like **C**, **C++**, or **Rust**. Instead, **Eliptic** focuses on offering a streamlined and efficient development experience for embedded systems and microcontroller applications.

---

## **Core Philosophy**

- **Simplicity over Complexity**:  
  If something can be simple and still performant, we prefer it that way. While hardware may improve over time, developers are often constrained by the pace of technological advancements and the complexity of modern systems. Eliptic seeks to eliminate unnecessary complexities to maximize **productivity** and **maintainability**.

- **The Implementation Responsibility**:  
  The burden of implementation lies with the developer of the language tools, not the user. **Eliptic avoids** introducing features that may simplify the implementation at the cost of the end user’s experience. This philosophy ensures that the programmer can focus on building solutions rather than workarounds.

- **Abstraction in Code**:  
  If abstraction can make code more **portable**, **cleaner**, or **less prone to bugs**, it should be used—even at the expense of some performance. Eliptic promotes code that is both **functional** and **maintainable**, even if that means trading off certain low-level optimizations in favor of clearer, more predictable behavior.

- **Expressiveness and Legibility**:  
  "*Code is read more often than it is written*." Software engineers don't just write code for themselves; they write code for others. As such, **Eliptic prioritizes expressiveness and legibility**. The language is designed to make code just as **easy to read** as it is to write. This approach encourages **better collaboration** and **long-term maintainability**.

- **Warn on Bad Practices**:  
  Eliptic is designed to help developers **avoid common pitfalls**. If a piece of code is **error-prone**, **inefficient**, or could negatively impact **performance**, Eliptic will issue warnings. These warnings ensure that the developer is aware of potential risks and can make an **informed decision**. Developers are encouraged to consciously accept risks, knowing the trade-offs involved.

- **You don't pay for anything you don't use**:  
  Eliptic follows the principle of "**zero-cost abstractions**." If you don’t use a feature, you don’t pay for it in terms of **memory** or **performance** overhead. The language design ensures that abstractions remain **efficient** and that the cost of unused features is minimized, allowing developers to use only what they need without unnecessary overhead.

- **Open and Inclusive Development**:  
  **Eliptic is an open-source project** that values collaboration and community contributions. We believe that the best solutions often come from a **diversity of perspectives**, and we encourage developers from all backgrounds to participate in shaping the future of the language. **Transparency** and **community-driven development** are core principles of Eliptic.

---

## **Design Goals**

- **English-like Syntax**:  
  Code should not require deep analysis of each word. It should **read like simple, everyday English text**. If someone who doesn't know programming cannot even guess what’s happening, the code is not written well. The goal is to make the code as **intuitive** and **readable** as possible, so even **non-programmers** can understand the general idea of what the program is doing.

- **One Code, Many Microcontrollers**:  
  The goal is for the **same code** to run on as many microcontrollers as possible. **Abstractions** are designed to abstract away any direct hardware interaction — unless the user specifically chooses to interact with the hardware directly. This approach enables **portability** across different platforms while still offering the flexibility to fine-tune low-level operations when needed.

- **Pragmatic and Practical**:  
  **Eliptic takes a pragmatic approach** to language design. Instead of adhering to strict theoretical purity, we favor **practical solutions** that work well in **real-world scenarios**.

- **Strong Standard Library**:  
  A well-designed **standard library** is crucial for any programming language. Eliptic will come with a **robust set of built-in functions** and modules, but we will avoid unnecessary bloat.

- **Tooling and Ecosystem**:  
  Eliptic aims to build a **rich ecosystem** of tools, libraries, and frameworks that enhance **productivity**. From **debuggers** to **package managers**, the ecosystem should make Eliptic an enjoyable language to work with.

---

## **Use Cases**

Eliptic is designed for **microcontroller programming**, particularly in the following scenarios:

- **Embedded Systems**:  
  Eliptic excels in environments where **low-level control** over hardware is required, but where simplicity and maintainability are also a priority.
  
- **Internet of Things (IoT)**:  
  The language is suitable for **IoT projects** that involve a large number of devices with potentially limited resources.

- **Wearable Devices**:  
  Eliptic offers an ideal balance between **performance** and **ease of use** for developing applications on small, constrained hardware.

- **Robotics and Automation**:  
  With its focus on direct hardware interaction and **real-time performance**, Eliptic is well-suited for robotics projects.

---

## **Target Audience**

Eliptic is primarily aimed at:

- **Embedded Systems Developers**:  
  Engineers who work with microcontrollers, designing hardware-software solutions for embedded systems.

- **Hobbyists and Makers**:  
  Individuals building their own microcontroller-based projects or prototyping new products.

- **Students and Educators**:  
  Those learning about **microcontroller programming** in academic or research contexts, offering a more approachable syntax compared to traditional embedded languages.

---

## **Future Vision**

The future of Eliptic is driven by the goal of making **microcontroller programming** as accessible and efficient as possible. As hardware continues to evolve, Eliptic will adapt, providing new abstractions and optimizations to keep up with the advancements in embedded systems.

- **Multi-core Support**:  
  Future versions of Eliptic may include tools and abstractions to support programming on **multi-core microcontrollers**, enabling **concurrent programming** in an intuitive way.

- **Real-time Operating Systems (RTOS) Integration**:  
  Eliptic is moving towards better support for **real-time systems**, with potential integration with existing **RTOS solutions**.

- **Broader Hardware Compatibility**:  
  While Eliptic is focused on microcontrollers, it will continue to expand support for a wide range of **devices**, including more specialized chips, sensors, and peripherals.

---

## **Contributing to Eliptic**

Eliptic is an **open-source project**, and we welcome contributions from the community. Whether you are interested in submitting **bug reports**, **writing documentation**, or adding new features, we encourage you to get involved.

### **How to Contribute**

1. **Fork the Repository**:  
   Start by forking the official **Eliptic repository** on GitHub.
   
2. **Submit Issues**:  
   If you encounter bugs or have suggestions for improvements, open an **issue** on GitHub.
   
3. **Submit Pull Requests**:  
   Once you have made changes or added new features, submit a **pull request** with a description of the changes.

4. **Join the Community**:  
   Participate in discussions, share ideas, and collaborate with other developers to improve the language.

---

**We are excited to have you on this journey to make microcontroller programming faster, simpler, and more efficient. Welcome to the Eliptic community!**
