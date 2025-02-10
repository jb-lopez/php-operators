--TEST--
Bitwise and assignment "&=" operator overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(15);
var_dump($a &= 3);
var_dump($a &= CONST_TEST);

--EXPECT--
int(3)
int(2)
