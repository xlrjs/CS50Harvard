from cs50 import get_int

while True:

    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(1, n + 1):

    for j in range(n - i):
        print(" ", end="")

    for k in range(i):
        print("#", end="")

    print("  ", end="")

    for l in range(i):
        print("#", end="")
    print("")