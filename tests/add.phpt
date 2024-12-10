--TEST--
Addition operator "+" overloading
--EXTENSIONS--
operator
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	public function __add($val) {
		return $this->value + $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(1);
var_dump($a + 2);
var_dump($a + CONST_TEST);

--EXPECT--
int(3)
int(11)
