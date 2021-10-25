A `snack` file always contains a single element of any type. It may be just a
scalar:
```
123
```
(that's the whole file!)

You can always identify the type of a token by just looking at it. `12` is
always an integer, and `12.0` is always a non-integer number. If you want to
make it a string, you have to do it explicitly by quoting, `"12.0"`.

Examples of `snack` files:

```
10
```

```
1 2.0 3 "4" 5 string_value "another string value"
```

```
key = value
key2 = 15
```
