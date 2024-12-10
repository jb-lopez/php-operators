--TEST--
Subtraction assignment operator "-=" overloading
--EXTENSIONS--
operator
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	private $value;

	public function __sub_assign($val) {
        return $this->value -= $val;
    }

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(12);
var_dump($a -= 4);

--EXPECT--
int(8)
