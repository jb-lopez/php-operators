--TEST--
Bitwise or "|" operator overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(8);
var_dump($a | 3);
var_dump($a | CONST_TEST);

--EXPECT--
int(11)
int(10)
