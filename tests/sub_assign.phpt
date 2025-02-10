--TEST--
Subtraction assignment operator "-=" overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(12);
var_dump($a -= 4);

--EXPECT--
int(8)
