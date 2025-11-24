import random

min = 1
max = 9
randomNum = random.randint(min, max)

Running = True

while Running:
    guess = int(input("Enter your guess: "))
    
    if guess < randomNum:
        print("Too Low")
    elif guess > randomNum:
        print("Too High")
    else:
        print("Correct! The number was", randomNum)
        Running = False





