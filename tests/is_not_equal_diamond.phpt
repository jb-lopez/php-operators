--TEST--
Is not equal operator "<>" overloading
--EXTENSIONS--
operator
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	public function __is_not_equal($val) {
		return $this->value != $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(10);
var_dump($a <> 2);
var_dump($a <> CONST_TEST);

--EXPECT--
bool(true)
bool(false)
