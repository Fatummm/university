import sys
sys.set_int_max_str_digits(50000)
a = 3**(100000**100)
print(sys.getsizeof(a))
