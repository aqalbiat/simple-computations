# This is my repository for the programming language called Simple Computations

- I will design a programming language and implement an interpreter for it.
- For now I will use topdown approach for parsing.
- Rumors say that the UNIX operating system was finished in 3 weeks. I want to challenge myself and see how much time I would spend on it. 

## My plan for the implementation

- Come up with 25 examples of small programs written in Simple Computations
- Create a CFG rule for parsing all of the example
- Implement a lexer that will tokenize the input
- Implement a topdown parser that realises the sufficient grammar
- Implement an evaluator given an AST from the topdown parser

## Some of the examples in this language

### First example

- This program just read 3 numbers and calculates their average 

```

job main() start

    make a(real, 5);
    make b(real, 5);
    make c(real, 5);

    listen(a, b, c);

    make res(real, 5) = (a + b + c) / 3.0;

    serve(res);

finish

```

- The general syntax for creating and initializing varialbes:

```

make a(real, 5);

```

Here the name of the variable is *a* and and it is type of *real* with 5 decimal digits saved after the dot. 

---

### Second example

- This is the program that calculates the GCD of two integers

```

job gcd(make x(integer), make y(integer)) (integer) start

    if (lt(x, y)) start
        return call(gcd, y, x);
    finish

    if (eq(y, 0)) start
        return y;
    finish

    x = x - y;
    return call(gcd, x, y);

finish

job main() start

    make a(integer);
    make b(integer);

    listen(a, b);

    make g(integer) = call(gcd, a, b);

    serve(g);

finish

```

In this example it is seen that functions are created using the special word *job* and they can be called by *call*

---
