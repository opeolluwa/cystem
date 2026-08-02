# Classifying characters 
The `cctypes` header contains functions for classifying headers, a few ...
| operator | function
| --- | --- | 
| isalpha |  Tests whether c is an uppercase or lowercase letter (or any alphabetic character that is neither uppercase nor lowercase, should the locale’s alphabet contain such characters).| 
| isupper | Tests whether c is an uppercase letter, by default 'A' to 'Z'.| 
| islower | Tests whether c is a lowercase letter, by default 'a' to 'z'. |
| isdigit | Tests whether c is a digit, '0' to '9'.| 
| isxdigit |  Tests whether c is a hexadecimal digit, either '0' to '9', 'a' to 'f', or 'A' to 'F'.| 
| isalnum | Tests whether c is an alphanumeric character; same as isalpha(c) || isdigit(c). |
| isspace |  Tests whether c is whitespace, by default a space (' ('\r'), form feed ('\f'), or horizontal ('\t') or vertical tab ('\v'). ), newline ('\n'), carriage return | 
| isblank | Tests whether c is a space character used to separate words within a line of text. By default either a space (' ') or a horizontal tab ('\t').|
| ispunct | Tests whether c is a punctuation character. By default, this will be either a space or one of the following: _ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " |
| isprint | Tests whether c is a printable character, which includes uppercase or lowercase letters, digits, punctuation characters, and spaces.|
| iscntrl|  Tests whether c is a control character, which is the opposite of a printable character| 
| isgraph | Tests whether c has a graphical representation, which is true for any printable character other than a space |




It also contains procedures for converting headers 
eg tolower, toupper to convert to lower or upper case respectively