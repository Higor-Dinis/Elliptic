# Elliptic

![Untitled-1](https://github.com/user-attachments/assets/ce5a97a1-a5fe-48f7-9723-ea7b18efa108)



## The project
Elliptic is a open-source, MIT licensed, compiled programming language. The basic premisse is be a easy, programmer-friendly language.

## How to build

### Pre-requisites:
- CMake 3.5.0 or later;
- GCC 13.3.0 or later;
- Ninja-build 1.11.1 or later;
- Git

### Installing dependencies
Debian/Ubuntu:
```bash
$ sudo apt install cmake gcc ninja-build
```

Homebrew:
```bash
$ brew install cmake gcc ninja-build
```

### Building
Clone the repository:
```bash
$ git clone https://github.com/Higor-Dinis/Elliptic
```

Create build files:
```bash
$ mkdir Elliptic/build 
$ cd Elliptic/build 
$ cmake -G Ninja ..
```

Building:
```bash
$ ninja .
```

To build documentations run:
```bash
$ mkdir docs
$ doxygen
```

## How to contribute

We welcome contributions from the community! Here are some ways you can get involved:

1. **Report Bugs**: If you find a bug, please report it by creating an issue on our [GitHub Issues](https://github.com/Higor-Dinis/Elliptic/issues) page.

2. **Submit Pull Requests**: If you have a fix or a new feature, feel free to submit a pull request. Please ensure your code follows our coding standards and includes tests.

3. **Improve Documentation**: Help us improve our documentation by making it clearer and more comprehensive.

4. **Feature Requests**: If you have an idea for a new feature, please open an issue to discuss it.

### Steps to Contribute

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Make your changes.
4. Commit your changes with a clear message.
5. Push your changes to your fork.
6. Open a pull request against the main repository.

Thank you for your contributions!
