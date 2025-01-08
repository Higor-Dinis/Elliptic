# Elliptic Language Concepts

*Higor Dinis, 01/07/2025*

***Note: As the language grammar isn't fully defined yet, we will use C++ code to illustrate***

---

## Technical Concepts

### No Special Types

In the Elliptic language, there are no exceptions, optional types, or variant types. If a piece of code needs to exchange data with another, it has to be using a normal type.

See this C++ code:

```Cpp
#include <exceptions>

void error_function() {
  throw std::exception(); // Throwing an exception
}

int main() {
  try {
    error_function();
  } catch (std::exception& e) {
    // ... Error handling logic
  }
}
```

In this case, an exception is being thrown to indicate an error. This is a common pattern in many programming languages, but it introduces complexity and makes code harder to follow and debug.

Instead, Elliptic encourages a simpler approach, where errors are returned as values:

```Cpp
int error_function() {
  return 1; // Return an error code
}

int main() {
  if (error_function() != 0) {
    // ... Error handling logic
  }
}
```

This approach allows errors to be dealt with as soon as they occur, rather than propagating them further down the code.

### Assembly Integration

*Warning: Any assembly code added in the program will not be tested or verified by the compiler.*

In Elliptic, we have a keyword-function for running assembly code directly within the program. The assembly code is architecture-specific, meaning it will be tailored to the target machine.

The `asm` keyword will work as in this example:

```C++
int main() {
  asm("mov eax, 0x20"); // Only one instruction

  asm(                  // Many instructions
    "mov eax, 0x20;",
    "add eax, 4;"
  );
}
```

To reference an variable or function in the assembly code, use the `get_pointer()` function. Like this:

```C++
int main() {
  int number = 1;

  asm("lea eax, {};", get_pointer(number)); // Ex.: lea eax, 0xab42e59f;
}
```

### Strong Typing, Nothing is Implicit

The programming language is made to help users, not to betray them. If there's any thing happening without the user knowing, it's a problem.

For example, in many languages, you might be able to assign an integer to a float without any explicit conversion:

```Cpp
int a = 5;
float b = a; // Implicit casting
```

In Elliptic, this will result in a compile-time error unless you explicitly convert the integer to a float:

```Cpp
int a = 5;
float b = (float) a; // Explicit casting
```

### More Concepts Coming...