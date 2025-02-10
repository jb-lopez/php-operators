--TEST--
Pre-inc operator "++$a" overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(15);
var_dump($a->value);
var_dump(++$a);
var_dump($a->value);

--EXPECT--
int(15)
int(16)
int(16)
