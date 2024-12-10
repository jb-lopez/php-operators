--TEST--
Bitwise and "&" operator overloading
--EXTENSIONS--
operator
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	public function __bw_and($val) {
		return $this->value & $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(15);
var_dump($a & 3);
var_dump($a & CONST_TEST);

--EXPECT--
int(3)
int(10)
