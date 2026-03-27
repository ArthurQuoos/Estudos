# I've added a style to the title and a delay between lines for dramatic effect, 
# i implemented a function to provide feedback on guesses, and included input validation to ensure guesses are the correct length and format.
import time


def provide_feedback(guess, secret_word):
    feedback = []
    for i in range(len(secret_word)):
        if guess[i] == secret_word[i]:
            feedback.append(guess[i].upper())
        elif guess[i] in secret_word:
            feedback.append(guess[i].lower())
        else:
            feedback.append("_")
    return " ".join(feedback)


if __name__ == "__main__":

    banner = [
        "░██╗░░░░░░░██╗░█████╗░██████╗░██████╗░██╗░██████╗  ░██████╗░░█████╗░███╗░░░███╗███████╗",
        "░██║░░██╗░░██║██╔══██╗██╔══██╗██╔══██╗╚█║██╔════╝  ██╔════╝░██╔══██╗████╗░████║██╔════╝",
        "░╚██╗████╗██╔╝██║░░██║██████╔╝██║░░██║░╚╝╚█████╗░  ██║░░██╗░███████║██╔████╔██║█████╗░░",
        "░░████╔═████║░██║░░██║██╔══██╗██║░░██║░░░░╚═══██╗  ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░",
        "░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║██████╔╝░░░██████╔╝  ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗",
        "░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚═════╝░░░░╚═════╝░  ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝",
    ]
    for line in banner:
        print(line)
        time.sleep(0.40)

    print("""\n         Welcome to the Word Puzzle Game!\n
        Your goal is to guess the secret word.
        "Rules: Your guesses should be the same number of letters as the word, wich will be shown by "_",
        "You will have as many attempts as you need, but you should try to guess it in as few attempts as possible.",
        "After each guess, you will receive feedback:",
        "- Correct letters in the correct position will be shown in UPPERCASE.",
        "- Correct letters in the wrong position will be shown in lowercase.",
        "- Incorrect letters will be shown as underscores (_).",\n""")
    time.sleep(1)
    print("Let's begin!\n")
    secret_word = "MAGIC"
    word_length = len(secret_word)
    attempts = 0
    guess = ""
    feedback = ""
    while guess != secret_word:
        for i in range(word_length):
            print("_ ", end="")
        print("\n")
        guess = input(f"Enter your guess ({word_length} letters): ").upper()
        attempts += 1
        if(guess == secret_word):
            print(f"Congratulations! You've guessed the word '{secret_word}' in {attempts} attempts.")
            break
        elif len(guess) != word_length:
            print(f"Your guess must be {word_length} letters long. Try again.\n")
            continue
        elif not guess.isalpha():
            print("Your guess must only contain letters. Try again.\n")
            continue
        else:
            feedback = provide_feedback(guess, secret_word)
            print(f"Feedback: {feedback}\n")