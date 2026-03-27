#

import math
from datetime import datetime

current_date_and_time = datetime.now()  
#print(f"{current_date_and_time:%Y-%m-%d}") #testing date format

tires = [
    {"diameter": 15, "width": 175, "aspect": 65, "price": "$249 to $630"},
    {"diameter": 16, "width": 195, "aspect": 55, "price": "$450 to $800"},
    {"diameter": 17, "width": 205, "aspect": 55, "price": "$450 to $1,100"},
    {"diameter": 18, "width": 255, "aspect": 45, "price": "$700 to $2,000+"}
]


def similarity(d, w, a, tire):
    return abs(d - tire["diameter"]) + \
           abs(w - tire["width"]) + \
           abs(a - tire["aspect"])


if __name__ == "__main__":
    print("""
    ████████╗██╗░░░██╗██████╗░███████╗  ░█████╗░░█████╗░██╗░░░░░░█████╗░██╗░░░██╗██╗░░░░░░█████╗░████████╗░█████╗░██████╗░
    ╚══██╔══╝╚██╗░██╔╝██╔══██╗██╔════╝  ██╔══██╗██╔══██╗██║░░░░░██╔══██╗██║░░░██║██║░░░░░██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗
    ░░░██║░░░░╚████╔╝░██████╔╝█████╗░░  ██║░░╚═╝███████║██║░░░░░██║░░╚═╝██║░░░██║██║░░░░░███████║░░░██║░░░██║░░██║██████╔╝
    ░░░██║░░░░░╚██╔╝░░██╔══██╗██╔══╝░░  ██║░░██╗██╔══██║██║░░░░░██║░░██╗██║░░░██║██║░░░░░██╔══██║░░░██║░░░██║░░██║██╔══██╗
    ░░░██║░░░░░░██║░░░██║░░██║███████╗  ╚█████╔╝██║░░██║███████╗╚█████╔╝╚██████╔╝███████╗██║░░██║░░░██║░░░╚█████╔╝██║░░██║
    ░░░╚═╝░░░░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ░╚════╝░╚═╝░░╚═╝╚══════╝░╚════╝░░╚═════╝░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝""")

    width = float(input("\n\nEnter the tire width in mm (e.g., 205): "))
    aspect_ratio = float(input("Enter the aspect ratio (e.g., 60): "))
    diameter = float(input("Enter the diameter of the wheel in inches (e.g., 15): "))

    volume = (math.pi * width**2 * aspect_ratio * (width * aspect_ratio + 2540 * diameter)) / 10000000000
    print(f"The volume of the tire is {volume:.2f} liters\n")

    if 15 <= diameter <= 22 and 175 <= width <= 255 and 45 <= aspect_ratio <= 80:
        print("These are popular tire dimensions.")

        best_match = min(tires,key=lambda tire: similarity(diameter, width, aspect_ratio, tire))

        print("\nWe couldn't find an exact match.")
        print("Based on your input, we recommend:")
        print(f'{best_match["width"]}/{best_match["aspect"]}R{best_match["diameter"]}')
        print(f'Price range: {best_match["price"]}')
    else:
        print("These dimensions are not common in our catalog.")



    answer = input("Would you like to buy tires with these dimensions?")

    if answer.lower() in ['yes', 'y']:
        client_name = input("Enter your name: ")
        client_phone = input("Enter your phone number: ")

    with open("tire_volume_log.txt", "a") as log_file:
        log_file.write(f"{current_date_and_time:%Y-%m-%d}, {width}, {aspect_ratio}, {diameter}, {volume:.2f}\n")
        if answer.lower() in ['yes', 'y']:
            log_file.write(f"Client Name: {client_name}, Client Phone: {client_phone}\n")
            print("Thank you! We will contact you soon.")