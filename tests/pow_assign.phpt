--TEST--
Power assignment operator "**=" overloading
--EXTENSIONS--
operators
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	public function __pow_assign($val) {
		return $this->value **= $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(5);
var_dump($a **= 2);
var_dump($a **= CONST_TEST);

--EXPECT--
int(25)
int(95367431640625)
