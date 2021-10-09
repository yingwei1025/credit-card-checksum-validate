# credit-card-checksum-validate

### Credit card checksum validate

The program written in both version of C and python which validate the credit cards by using  an algorithm invented by Hans Peter Luhn of IBM. This program will check is this credit card valid and what is the type

CS50 Pset

# Luhn’s Algorithm

1) Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2) Add the sum to the sum of the digits that weren’t multiplied by 2.
3) If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid

Lets assume credit card of 4003600000000014

Starting with the number’s second-to-last digit from the right hand side, so is 
```
1 ,  0 , 0 , 0, 0,  6,  0, 4
```

Let’s multiply each of the underlined digits by 2:
```
1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2
```
That gives us:
```
2 + 0 + 0 + 0 + 0 + 12 + 0 + 8
```
Now let’s add those products’ digits (i.e., not the products themselves) together:
```
2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
```
Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):
```
13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
```
So in the last digit in that sum (20) is a 0, so this card is valid.

# Run the program in C
```
~/ $ ./credit
Number: 4003600000000014
VISA

~/ $ ./credit
Number: 378282246310005
AMEX

~/ $ ./credit
Number: 5555555555554444
MASTERCARD

~/ $ ./credit
Number: 369421438430814
INVALID
```

# Run the program in python
```
~/ $ python credit.py
Number: 4003600000000014
VISA

~/ $ python credit.py
Number: 378282246310005
AMEX

~/ $ python credit.py
Number: 5555555555554444
MASTERCARD

~/ $ python credit.py
Number: 369421438430814
INVALID
```
