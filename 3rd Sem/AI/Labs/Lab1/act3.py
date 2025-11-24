isPrime = True
n = int(input("Enter a number to check if it is prime or not: "))
i = 2

while i < n:
    if n % i == 0:
        isPrime = False
        break
    i += 1

if isPrime:
    print("Prime")
else:
    print("Not Prime")

   