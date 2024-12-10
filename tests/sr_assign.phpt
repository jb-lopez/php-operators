--TEST--
Shift right assignment operator ">>=" overloading
--EXTENSIONS--
operator
--FILE--
<?php

const CONST_TEST = 2;

class foo {
	private $value;

	public function __sr_assign($val) {
		return $this->value >>= $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(64);
var_dump($a >>= 1);
var_dump($a >>= CONST_TEST);

--EXPECT--
int(32)
int(8)
