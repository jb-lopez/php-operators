--TEST--
Pre-dec operator "--$a" overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = 10;

$a = new OperatorOverloading(16);
var_dump($a->value);
var_dump(--$a);
var_dump($a->value);

--EXPECT--
int(16)
int(15)
int(15)
