my_list = input("Enter numbers separated by spaces").split(" ");
total = 0;
for num in my_list:
    try:
        total += int(num)
    except ValueError:
        print("List contains non-numeric values\n")
        exit(-1)
print(total)
