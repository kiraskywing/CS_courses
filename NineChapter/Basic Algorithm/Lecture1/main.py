#------------------------------------------------
a = 10
b = 20
print(a + b)

print("Hello world")

#------------------------------------------------
year = 1900
is_leap_year = year % 400 == 0 or year % 4 == 0 and year % 100 != 0
print(is_leap_year)

#------------------------------------------------

number = 123
print(number % 10 * 100 + int(number / 10) % 10 * 10 + int(number / 100))
