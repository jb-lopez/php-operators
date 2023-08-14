# PHP Operator Overloading

This extension provides operator overloading for PHP 8.

## Regular Operators

These operators are the ones that make the most sense to overload. They are
assignment, unary, binary, and comparison operators.

| Opcode Constant            | Opcode | Operator | Implemented |
|----------------------------|--------|----------|-------------|
| `ZEND_ADD`                 | `1`    | `+`      | Yes         |
| `ZEND_SUB`                 | `2`    | `-`      | Yes         |
| `ZEND_MUL`                 | `3`    | `*`      | Yes         |
| `ZEND_DIV`                 | `4`    | `/`      | Yes         |
| `ZEND_MOD`                 | `5`    | `%`      | Yes         |
| `ZEND_SL`                  | `6`    | `<<`     | Yes         |
| `ZEND_SR`                  | `7`    | `>>`     | Yes         |
| `ZEND_CONCAT`              | `8`    | `.`      | Yes         |
| `ZEND_BW_OR`               | `9`    | `\|`     | Yes         |
| `ZEND_BW_AND`              | `10`   | `&`      | Yes         |
| `ZEND_BW_XOR`              | `11`   | `^`      | Yes         |
| `ZEND_POW`                 | `12`   | `**`     | Yes         |
| `ZEND_BW_NOT`              | `13`   | `~`      | No          |
| `ZEND_BOOL_NOT`            | `14`   | `!`      | No          |
| `ZEND_BOOL_XOR`            | `15`   | `xor`    | No          |
| `ZEND_IS_IDENTICAL`        | `16`   | `===`    | Yes         |
| `ZEND_IS_NOT_IDENTICAL`    | `17`   | `!==`    | Yes         |
| `ZEND_IS_EQUAL`            | `18`   | `==`     | Yes         |
| `ZEND_IS_NOT_EQUAL`        | `19`   | `!=`     | Yes         |
| `ZEND_IS_SMALLER`          | `20`   | `<`      | No          |
| `ZEND_IS_SMALLER_OR_EQUAL` | `21`   | `<=`     | No          |
| `ZEND_ASSIGN`              | `22`   | `=`      | Yes         |
| `ZEND_PRE_INC`             | `34`   | `++$a`   | No          |
| `ZEND_PRE_DEC`             | `35`   | `--$a`   | No          |
| `ZEND_POST_INC`            | `36`   | `$a++`   | No          |
| `ZEND_POST_DEC`            | `37`   | `$a--`   | No          |
| `ZEND_COALESCE`            | `169`  | `??`     | No          |
| `ZEND_SPACESHIP`           | `170`  | `<=>`    | No          |

## Assignment Operators

There are a few assignment operators that are overloaded. These are an operator
and an assignment operator combined. For example, `+=` is an addition assignment
operator.

| Operator | Implemented |
|----------|-------------|
| `+=`     | Yes         |
| `-=`     | Yes         |
| `*=`     | Yes         |
| `/=`     | Yes         |
| `%=`     | Yes         |
| `<<=`    | Yes         |
| `>>=`    | Yes         |
| `.=`     | Yes         |
| `\|=`    | Yes         |
| `&=`     | Yes         |
| `^=`     | Yes         |
| `**=`    | Yes         |

## Other Opcodes

There are a number of opcodes, more than 200 in total. Many of them don't make
sense to overload. The full opcode list can be found in the `php-src` repo
[here](https://github.com/php/php-src/blob/master/Zend/zend_vm_opcodes.h#L86).
