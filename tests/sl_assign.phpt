--TEST--
Shift left assignment operator "<<=" overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 2;

$a = new OperatorOverloading(1);
var_dump($a <<= 1);
var_dump($a <<= CONST_TEST);

--EXPECT--
int(2)
int(8)
