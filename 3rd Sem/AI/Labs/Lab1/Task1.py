str = input("Enter a string you want to reverse: ")

reversed_str = ""   
for i in range(len(str) - 1, -1, -1): 
    reversed_str += str[i]

print("Reversed string is:", reversed_str)

