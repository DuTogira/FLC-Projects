def main():
    tempC = int(0)
    tempF = float(0)
    tab = ("                ")
    tab2 = ("               ")
    tab3 = ("       ")
    displayModule(tab3)
    tempChanger(tempC, tempF, tab, tab2)

#
def displayModule(tab3):
    print("Celsius", tab3, "Fahrenheit")
    print("--------------------------")
#
def tempChanger(tempC, tempF, tab, tab2):
    maxTemp = int(20)
    while tempC <= maxTemp:
        tempF = tempC * 9/5 + 32
        if tempC < 10:
            print(tempC, tab, tempF)
        else:
            print(tempC, tab2, tempF)
        tempC = tempC + 1
    return tempC
    return tempF
#
main()
