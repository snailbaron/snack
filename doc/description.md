# Everything in this file is a fantasy, and is not yet implemented.

`snack` is a simple data format, unrestricted by stupid computer stuff.

## **Snacks**

A `snack` file always contains a **snack**. You can think of it as a "value" of
sorts.

It might be simple, it might be complex. In fact, it might be as simple as a
single integer:
```
123
```

Or any decimal, if you add a decimal point:
```
123.456
```

Or a string:
```
"hello-hello"
```

Those three types of **snacks** are called **scalars**. They are the atomic
blocks of any **snack**, the simplest possible values. The type of a **scalar**
is always obvious: a decimal always contains a decimal point, a string is always
quoted.

A key-value pair is also a **snack**:
```
"key" = "value"
```
The key and its value are separated by "=", with optional **good whitespace**
around it: spaces, tabs, and newlines. Fancy stuff such as vertical tabs is not
allowed. In fact, you can use **good whitespace** as much as you want: add empty
lines, offsets and such.

Keys are not limited to strings:
```
12 = "twelve"
```

In fact, you can use any **snack** as a key. More on that later.

Several **snack** values one after another constitute a **composition**:
```
1 2 "hello" "one two three"
```
**Composition** elements are separated by **good whitespace**, expectedly.

And because a key-value pair is also a **snack**, it can be a member of a
**composition** as well:
```
1 2 "key" = "value" "something else"
```

You can think of a **composition** as a mix of lists and dictionaries of sorts.
The composition above has integers at positions 0 and 1, a key-value pair at
position 2, and a string at position 3. But we may also say that it has a string
"value" accessible by key "key".

At this point the only question remaining is how do you store a composition
inside another one. You do it with parentheses (the normal, round brackets, `(`
and `)`):
```
1 "second" (12 = 21 "something") "hello" = "hello"
```

This **composition** contains 4 elements: the one at index 0 is a number, the
next one is a string, the next one is itself a **composition**,
`12 = 21 "something"`, and the last one is a key-value pair.

## Use cases

You may say that `1 "second" (12 = 21 "something") "hello" = "hello"` is not
very easy to read. That's because it's nonsense. So let's look at some more
meaningful examples.

First of all, you might have a **snack** that is basically a dictionary:
```
"name" = "John"
"age" = 100
"greeting" = "Hello, nice to meet you!"
```

You might want to have a list of such dictionaries:
```
(
    "name" = "John"
    "age" = 100
    "greeting" = "Hello, nice to meet you!"
)
(
    "name" = "Bob"
    "age" = 200
    "greeting" = "Hey, I'm Bob!"
)
```

Due to the free nature of a **composition** you might throw in some scalars
in-between the dictionaries, maybe to mark their "type" of some sort:
```
"person"
(
    "name" = "John"
    "age" = 100
    "greeting" = "Hello, nice to meet you!"
)

"cat"
(
    "name" = "Hugo"
    "age" = 10
    "color" = "tabby"
)
```

You might as well get rid of the parentheses:
```
"person"
  "name" = "John"
  "age" = 100
  "greeting" = "Hello, nice to meet you!"

"cat"
  "name" = "Hugo"
  "age" = 10
  "color" = "tabby"
```

If you combine a bunch of scalars and key-value pairs, you have a convenient way
to describe a function call in a language where key-value argument passing
exists. Like Python's `open()`:
```
"my_file.txt" "r" "encoding"="utf-8"
```

May as well add the name of the function as well:
```
"open"("my_file.txt" "r" "encoding"="utf-8")
```
