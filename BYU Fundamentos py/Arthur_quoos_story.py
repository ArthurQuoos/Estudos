
#I didn't add anything new to the story, except the way the questions are asked to the user 

print("The other day, I was really in trouble. It all started when I saw a very ...")
adjective = input("type in a adjective: ")

print(f"The other day, I was really in trouble. It all started when I saw a very {adjective} ...")
animal = input("Type an animal: ")

print(f"The other day, I was really in trouble. It all started when I saw a very {adjective} {animal}...")
verb = input("Now a verb: ")

print(f"The other day, I was really in trouble. It all started when I saw a very {adjective} {animal} {verb} down the hallway. \"...!\" I yelled ...")
exclamation = input("What did you yelled? ")

print(f"The other day, I was really in trouble. It all started when I saw a very"
        f"{adjective} {animal} {verb} down the hallway. \"{exclamation.capitalize()}!\"" 
        f"I yelled. But all i could think to do was to ...")
verb2 = input("Do what? ")

print(f"The other day, I was really in trouble. It all started when I saw a very"
        f"{adjective} {animal} {verb} down the hallway. \"{exclamation.capitalize()}!\"" 
        f"I yelled. But all i could think to do was to {verb2} over and over. Miraculously,"
        f"that caused it to stop, but not before it tried to ...")
verb3 = input("To do what? ")

print(f"The other day, I was really in trouble. It all started when I saw a very"
        f"{adjective} {animal} {verb} down the hallway. \"{exclamation.capitalize()}!\"" 
        f"I yelled. But all i could think to do was to {verb2} over and over. Miraculously,"
        f"that caused it to stop, but not before it tried to {verb3} right in front of my family.")
