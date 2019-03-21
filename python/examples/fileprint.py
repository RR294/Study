
try:
    filename = input("Enter file name : ")
    fileh = open(filename)
    for line in fileh:
        line.strip()
        print(line.upper())
except:
    print("Can't open file :", filename)