<?php
/** @noinspection MagicMethodsValidityInspection */

class OperatorOverloading
{
    public mixed $value;

    public function __add(mixed $val): mixed
    {
        return $this->value + $val;
    }

    public function __add_assign(mixed $val): mixed
    {
        return $this->value += $val;
    }

    public function __assign(mixed $val): mixed
    {
        return $this->value = $val;
    }

    public function __bw_and(mixed $val): int
    {
        return $this->value & $val;
    }

    public function __bw_and_assign(mixed $val): mixed
    {
        return $this->value &= $val;
    }

    public function __bw_or(mixed $val): int
    {
        return $this->value | $val;
    }

    public function __bw_or_assign(mixed $val): mixed
    {
        return $this->value |= $val;
    }

    public function __bw_xor(mixed $val): int
    {
        return $this->value ^ $val;
    }

    public function __coalesce(): mixed
    {
        if (empty($this->value)) {
            return null;
        }

        return $this->value;
    }

    public function __concat(mixed $val): string
    {
        return $this->value . $val;
    }

    public function __concat_assign(mixed $val): string
    {
        return $this->value .= $val;
    }

    public function __div(mixed $val): int|float
    {
        return $this->value / $val;
    }

    public function __div_assign(mixed $val): mixed
    {
        return $this->value /= $val;
    }

    public function __is_equal(mixed $val): bool
    {
        return $this->value == $val;
    }

    public function __is_identical(mixed $val): bool
    {
        return $this->value === $val;
    }

    public function __is_not_equal(mixed $val): bool
    {
        return $this->value != $val;
    }

    public function __is_not_identical(mixed $val): bool
    {
        return $this->value !== $val;
    }

    public function __is_smaller(mixed $val): bool
    {
        return $this->value < $val;
    }

    public function __is_smaller_or_equal(mixed $val): bool
    {
        return $this->value <= $val;
    }

    public function __mod(mixed $val): int
    {
        return $this->value % $val;
    }

    public function __mod_assign(mixed $val): mixed
    {
        return $this->value %= $val;
    }

    public function __mul(mixed $val): int|float
    {
        return $this->value * $val;
    }

    public function __mul_assign(mixed $val): mixed
    {
        return $this->value *= $val;
    }

    public function __post_dec(): mixed
    {
        return $this->value--;
    }

    public function __post_inc(): mixed
    {
        return $this->value++;
    }

    public function __pow(mixed $val): mixed
    {
        return $this->value ** $val;
    }

    public function __pow_assign(mixed $val): mixed
    {
        return $this->value **= $val;
    }

    public function __pre_dec(): mixed
    {
        return --$this->value;
    }

    public function __pre_inc(): mixed
    {
        return ++$this->value;
    }

    public function __sl(mixed $val): int
    {
        return $this->value << $val;
    }

    public function __sl_assign(mixed $val): mixed
    {
        return $this->value <<= $val;
    }

    public function __spaceship(mixed $val): int
    {
        return $this->value <=> $val;
    }

    public function __sr(mixed $val): int
    {
        return $this->value >> $val;
    }

    public function __sr_assign(mixed $val): mixed
    {
        return $this->value >>= $val;
    }

    public function __sub(mixed $val): mixed
    {
        return $this->value - $val;
    }

    public function __sub_assign(mixed $val): mixed
    {
        return $this->value -= $val;
    }

    public function __construct(mixed $init)
    {
        $this->value = $init;
    }
}
