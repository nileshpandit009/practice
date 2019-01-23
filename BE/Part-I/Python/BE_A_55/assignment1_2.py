my_list = input("Enter numbers separated by spaces").split(" ")
product = 1
for num in my_list:
    try:
        product *= float(num)
    except ValueError:
        print("List contains non-numeric values\n")
        exit(-1)
print(product)
