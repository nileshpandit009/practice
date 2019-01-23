my_list = input("Enter numbers separated by spaces\n").split(" ")

try:
    my_list = [int(x) for x in my_list]
    print("Max number is %f" % max(my_list))
except ValueError:
    print("Not all items are numbers")
