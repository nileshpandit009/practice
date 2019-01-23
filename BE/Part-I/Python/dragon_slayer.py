import random

player = 25
dragon = 100

while (player > 0 or dragon > 0):
    if (random.choice([1, 2]) == 1):
        dragon -= 25
    else:
        player -= 25

if (player == 0):
    print ("Dragon wins")
else:
    print ("You won!!!")
