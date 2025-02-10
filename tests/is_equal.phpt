--TEST--
Is equal operator "==" overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(10);
var_dump($a == 2);
var_dump($a == CONST_TEST);

--EXPECT--
bool(false)
bool(true)
