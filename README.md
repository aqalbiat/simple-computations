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

## Interperter implementation progress bar

1. Examples:             ![](https://geps.dev/progress/72)

2. Grammar:              ![](https://geps.dev/progress/0)

3. Tokenizer:            ![](https://geps.dev/progress/0)

4. Parser:               ![](https://geps.dev/progress/0)

5. Evaluator:            ![](https://geps.dev/progress/0)


## Some of the examples in this language

### First example

- This program just read 3 numbers and calculates their average 

```

job main() start

    make a(real(5));
    make b(real(5));
    make c(real(5));

    listen(a, b, c);

    make res(real(5)) = div(add(a, b, c), 3.0);

    serve(res);

finish

```

- The general syntax for creating and initializing varialbes:

```

make a(real(5));

```

Here the name of the variable is *a* and and it is type of *real* with 5 decimal digits saved after the dot. 

In addition, special functions for arithmetic operations will be used: *add*, *sub*, *mul*, *div*.

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

    x = sub(x, y);
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

- In this example it is seen that functions are created using the special word *job* and they can be called by *call*

```

job gcd(make x(integer), make y(integer)) (integer) start

...

make g(integer) = call(gcd, a, b);

```

Also, for comparisions and logical operations some special functions will be used: *lt*, *gt*, *eq*, *and*, *or*, *not*

---

### Third example

- This program read an array and sorts it with some quadratic sorting algorithm

```

job main() start

    make a(array(integer, 10));

    make i(integer) = 0;

    loop (lt(i, 10)) start
        listen(at(a, i));
        i = add(i, 1);
    finish

    i = 0;

    loop(lt(i, 10)) start
        make j(integer) = i;
        loop(lt(j, 9)) start
            if (gt(at(a, j), at(a, add(j, 1)))) start
                make tmp(integer) = at(a, j);
                at(a, j) = at(a, add(j, 1));
                at(a, add(j, 1)) = tmp;
            finish
        finish
    finish

    i = 0;

    loop(lt(i, 10)) start
        serve(at(a, i));
    finish

finish

```

Here an array could be created in similar manner as variables but with special keyword *array*. 

And *loop* will be used to carry out repeated actions. 

---
