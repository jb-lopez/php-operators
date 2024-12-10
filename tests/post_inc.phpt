--TEST--
Post-inc operator "$a++" overloading
--EXTENSIONS--
operator
--FILE--
<?php

const CONST_TEST = 10;

class foo {
	public $value;

	public function __post_inc() {
		return $this->value++;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo(15);
var_dump($a->value);
var_dump($a++);
var_dump($a->value);

--EXPECT--
int(15)
int(15)
int(16)
