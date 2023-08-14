--TEST--
Modulo operator "%" overloading
--EXTENSIONS--
operators
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	public function __mod($val) {
		return $this->value % $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(5);
var_dump($a % 2);
var_dump($a % CONST_TEST);

--EXPECT--
int(1)
int(5)
