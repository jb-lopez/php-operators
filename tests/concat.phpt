--TEST--
Concat "." operator overloading
--EXTENSIONS--
operators
--FILE--
<?php

const CONST_TEST = "Nurse!";

class foo {
	private $value;

	public function __concat($val) {
		return $this->value . $val;
	}

	public function __construct($init) {
		$this->value = $init;
	}
}

$a = new foo("Hello ");
var_dump($a . "World!");
var_dump($a . CONST_TEST);

--EXPECT--
string(12) "Hello World!"
string(12) "Hello Nurse!"
