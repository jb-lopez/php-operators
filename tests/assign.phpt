--TEST--
Assignment operator "=" overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(1);
var_dump($a = 2);
var_dump(is_object($a));
var_dump($a = CONST_TEST);
var_dump(is_object($a));

--EXPECT--
int(2)
bool(true)
int(10)
bool(true)
