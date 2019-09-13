import cs50

height = input("Enter height: ")

while (height < 0 or height > 24):
    for i in range(height):
        print(" "*(height-i) + "#"*(i+1))

