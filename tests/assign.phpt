--TEST--
Assignment operator "=" overloading
--EXTENSIONS--
operators
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	function __assign($val) {
		return $this->value = $val;
	}

	function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(1);
var_dump($a = 2);
var_dump(is_object($a));
var_dump($a = CONST_TEST);
var_dump(is_object($a));

--EXPECT--
int(2)
bool(true)
int(10)
bool(true)
