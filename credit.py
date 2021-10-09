def main():
    card = card_input()
    check = checksum(card)
    validate(card, check)


def card_input():
    while True:
        card_number = input("Card Number: ")
        if card_number.isnumeric():
            break

    return card_number


def checksum(card_number):
    even_sum = 0
    odd_sum = 0
    card_number = reversed([int(digit) for digit in card_number])
    for i, digit in enumerate(card_number):
        if (i + 1) % 2 == 0:
            odd_digit = digit * 2
            if odd_digit > 9:
                odd_sum += int(odd_digit / 10) + odd_digit % 10
            else:
                odd_sum += odd_digit
        else:
            even_sum += digit
    result = even_sum + odd_sum
    return result


def validate(card_number, checksum):
    # get the first 2 digit
    card_prefix = int(card_number[0:2])
    # get the length of card
    length = len(card_number)
    # check the last digit by % 10
    last_digit = checksum % 10

    if last_digit == 0:
        if card_prefix in [34, 37] and length == 15:
            print("AMEX")
        elif (card_prefix in range(51, 56)) and length == 16:
            print("MASTERCARD")
        elif (int(card_number[0]) == 4) and length in [13, 16]:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()
