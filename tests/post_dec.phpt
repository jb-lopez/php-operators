--TEST--
Post-dec operator "$a--" overloading
--EXTENSIONS--
operators
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	public $value;

	public function __post_dec() {
		return $this->value--;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(16);
var_dump($a->value);
var_dump($a--);
var_dump($a->value);

--EXPECT--
int(16)
int(16)
int(15)
