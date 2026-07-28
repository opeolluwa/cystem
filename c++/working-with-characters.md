## Working with Unicode Characters

ASCII is generally adequate for national language character sets that use Latin characters. However, if you
want to work with characters for multiple languages simultaneously or if you want to handle character sets
for many non-English languages, 256 character codes doesn’t go nearly far enough, and Unicode is the
answer. You can refer to Chapter 1 for a brief introduction on Unicode and character encodings.
Type wchar_t is a fundamental type that can store all members of the largest extended character set
that’s supported by an implementation. The type name derives from wide characters because the character
is “wider” than the usual single-byte character. By contrast, type char is referred to as “narrow” because of
the limited range of character codes that are available.
You define wide-character literals in a similar way to literals of type char, but you prefix them with L.
Here’s an example:
wchar_t wch {L'Z'};
This defines wch as type wchar_t and initializes it to the wide-character representation for Z.
Your keyboard may not have keys for representing other national language characters, but you can still
create them using hexadecimal notation. Here’s an example:
wchar_t wch {L'\x0438'}; // Cyrillic и
The value between the single quotes is an escape sequence that specifies the hexadecimal
representation of the character code. The backslash indicates the start of the escape sequence, and x or X
after the backslash signifies that the code is hexadecimal.
Type wchar_t does not handle international character sets very well. It’s much better to use type
char16_t, which stores characters encoded as UTF-16, or char32_t, which stores UTF-32 encoded
characters. Here’s an example of defining a variable of type char16_t:
char16_t letter {u'B'}; char16_t cyr {u'\x0438'}; // Initialized with UTF-16 code for B
// Initialized with UTF-16 code for cyrillic и
The lowercase u prefix to the literals indicates that they are UTF-16. You prefix UTF-32 literals with
uppercase U. Here’s an example:
char32_t letter {U'B'}; char32_t cyr {U'\x044f'}; // Initialized with UTF-32 code for B
// Initialized with UTF-32 code for cyrillic я
Of course, if your editor and compiler have the capability to accept and display the characters, you can
define cyr like this:
char32_t cyr {U'я'};
The Standard Library provides standard input and output streams wcin and wcout for reading and
writing characters of type wchar_t, but there is no provision with the library for handling char16_t and
char32_t character data.
