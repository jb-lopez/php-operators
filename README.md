# PHP Operator Overloading

This extension provides operator overloading for PHP 8.

There is an extension for operator overloading in PHP 7,
[pecl-php-operator](https://github.com/php/pecl-php-operator), but it has been
broken since PHP 7.4. This extension is a rewrite of that extension, but for
PHP 8.

## Regular Operators

These operators are the ones that make the most sense to overload. They are
assignment, unary, binary, and comparison operators.

### [Arithmetic Operators](https://www.php.net/manual/en/language.operators.arithmetic.php)

| Opcode Constant | Operator Name  | Opcode | Operator   | Implemented | Function Call   |
|-----------------|----------------|-------:|------------|-------------|-----------------|
|                 | Identity       |        | `+$a`      | Maybe[^1]   |                 |
|                 | Negation       |        | `-$a`      | Maybe[^1]   |                 |
| `ZEND_ADD`      | Addition       |    `1` | `$a + $b`  | Yes         | `$a::__add($b)` |
| `ZEND_SUB`      | Subtraction    |    `2` | `$a - $b`  | Yes         | `$a::__sub($b)` |
| `ZEND_MUL`      | Multiplication |    `3` | `$a * $b`  | Yes         | `$a::__mul($b)` |
| `ZEND_DIV`      | Division       |    `4` | `$a / $b`  | Yes         | `$a::__div($b)` |
| `ZEND_MOD`      | Modulo         |    `5` | `$a % $b`  | Yes         | `$a::__mod($b)` |
| `ZEND_POW`      | Exponent       |   `12` | `$a ** $b` | Yes         | `$a::__pow($b)` |

### [Assignment Operators](https://www.php.net/manual/en/language.operators.assignment.php)

| Opcode Constant | Operator Name | Opcode | Operator    | Implemented | Function Call      |
|-----------------|---------------|-------:|-------------|-------------|--------------------|
| `ZEND_ASSIGN`   | Assignment    |   `22` | `$a = $b`   | Yes         | `$a::__assign($b)` |

### [Bitwise Operators](https://www.php.net/manual/en/language.operators.bitwise.php)

| Opcode Constant | Operator Name | Opcode | Operator    | Implemented | Function Call      |
|-----------------|---------------|-------:|-------------|-------------|--------------------|
| `ZEND_BW_AND`   | And           |   `10` | `$a & $b`   | Yes         | `$a::__bw_and($b)` |
| `ZEND_BW_OR`    | Or            |    `9` | `$a \| $b`  | Yes         | `$a::__bw_or($b)`  |
| `ZEND_BW_XOR`   | Xor           |   `11` | `$a ^ $b`   | Yes         | `$a::__bw_xor($b)` |
| `ZEND_BW_NOT`   | Not           |   `13` | `~$a`       | No          |                    |
| `ZEND_SL`       | Shift left    |    `6` | `$a << $b`  | Yes         | `$a::__sl($b)`     |
| `ZEND_SR`       | Shift right   |    `7` | `$a >> $b`  | Yes         | `$a::__sr($b)`     |

### [Comparison Operators](https://www.php.net/manual/en/language.operators.comparison.php)

| Opcode Constant            | Operator Name         | Opcode | Operator    | Implemented | Function Call                |
|----------------------------|-----------------------|-------:|-------------|-------------|------------------------------|
| `ZEND_IS_EQUAL`            | Equal                 |   `18` | `$a == $b`  | Yes         | `$a::__is_equal($b)`         |
| `ZEND_IS_IDENTICAL`        | Identical             |   `16` | `$a === $b` | Yes         | `$a::__is_identical($b)`     |
| `ZEND_IS_NOT_EQUAL`        | Not equal             |   `19` | `$a != $b`  | Yes         | `$a::__is_not_equal($b)`     |
| `ZEND_IS_NOT_EQUAL`        | Not equal             |   `19` | `$a <> $b`  | Yes         | `$a::__is_not_equal($b)`     |
| `ZEND_IS_NOT_IDENTICAL`    | Not identical         |   `17` | `$a !== $b` | Yes         | `$a::__is_not_identical($b)` |
| `ZEND_IS_SMALLER`          | Less than             |   `20` | `$a < $b`   | No          |                              |
|                            | Greater than          |        | `$a > $b`   | No          |                              |
| `ZEND_IS_SMALLER_OR_EQUAL` | Less than or equal    |   `21` | `$a <= $b`  | No          |                              |
|                            | Greater than or equal |        | `$a >= $b`  | No          |                              |
| `ZEND_SPACESHIP`           | Spaceship             |  `170` | `$a <=> $b` | No          |                              |
|                            | Ternary               |        | `$a ?: $b`  | No          |                              |
| `ZEND_COALESCE`            | Null coalescing       |  `169` | `$a ?? $b`  | No          |                              |

### [Incrementing/Decrementing Operators](https://www.php.net/manual/en/language.operators.increment.php)

| Opcode Constant | Operator Name  | Opcode | Operator | Implemented | Function Call |
|-----------------|----------------|-------:|----------|-------------|---------------|
| `ZEND_PRE_INC`  | Pre-increment  |   `34` | `++$a`   | No          |               |
| `ZEND_POST_INC` | Post-increment |   `36` | `$a++`   | No          |               |
| `ZEND_PRE_DEC`  | Pre-decrement  |   `35` | `--$a`   | No          |               |
| `ZEND_POST_DEC` | Post-decrement |   `37` | `$a--`   | No          |               |

### [Logical Operators](https://www.php.net/manual/en/language.operators.logical.php)

| Opcode Constant | Operator Name | Opcode | Operator     | Implemented | Function Call |
|-----------------|---------------|-------:|--------------|-------------|---------------|
|                 | And           |        | `$a and $b`  | Maybe[^1]   |               |
|                 | Or            |        | `$a or $b`   | Maybe[^1]   |               |
| `ZEND_BOOL_XOR` | Xor           |   `15` | `$a xor $b`  | No          |               |
| `ZEND_BOOL_NOT` | Not           |   `14` | `$a ! $b`    | No          |               |
|                 | And           |        | `$a && $b`   | Maybe[^1]   |               |
|                 | Or            |        | `$a \|\| $b` | Maybe[^1]   |               |

### [String Operators](https://www.php.net/manual/en/language.operators.string.php)

| Opcode Constant | Operator Name | Opcode | Operator  | Implemented | Function Call      |
|-----------------|---------------|-------:|-----------|-------------|--------------------|
| `ZEND_CONCAT`   | Concatenation |    `8` | `$a . $b` | Yes         | `$a::__concat($b)` |

## Combination Assignment Operators

There are a few assignment operators that are overloaded. These are an operator
and an assignment operator combined[^2]. For example, `+=` is an addition assignment
operator.

| Opcode Constant | Operator Name             | Opcode | Operator    | Implemented | Function Call             |
|-----------------|---------------------------|-------:|-------------|-------------|---------------------------|
|                 | Addition Assignment       |        | `$a += $b`  | Yes         | `$a::__add_assign($b)`    |
|                 | Subtraction Assignment    |        | `$a -= $b`  | Yes         | `$a::__sub_assign($b)`    |
|                 | Multiplication Assignment |        | `$a *= $b`  | Yes         | `$a::__mul_assign($b)`    |
|                 | Division Assignment       |        | `$a /= $b`  | Yes         | `$a::__div_assign($b)`    |
|                 | Modulo Assignment         |        | `$a %= $b`  | Yes         | `$a::__mod_assign($b)`    |
|                 | Exponent Assignment       |        | `$a **= $b` | Yes         | `$a::__pow_assign($b)`    |
|                 | And Assignment            |        | `$a &= $b`  | Yes         | `$a::__and_assign($b)`    |
|                 | Or Assignment             |        | `$a \|= $b` | Yes         | `$a::__or_assign($b)`     |
|                 | Xor Assignment            |        | `$a ^= $b`  | Yes         | `$a::__xor_assign($b)`    |
|                 | Shift left Assignment     |        | `$a <<= $b` | Yes         | `$a::__sl_assign($b)`     |
|                 | Shift right Assignment    |        | `$a >>= $b` | Yes         | `$a::__sr_assign($b)`     |
|                 | Coalesce Assignment       |        | `$a ??= $b` | No          |                           |
|                 | Concat Assignment         |        | `$a .= $b`  | Yes         | `$a::__concat_assign($b)` |

## Other Opcodes

There are a number of opcodes, more than 200 in total. Many of them don't make
sense to overload. The full opcode list can be found in the `php-src` repo
[here](https://github.com/php/php-src/blob/master/Zend/zend_vm_opcodes.h#L86).

[^1]: This might be the same as other opcodes, or maybe there is no opcode for
it, but I'm not sure. I haven't tested it yet.

[^2]: There isn't a separate opcode for `+=`, it's just `ZEND_ADD` as the
  `extra-details` within the `ZEND_ASSIGN_OP` opcode. Those separate opcodes were
  removed in PHP 7.4. This is one of the things that broke the original
  operator overloading extension.
