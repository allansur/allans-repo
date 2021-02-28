#Allan Sur 821444631
#Professor Healey
#CS320
#6/1/20
import re

def print_menu():
    print("\n****MENU****")
    print("1. FANBOY Detector")
    print("2. Exit Program")


def fanboy_detector():
    sentence = input("Please enter a sentence.\n")
    pattern = re.split(r",\s(and|for|not|but|or|yet|so)", sentence)
    count = 1
    for x in range(0,len(pattern), 2):
        print("%s." % (count) + pattern[x])
        count += 1

    print("\n")
        
loop = True
while loop:
    print_menu()
    choice = input("\nEnter your choice\n")
    if choice == "1":
        print("**FANBOY DETECTOR**")
        fanboy_detector()
    elif choice == "2":
        print("Now exiting the program")
        loop = False




 