total = 0
n = int(input("Enter an integer to calculate sum (or enter 0 to exit): "))

while n != 0:
    total = total + n
    n = int(input("Enter another integer (or 0 to exit): "))

print("Sum is =", total)
