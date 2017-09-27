# KK-16-Lua-Interpreter
Small interpreter for programming language Lua

Interpreter is implemented in programming language C++ using tool- Bison/Flex.
To use it, you need to have Linux system, and installed Bison/Flex.
To install Bison- sudo apt-get install Bison
To install Flex- sudo apt-get install Flex
Compile program by calling make.

Lua interpreter supports limited amount of functions. It can declare
variables, and variables names can start with a letter or and underscore,
and continue with any amount of letters, underscores and digits.

All variables are double type. You can print variable with print(variable_name).
You can read variable value with variable_name = read() which reads from standard
input. Language also supports if-than statemens and while loops, and regular
arithmetic and logical operators. Every command in Lua can be ended with 
semicolon, but doesnt necessarly need to.
