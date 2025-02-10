--TEST--
Concat "." operator overloading
--EXTENSIONS--
operator
--FILE--
<?php

require_once __DIR__ . '/OperatorOverloading.inc';
const CONST_TEST = "Nurse!";

$a = new OperatorOverloading("Hello ");
var_dump($a . "World!");
var_dump($a . CONST_TEST);

--EXPECT--
string(12) "Hello World!"
string(12) "Hello Nurse!"
