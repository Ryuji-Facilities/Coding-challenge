import random

passlen = int(input("Enter the Length of the Password >> "))
char = "abcdefghijklmnopqrstuvwxyz01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()?"
passw =  "".join(random.sample(char ,passlen))
print (passw)
