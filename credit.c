#include <stdio.h>

#include <cs50.h>

#include <math.h>

int main(void)
{
    long card_num, card_start_num = 0;
    int part_a_digit, part_b_digit, card_num_length = 0, other_sum = 0, checksum = 0;;
    bool is_visa_card, is_amex_card, is_mastercard;

    card_num = get_long("Number: ");
    //  while there are numbers on the card
    while (card_num != 0)
    {
        // number modulo divided by 10 returns its last digit.
        part_a_digit = card_num % 10;

        //Separete the other digits by each second last 2
        if (card_num_length % 2 != 0)
        {
            //Multiply the other digit by two
            part_b_digit = part_a_digit * 2;

            // Now let’s add those products’ digits (not the products themselves) means 12 is treat as 1, 2
            //If the part_b_digit is 2 digits then sum the digits : 12 is 2 digit so become 1+2 =3
            other_sum += (part_b_digit % 100 == 0) ? part_b_digit :
                         part_b_digit % 10 + part_b_digit / 10;
        }
        else
        {
            //Sum of the digits that weren’t multiplied by 2
            checksum += part_a_digit;
        }
        //Get the card first 2number
        // because long data type treat 0.4 as 0 so when card_num = 40 and divided 100 become 0 so is true
        if (card_num / 100 == 0 && card_start_num == 0)
        {
            card_start_num = card_num;
        }

        // after finish 1 round remove the last digit from the card number by divided 10
        // so the card number will become more and more shorter each round
        card_num = card_num / 10;
        //  then increment the count as the length of card number
        card_num_length++;
    }

    // if last digit in that sum : (20) then checksum is a 0
    checksum = (checksum + other_sum) % 10;

    // Check match the condition for each card
    // visa card number is 13 or 16
    is_visa_card = card_num_length == 13 || card_num_length == 16;

    // amex card number starting with 34 and 37
    is_amex_card = card_start_num == 34 || card_start_num == 37;

    // MasterCard numbers start with 51, 52, 53, 54, or 55
    is_mastercard = card_start_num == 51 || card_start_num == 52 || card_start_num == 53 || card_start_num == 54
                    || card_start_num == 55;

    // if the checksum is 0 and
    // amex card number 15
    if (checksum == 0 && card_num_length == 15 && is_amex_card)
    {
        printf("AMEX\n");
    }
    // visa card starting with 4
    else if (checksum == 0 && card_start_num / 10 == 4 && is_visa_card)
    {
        printf("VISA\n");
    }
    // master card number 16
    else if (checksum == 0 && card_num_length == 16 && is_mastercard)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
