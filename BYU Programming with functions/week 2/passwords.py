#I always like to add, the ASCII art in the beggining,

def word_in_file(password, file, case_sensitive = False):
    # This function reads a file (specified by the filename parameter) 
    # in which each line of the file contains a single word. If the word passed 
    # in the word parameter matches a word in the file the function returns a true 
    # otherwise it returns a false. If the parameter case_sensitive is true a case
    # sensitive match is performed. If case_sensitive is false a case insensitive 
    # match is performed. The case_sensitive parameter should default to False
    
    try:
        with open(file, 'r', encoding='utf-8', errors='ignore') as f: #I use windows, so I added encoding and errors parameters to avoid issues with special characters
            if not case_sensitive:
                password = password.lower()

            for line in f:
                word = line.strip()
                if not case_sensitive:
                    word = word.lower()

                if password == word:
                    return True
    except FileNotFoundError:
        print(f"File {file} not found.")
    return False

def word_has_character(password, character_list):
    #This function loops through each character in the string passed in the 
    #word parameter to see if that character is in the list of characters 
    #passed in the character_list parameter. If any of the characters in 
    #the word are present in the character list return a true, If none of the 
    #characters in the word are in the character list return false
    for char in password:
        if char in character_list:
            return True
    return False

def word_complexity(password):
    # This function creates a numeric complexity value based on the types of 
    # characters the word parameter contains. One point of complexity is given 
    # for each type of character in the word. The function calls the word_has_character 
    # function for each of the 4 kinds of characters (LOWER, UPPER, DIGITS, SPECIAL). 
    # If the word has that kind of character a point is added to complexity rating. 
    # Since there are 4 kinds of characters the complexity rating will range from 0 to 4. 
    # (0 would be returned only if word contained no characters or only contains characters 
    # that are not in any of the lists.)
    
    LOWER=["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
    UPPER=["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
    DIGITS=["0","1","2","3","4","5","6","7","8","9"]
    SPECIAL=["!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "=", "+", "[", "]", "{", "}", "|", ";", ":", "'", "\"", ",", ".", "<", ">", "?", "/", "\\","`", "~"]

    complexity = 1
    if word_has_character(password, LOWER):
        complexity += 1
    if word_has_character(password, UPPER):
        complexity += 1
    if word_has_character(password, DIGITS):
        complexity += 1
    if word_has_character(password, SPECIAL):
        complexity += 1

    return complexity

def password_strength(password, min_length=10, strong_length=16):
    # This function checks length requirements, checks dictionary and known-passwords, 
    # calls word_complexity to calculate the word's complexity then determines the password's 
    # strength based on the user requirements. It should print the messages defined in the 
    # requirements and return the password's strength as a number from 0 to 5. The min_length 
    # parameter should have a default value of 10. 
    # The strong_length parameter should have a default value of 16


    if word_in_file(password, 'wordlist.txt', case_sensitive=False):
        print("Password is a dictionary word and is not secure.")
        return 0

    if word_in_file(password, 'toppasswords.txt', case_sensitive=True):
        print("Password is a commonly used password and is not secure.")
        return 0

    if len(password) < min_length:
        print("Password is too short and is not secure.")
        return 1

    complexity = word_complexity(password)

    if len(password) > 15:
        print("Password is long, length trumps complexity this is a good password.")
        return 5
    elif complexity == 5:
        print(f"Password is extremely strong. complexity score: {complexity}")
        return 5
    elif complexity == 4:
        print(f"Password is very strong. complexity score: {complexity}")
        return 5
    elif complexity == 3:
        print(f"Password is strong. complexity score: {complexity}")
        return 4
    elif complexity == 2:
        print(f"Password is moderate. complexity score: {complexity}")
        return 3
    elif complexity == 1:
        print(f"Password is weak. Complexity score: {complexity}")
        return 2
    else:
        print("Password has no complexity.")
        return 1




if __name__ == "__main__":
    print("""
██████████████████████████████████████████████████████████████████████████████████████████▀███████████
█▄─▄▄─██▀▄─██─▄▄▄▄█─▄▄▄▄█▄─█▀▀▀█─▄█─▄▄─█▄─▄▄▀█▄─▄▄▀███─▄▄▄▄█─▄─▄─█▄─▄▄▀█▄─▄▄─█▄─▀█▄─▄█─▄▄▄▄█─▄─▄─█─█─█
██─▄▄▄██─▀─██▄▄▄▄─█▄▄▄▄─██─█─█─█─██─██─██─▄─▄██─██─███▄▄▄▄─███─████─▄─▄██─▄█▀██─█▄▀─██─██▄─███─███─▄─█
▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▀▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▄▄▄▄▀▀▀▀▄▄▄▄▄▀▀▄▄▄▀▀▄▄▀▄▄▀▄▄▄▄▄▀▄▄▄▀▀▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀▄▀▄▀""")
    
    # Provides the user input loop. The loop asks the user for a password to test. 
    # If that password is anything but "q" or "Q" call the password_strength function 
    # and report the results to the user. If the user enters "q" or "Q", quit the program.

    while True:
        password = input('Enter your password (if you type "q" or "Q", the program will quit): ')

        if password.lower() == 'q':
            print("Exiting the program. Goodbye!")
            break

        strength = password_strength(password)
 
        print(f"Password strength: {strength}/5")