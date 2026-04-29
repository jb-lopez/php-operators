--TEST--
Assignment Operator Testing
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
// Constants take different code paths than scalar values, so we must test both.
const CONST_TEST = 10;
const CONST_TEXT = "Globe!";

$a = new OperatorOverloading(1);

// Test Assignment `$a::__assign($b)`
echo "Test Assignment\n";
var_dump($a = 2);
var_dump(is_object($a));
var_dump($a = CONST_TEST);
var_dump(is_object($a));

// The next series of tests are for combinatorial assignment operators.

// Test Addition Assignment `$a::__assign_add($b)`
echo "Test Addition Assignment\n";
$a->value = 1;
var_dump($a += 2);
var_dump(is_object($a));
var_dump($a += CONST_TEST);
var_dump(is_object($a));

// Test Subtraction Assignment `$a::__assign_sub($b)`
echo "Test Subtraction Assignment\n";
$a->value = 12;
var_dump($a -= 4);
var_dump(is_object($a));
var_dump($a -= CONST_TEST);
var_dump(is_object($a));

// Test Multiplication Assignment `$a::__assign_mul($b)`
echo "Test Multiplication Assignment\n";
$a->value = 5;
var_dump($a *= 2);
var_dump(is_object($a));
var_dump($a *= CONST_TEST);
var_dump(is_object($a));

// Test Division Assignment `$a::__assign_div($b)`
echo "Test Division Assignment\n";
$a->value = 100;
var_dump($a /= 2);
var_dump(is_object($a));
var_dump($a /= CONST_TEST);
var_dump(is_object($a));

// Test Modulo Assignment `$a::__assign_mod($b)`
echo "Test Modulo Assignment\n";
$a->value = 5;
var_dump($a %= 2);
var_dump(is_object($a));
var_dump($a %= CONST_TEST);
var_dump(is_object($a));

// Test Exponent Assignment `$a::__assign_pow($b)`
echo "Test Exponent Assignment\n";
$a->value = 5;
var_dump($a **= 2);
var_dump(is_object($a));
var_dump($a **= CONST_TEST);
var_dump(is_object($a));

// Test Bitwise And Assignment `$a::__assign_bw_and($b)`
echo "Test Bitwise And Assignment\n";
$a->value = 15;
var_dump($a &= 3);
var_dump(is_object($a));
var_dump($a &= CONST_TEST);
var_dump(is_object($a));

// Test Bitwise Or Assignment `$a::__assign_bw_or($b)`
echo "Test Bitwise Or Assignment\n";
$a->value = 8;
var_dump($a |= 3);
var_dump(is_object($a));
var_dump($a |= CONST_TEST);
var_dump(is_object($a));

// Test Bitwise Xor Assignment `$a::__assign_bw_xor($b)`
echo "Test Bitwise Xor Assignment\n";
$a->value = 8;
var_dump($a ^ 3);
var_dump(is_object($a));
var_dump($a ^ CONST_TEST);
var_dump(is_object($a));

// Test Bitwise Shift Left Assignment `$a::__assign_sl($b)`
echo "Test Bitwise Shift Left Assignment\n";
$a->value = 1;
var_dump($a <<= 1);
var_dump(is_object($a));
var_dump($a <<= CONST_TEST);
var_dump(is_object($a));

// Test Bitwise Shift Right Assignment `$a::__assign_sr($b)`
echo "Test Bitwise Shift Right Assignment\n";
$a->value = 2048;
var_dump($a >>= 1);
var_dump(is_object($a));
var_dump($a >>= CONST_TEST);
var_dump(is_object($a));

// Test Concatenation Assignment `$a::__assign_concat($b)`
echo "Test Concatenation Assignment\n";
$a->value = "Hello ";
var_dump($a .= "World!");
var_dump(is_object($a));
$a->value = "Hello ";
var_dump($a .= CONST_TEXT);
var_dump(is_object($a));

--EXPECT--
Test Assignment
int(2)
bool(true)
int(10)
bool(true)
Test Addition Assignment
int(3)
bool(true)
int(13)
bool(true)
Test Subtraction Assignment
int(8)
bool(true)
int(-2)
bool(true)
Test Multiplication Assignment
int(10)
bool(true)
int(100)
bool(true)
Test Division Assignment
int(50)
bool(true)
int(5)
bool(true)
Test Modulo Assignment
int(1)
bool(true)
int(1)
bool(true)
Test Exponent Assignment
int(25)
bool(true)
int(95367431640625)
bool(true)
Test Bitwise And Assignment
int(3)
bool(true)
int(2)
bool(true)
Test Bitwise Or Assignment
int(11)
bool(true)
int(11)
bool(true)
Test Bitwise Xor Assignment
int(11)
bool(true)
int(2)
bool(true)
Test Bitwise Shift Left Assignment
int(2)
bool(true)
int(2048)
bool(true)
Test Bitwise Shift Right Assignment
int(1024)
bool(true)
int(1)
bool(true)
Test Concatenation Assignment
string(12) "Hello World!"
bool(true)
string(12) "Hello Globe!"
bool(true)
