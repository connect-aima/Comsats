marks = int(input("Enter marks (1-100): "))

if marks < 50:
    grade = "F"
elif marks <= 60:
    grade = "E"
elif marks <= 70:
    grade = "D"
elif marks <= 80:
    grade = "C"
elif marks <= 90:
    grade = "B"
elif marks <= 100:
    grade = "A"
else:
    grade = "Invalid input"

print("Grade:", grade)
