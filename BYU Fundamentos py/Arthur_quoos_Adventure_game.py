 # I chose fantasy genre for the game, used loops to make sure the user inputs valid choices.



if __name__ == "__main__":
    print("""In search of the Crystal of Aeloria!
          
        You are a young apprentice of the Grand Mage Arven. One night, he disappears, leaving behind only a glowing crystal and a note that says:
        “The fate of Aeloria depends on your courage. Follow the light.”
        You step outside your tower and see three glowing paths leading in different directions.\n""")
    
    path = input("Do you follow the FOREST path, the MOUNTAIN trail, or the RIVER road? ").upper()
    while True:
        if path == "FOREST":
            break
        elif path == "MOUNTAIN":
            break
        elif path == "RIVER":
            break  
        else:
            path = input("Invalid choice. Please choose FOREST, MOUNTAIN, or RIVER: ").upper()
        
    if path == "FOREST":
        print("""The forest is silent except for the sound of whispering leaves. Suddenly, a hooded figure appears and blocks your way.

        Do you TALK, ATTACK, or RUN?""")
        action = input().upper()
        while True:
            if action == "TALK":
                break
            elif action == "ATTACK":
                print("The spirit vanishes, and the forest comes alive with angry vines. Game over.")
                exit()
            elif action == "RUN":
                print("You trip on a root and fall into a hidden pit. Game over.")
                exit()
            else:
                action = input("Invalid choice. Please choose TALK, ATTACK, or RUN: ").upper()
        
        if action == "TALK":
            print("""The hooded figure reveals herself to be a forest spirit. She offers you a choice: a BOW OF LIGHT or a SHIELD OF ROOTS.""")
            item = input("Do you choose BOW of light or SHIELD of roots? ").upper()
            while True:
                if item == "BOW":
                    print("You defeat the shadow creatures ahead and find the crystal’s twin. You win!")
                    exit()
                elif item == "SHIELD":
                    print("You survive the forest’s dangers but never find the crystal. You survive, but fail your quest.")
                    exit()
                else:
                    item = input("Invalid choice. Please choose BOW or SHIELD: ").upper()

    if path == "MOUNTAIN":
        print("""You climb higher and higher until you reach a cave entrance glowing with blue light. Inside, a stone guardian awakens.

        Do you FIGHT or SPEAK to it?""")
        action = input().upper()
        while True:
            if action == "FIGHT":
                print("Your magic harms the creature, but it grows stronger with every hit. Finally, it smashes the ground, and the cave collapses. Game over.")
                exit()
            elif action == "SPEAK":
                break
            else:
                action = input("Invalid choice. Please choose FIGHT or SPEAK: ").upper()
        
        if action == "SPEAK":
            print("""The guardian listens and offers you a riddle:

            “I am born in darkness but bring light to others. What am I?”
            Do you answer FIRE, STAR, or CRYSTAL?""")
            answer = input().upper()
            while True:
                if answer == "FIRE":
                    print("“Correct,” says the guardian. He steps aside, revealing the hidden Crystal of Aeloria. You win!")
                    exit()
                elif answer == "STAR":
                    print("The guardian shakes its head and fades away. You are trapped forever in the cave. Game over.")
                    exit()
                elif answer == "CRYSTAL":
                    print("The guardian laughs: “Too obvious.” The cave trembles and collapses. Game over.")
                    exit()
                else:
                    answer = input("Invalid choice. Please choose FIRE, STAR, or CRYSTAL: ").upper()

    if path == "RIVER":
        print("""You follow the river until you reach an old bridge guarded by a knight in silver armor.
        He raises his sword and says: “None shall pass unless they prove their worth!”""")

        action = input("Do you DUEL, offer GOLD, or try to REASON? ").upper()
        while True:
            if action == "DUEL":
                print("The knight respects your courage but defeats you easily. Game over.")
                exit()
            elif action == "GOLD":
                print("The knight accepts your bribe, but when you cross, the bridge collapses. Game over.")
                exit()
            elif action == "REASON":
                print("You explain your mission to save Aeloria. The knight kneels and gifts you his sword. With it, you channel the crystal’s power and restore peace to the realm. You win!")
                exit()
            else:
                action = input("Invalid choice. Please choose DUEL, GOLD, or REASON: ").upper()
  