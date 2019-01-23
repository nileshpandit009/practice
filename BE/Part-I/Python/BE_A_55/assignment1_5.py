def getInput():
    temp_list = input("Enter Strings separated by spaces:\n").split(" ")
    return temp_list

def isFirstLastCharEqual(string):
    if (string[0] == string[len(string) - 1]):
        return True
    else:
        return False

def main():
    counter = 0;
    strings = getInput()
    for string in strings:
        if (len(string) >= 2):
            if (isFirstLastCharEqual(string)):
                counter += 1
        else:
            print("String is too short")
    print("%d strings have First and Last character same" % counter)

if __name__ == "__main__":
    main()
