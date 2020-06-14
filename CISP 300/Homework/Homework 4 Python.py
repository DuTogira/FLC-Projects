#This program should convert any real number from 1 to 10 into romen numerals
def main():
    userNumber = float(input("Please enter a number between 1 and 10 which you wish to have converted to roman numerals."))
    romanConverter(userNumber)
#
#This module runs through two other modules, one of which will verify that
#the number entered by the user qualifies as a real number, and then converts
#the number into roman numeral form
def romanConverter(userNumber):
    numChecker(userNumber)
    whatIf(userNumber)
    return userNumber
    return romanNumber
#
#This module will display the results of our previous modules conversions
def romanDisplay(userNumber, romanNumber):
    print(userNumber, "will look like", romanNumber, "as a roman numeral.")
#
#This module will verify that the number entered by the user is able to be
#converted into a roman numeral by the program
def numChecker(userNumber):     
    while userNumber<1 or userNumber>10:
        userNumber = float(input("Error: Please enter a number between 1 and 10."))
    return userNumber
#
#This module converts the number to a roman numeral using a series of
#if statements
def whatIf(userNumber):
    if userNumber == 1:
        romanNumber = "I"
    elif userNumber == 2:
        romanNumber = "II"
    elif userNumber == 3:
        romanNumber = "III"
    elif userNumber == 4:
        romanNumber = "IV"
    elif userNumber == 5:
        romanNumber = "V"
    elif userNumber == 6:
        romanNumber = "VI"
    elif userNumber == 7:
        romanNumber = "VII"
    elif userNumber == 8:
        romanNumber = "VIII"
    elif userNumber == 9:
        romanNumber = "IX"
    elif userNumber == 10:
        romanNumber = "X"
    romanDisplay(userNumber, romanNumber)
    return userNumber
    return romanNumber
#
#And last but not least we must never forget to call the main module
main()
                                        
                                    
