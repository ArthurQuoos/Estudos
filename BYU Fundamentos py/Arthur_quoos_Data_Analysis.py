# I added a "pretty" menu to navigate through the analysis options, and funtion to search for life expectancy by country.


def highest_life_expectancy(file):
    file.seek(0)  # Reset file pointer to the beginning
    next(file) # Skip header line
    highest = 0
    for line in file:
        spilited_line = line.strip().split(",")
        if float(spilited_line[3]) > highest:
            highest = float(spilited_line[3])
            country = spilited_line[0]
            year = spilited_line[2]
            life_expectancy = float(spilited_line[3])

    return country, year, life_expectancy

def lowest_life_expectancy(file):
    file.seek(0)  # Reset file pointer to the beginning
    next(file) # Skip header line
    lowest = float('inf')
    for line in file:
        spilited_line = line.strip().split(",")
        if float(spilited_line[3]) < lowest:
            lowest = float(spilited_line[3])
            country = spilited_line[0]
            year = spilited_line[2]
            life_expectancy = float(spilited_line[3])

    return country, year, life_expectancy

def life_expectancy_in_year(file, year):
    file.seek(0)  # Reset file pointer to the beginning
    next(file) # Skip header line
    total_life_expectancy = 0
    count = 0
    highest = 0
    lowest = 1000
    country_high = ""
    country_low = ""
    for line in file:
        spilited_line = line.strip().split(",")
        if int(spilited_line[2]) == year:
            total_life_expectancy += float(spilited_line[3])
            count += 1
            if float(spilited_line[3]) > highest:
                highest = float(spilited_line[3])
                country_high = spilited_line[0]
            if float(spilited_line[3]) < lowest:
                lowest = float(spilited_line[3])
                country_low = spilited_line[0]
    if count == 0:
        return 0

    average_life_expectancy = total_life_expectancy / count
    return average_life_expectancy, highest, country_high, lowest, country_low

def life_expectancy_in_country(file, country):
    file.seek(0)  # Reset file pointer to the beginning
    next(file) # Skip header line
    total_life_expectancy = 0
    count = 0
    highest = 0
    lowest = 1000
    year_high = ""
    year_low = ""
    for line in file:
        spilited_line = line.strip().split(",")
        if spilited_line[0].lower() == country.lower():
            total_life_expectancy += float(spilited_line[3])
            count += 1
            if float(spilited_line[3]) > highest:
                highest = float(spilited_line[3])
                year_high = spilited_line[2]
            if float(spilited_line[3]) < lowest:
                lowest = float(spilited_line[3])
                year_low = spilited_line[2]
    if count == 0:
        return 0

    average_life_expectancy = total_life_expectancy / count
    return average_life_expectancy, highest, year_high, lowest, year_low

def main():
    print("""
██████╗░░█████╗░████████╗░█████╗░  ░█████╗░███╗░░██╗░█████╗░██╗░░░░░██╗░░░██╗░██████╗███████╗██████╗░
██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗  ██╔══██╗████╗░██║██╔══██╗██║░░░░░╚██╗░██╔╝██╔════╝██╔════╝██╔══██╗
██║░░██║███████║░░░██║░░░███████║  ███████║██╔██╗██║███████║██║░░░░░░╚████╔╝░╚█████╗░█████╗░░██████╔╝
██║░░██║██╔══██║░░░██║░░░██╔══██║  ██╔══██║██║╚████║██╔══██║██║░░░░░░░╚██╔╝░░░╚═══██╗██╔══╝░░██╔══██╗
██████╔╝██║░░██║░░░██║░░░██║░░██║  ██║░░██║██║░╚███║██║░░██║███████╗░░░██║░░░██████╔╝███████╗██║░░██║
╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝  ╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝╚══════╝░░░╚═╝░░░╚═════╝░╚══════╝╚═╝░░╚═╝""")


    with open("life-expectancy.csv", "r", encoding="utf-8") as arq:

        while(True):
            print("Welcome to the Life Expectancy Analyzer!"
                  "\n1- Show overall max life expectancy and in wich country and year it occurred"
                  "\n2- Show overall min life expectancy and in wich country and year it occurred"
                  "\n3- Show a report about life expectancy for a given year"
                  "\n4- Show a report about life expectancy for a given country"
                  "\n5- Exit")
            choice = input("Please enter your choice (1-5): ")

            if choice == '1':
                 highest = highest_life_expectancy(arq) 
                 print(f"The overall max life expectancy is {highest[0]} in the year {highest[1]} with {highest[2]} years.")

            elif choice == '2':
                 lowest = lowest_life_expectancy(arq)
                 print(f"The overall min life expectancy is {lowest[0]} in the year {lowest[1]} with {lowest[2]} years.")

            elif choice == '3':
                year = input("Enter the year to see the average life expectancy from that time: ")
                data = life_expectancy_in_year(arq, int(year))
                print(f"for the year {year}:" 
                      f"\nThe average life expectancy across all countries was {data[0]:.2f} years."
                      f"\nThe max life expectancy was {data[1]} in country {data[2]}"
                      f"\nThe min life expectancy was {data[3]} in country {data[4]}.")
                
            elif choice == '4':
                country = input("Enter the country to see the average life expectancy for that country: ")
                data = life_expectancy_in_country(arq, country)
                print(f"For the country {country}:"
                      f"The average life expectancy across all years was {data[0]:.2f} years."
                      f"\nThe max life expectancy was {data[1]} in year {data[2]}"
                      f"\nThe min life expectancy was {data[3]} in year {data[4]}.")
                
            elif choice == '5':
                print("Exiting the program. Goodbye!")
                break
            else:
                print("Invalid choice. Please enter a number between 1 and 5.")



if __name__ == "__main__":
    main()