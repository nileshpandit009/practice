flag = False
num = int(input("Enter a number to check whether prime or not\n"))
for i in range(2, int(((num/2) + 1))):
    if ((num % i) == 0):
        flag = True
if (not flag):
    print ("Number is Prime")
else:
    print ("Number is not Prime")
