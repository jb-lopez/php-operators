--TEST--
Division assignment operator "/=" overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(100);
var_dump($a /= 2);
var_dump($a /= CONST_TEST);

--EXPECT--
int(50)
int(5)
