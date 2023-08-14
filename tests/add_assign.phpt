--TEST--
Addition assignment operator "+=" overloading
--EXTENSIONS--
operators
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	public function __add_assign($val) {
		return $this->value += $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(1);
var_dump($a += 2);
var_dump($a += CONST_TEST);

--EXPECT--
int(3)
int(13)
