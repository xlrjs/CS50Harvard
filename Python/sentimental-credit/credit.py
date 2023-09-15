from cs50 import get_int

""" This solution is based on the same way as mario.c
we have to keep in mind that this is not the most efficient solution
at this point at the course we have been seen different data structures
we have seen arrays, linked lists and more. As we saw in the course and
particularly week 6, the solution for this problem can be addressed by
using touples or list indexes as this will be the most efficient
way to do it in python; for better solution, we will do another implementation"""

n = get_int("Number: ") #User puts the number card information
if n > 4000000000000 and n < 5600000000000000:
    value_comp = 10000000000000000000

    g_sum = 0 #general sum
    digit = 0 #variable for extracting digit
    internal_sum = 0

    #operations for the multiplied digits
    i = 100
    while i < value_comp: #loop going through all the digits
        digit = (n % i) / (i / 10) # variable to holds the digit alone and extract it
        #print(f"digit {digit}")

        digit_mult = int(digit) * 2 # var to analize if the multiplication exceeds 9
        #testing print
        #print(f"tp digit mult {digit_mult}")

        #testing print
        #print(f"tp suma antes {internal_sum}")

        if digit_mult > 9:
            sum_mult = 0

            j = 10

            while j <= 100:
                dual = int(digit_mult % j) / (j / 10)
                sum_mult = sum_mult + int(dual)
                #print(f" testing print suma multiplo {sum_mult}")
                j = j * 10
            internal_sum = internal_sum + sum_mult

        else:
            internal_sum = internal_sum + digit_mult
        i = i * 100
    #print(f"after double digit sum {internal_sum}")

    #now operations for the non multiplied digits

    non_mult = 0
    sum_non = 0

    k = 10
    while k < value_comp:
        non_mult = (n % k) / (k / 10)
        #print(f"tp non mult {non_mult}")
        sum_non = sum_non + int(non_mult)
        #print(f"tp sum here {sum_non}")
        k = k * 100

    g_sum = int(internal_sum) + int(sum_non)

    checksum = int(g_sum)
    #print(f"tp checksum {checksum}")

    if int(checksum % 10) == 0:
        if (n > 340000000000000 and n < 350000000000000) or (n > 370000000000000 and n < 380000000000000):
            print("AMEX")
        elif n > 5100000000000000 and n < 5600000000000000:
            print("MASTERCARD")
        elif n > 400000000000 and n < 5000000000000 or n > 400000000000000 and n < 5000000000000000:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")
else:
    print("INVALID")
