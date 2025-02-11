<?php
/** @noinspection MagicMethodsValidityInspection */

class OperatorOverloading
{
    public mixed $value;

    public function __add(mixed $val): mixed
    {
        return $this->value + $val;
    }

    public function __assign_add(mixed $val): mixed
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

    public function __assign_bw_and(mixed $val): mixed
    {
        return $this->value &= $val;
    }

    public function __bw_or(mixed $val): int
    {
        return $this->value | $val;
    }

    public function __assign_bw_or(mixed $val): mixed
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

    public function __assign_concat(mixed $val): string
    {
        return $this->value .= $val;
    }

    public function __div(mixed $val): int|float
    {
        return $this->value / $val;
    }

    public function __assign_div(mixed $val): mixed
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

    public function __assign_mod(mixed $val): mixed
    {
        return $this->value %= $val;
    }

    public function __mul(mixed $val): int|float
    {
        return $this->value * $val;
    }

    public function __assign_mul(mixed $val): mixed
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

    public function __assign_pow(mixed $val): mixed
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

    public function __assign_sl(mixed $val): mixed
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

    public function __assign_sr(mixed $val): mixed
    {
        return $this->value >>= $val;
    }

    public function __sub(mixed $val): mixed
    {
        return $this->value - $val;
    }

    public function __assign_sub(mixed $val): mixed
    {
        return $this->value -= $val;
    }

    public function __construct(mixed $init)
    {
        $this->value = $init;
    }
}
