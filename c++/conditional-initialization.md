Initialization Statements
Consider the following code snippet:

```cpp
auto lower{ static_cast<char>(std::tolower(input)) };
if (lower >= 'a' && lower <= 'z') {
std::cout << "You've entered the letter '" << lower << '\'' << std::endl;
}
// ... more code that does not use lower
```

We convert some input character to a lowercase character lower and use the outcome first to check
whether the input was a letter and then, if so, to produce some output. For illustration’s sake, ignore the fact
that we could—should even—be using the portable std::isalpha() function here instead. You’ve learned
all about that in this chapter already. The key point that we want to make with this example is that the lower
variable is used only by the if statement and not anymore by any of the code that follows the snippet. In
general, it is considered good coding style to limit the scope of variables to the region in which they are used,
even if this means adding an extra scope as follows:

```cpp
{
auto lower{ static_cast<char>(std::tolower(input)) };
if (lower >= 'a' && lower <= 'z') {
std::cout << "You've entered the letter '" << lower << '\'' << std::endl;
}
}
// ... more code (lower does not exist here)
```

The result is that, for the rest of the code, it is as if the lower variable never existed. Patterns such as this
where an extra scope (and indentation) is introduced to bind local variables to if statements are relatively
common. They are common enough for C++17 to introduce a new, specialized syntax for it. The general
syntax is as follows:

`if (initialization; condition)`

same applies for switch 

`switch (initialization; condition)`