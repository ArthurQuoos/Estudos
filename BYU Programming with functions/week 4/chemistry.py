#i always like to add the ascii art, i also added a loop to allow multiple calculations without restarting the program and an error handling for invalid inputs

def make_periodic_table():
    periodic_table = {
        "Ac": ("Actinium", 227),
        "Ag": ("Silver", 107.8682),
        "Al": ("Aluminum", 26.9815386),
        "Ar": ("Argon", 39.948),
        "As": ("Arsenic", 74.9216),
        "At": ("Astatine", 210),
        "Au": ("Gold", 196.966569),
        "B": ("Boron", 10.811),
        "Ba": ("Barium", 137.327),
        "Be": ("Beryllium", 9.012182),
        "Bi": ("Bismuth", 208.9804),
        "Br": ("Bromine", 79.904),
        "C": ("Carbon", 12.0107),
        "Ca": ("Calcium", 40.078),
        "Cd": ("Cadmium", 112.411),
        "Ce": ("Cerium", 140.116),
        "Cl": ("Chlorine", 35.453),
        "Co": ("Cobalt", 58.933195),
        "Cr": ("Chromium", 51.9961),
        "Cs": ("Cesium", 132.9054519),
        "Cu": ("Copper", 63.546),
        "Dy": ("Dysprosium", 162.5),
        "Er": ("Erbium", 167.259),
        "Eu": ("Europium", 151.964),
        "F": ("Fluorine", 18.9984032),
        "Fe": ("Iron", 55.845),
        "Fr": ("Francium", 223),
        "Ga": ("Gallium", 69.723),
        "Gd": ("Gadolinium", 157.25),
        "Ge": ("Germanium", 72.64),
        "H": ("Hydrogen", 1.00794),
        "He": ("Helium", 4.002602),
        "Hf": ("Hafnium", 178.49),
        "Hg": ("Mercury", 200.59),
        "Ho": ("Holmium", 164.93032),
        "I": ("Iodine", 126.90447),
        "In": ("Indium", 114.818),
        "Ir": ("Iridium", 192.217),
        "K": ("Potassium", 39.0983),
        "Kr": ("Krypton", 83.798),
        "La": ("Lanthanum", 138.90547),
        "Li": ("Lithium", 6.941),
        "Lu": ("Lutetium", 174.9668),
        "Mg": ("Magnesium", 24.305),
        "Mn": ("Manganese", 54.938045),
        "Mo": ("Molybdenum", 95.96),
        "N": ("Nitrogen", 14.0067),
        "Na": ("Sodium", 22.98976928),
        "Nb": ("Niobium", 92.90638),
        "Nd": ("Neodymium", 144.242),
        "Ne": ("Neon", 20.1797),
        "Ni": ("Nickel", 58.6934),
        "Np": ("Neptunium", 237),
        "O": ("Oxygen", 15.9994),
        "Os": ("Osmium", 190.23),
        "P": ("Phosphorus", 30.973762),
        "Pa": ("Protactinium", 231.03588),
        "Pb": ("Lead", 207.2),
        "Pd": ("Palladium", 106.42),
        "Pm": ("Promethium", 145),
        "Po": ("Polonium", 209),
        "Pr": ("Praseodymium", 140.90765),
        "Pt": ("Platinum", 195.084),
        "Pu": ("Plutonium", 244),
        "Ra": ("Radium", 226),
        "Rb": ("Rubidium", 85.4678),
        "Re": ("Rhenium", 186.207),
        "Rh": ("Rhodium", 102.9055),
        "Rn": ("Radon", 222),
        "Ru": ("Ruthenium", 101.07),
        "S": ("Sulfur", 32.065),
        "Sb": ("Antimony", 121.76),
        "Sc": ("Scandium", 44.955912),
        "Se": ("Selenium", 78.96),
        "Si": ("Silicon", 28.0855),
        "Sm": ("Samarium", 150.36),
        "Sn": ("Tin", 118.71),
        "Sr": ("Strontium", 87.62),
        "Ta": ("Tantalum", 180.94788),
        "Tb": ("Terbium", 158.92535),
        "Tc": ("Technetium", 98),
        "Te": ("Tellurium", 127.6),
        "Th": ("Thorium", 232.03806),
        "Ti": ("Titanium", 47.867),
        "Tl": ("Thallium", 204.3833),
        "Tm": ("Thulium", 168.93421),
        "U": ("Uranium", 238.02891),
        "V": ("Vanadium", 50.9415),
        "W": ("Tungsten", 183.84),
        "Xe": ("Xenon", 131.293),
        "Y": ("Yttrium", 88.90585),
        "Yb": ("Ytterbium", 173.054),
        "Zn": ("Zinc", 65.38),
        "Zr": ("Zirconium", 91.224)
    }
    return periodic_table

def validate_formula(compound_list, periodic_table):
    for symbol, _ in compound_list:
        if symbol not in periodic_table:
            raise ValueError(f"Unknown element symbol: {symbol}")


def parse_formula(formula):
    """Converts a chemical formula string into a compound list.
    Example: "H2O" -> [["H", 2], ["O", 1]]
    """
    compound = []
    i = 0

    while i < len(formula):
        symbol = formula[i]
        i += 1

        if i < len(formula) and formula[i].islower():
            symbol += formula[i]
            i += 1

        quantity = ""
        while i < len(formula) and formula[i].isdigit():
            quantity += formula[i]
            i += 1

        if quantity == "":
            quantity = 1
        else:
            quantity = int(quantity)

        compound.append([symbol, quantity])

    return compound


def compute_molar_mass(symbol_quantity_list, periodic_table):
    """Computes and returns the molar mass of a compound."""
    molar_mass = 0

    for element in symbol_quantity_list:
        symbol = element[0]
        quantity = element[1]
        atomic_mass = periodic_table[symbol][1]
        molar_mass += atomic_mass * quantity

    return molar_mass


def main():

    print("""
░█████╗░██╗░░██╗███████╗███╗░░░███╗██╗░██████╗████████╗██████╗░██╗░░░██╗░░░██████╗░██╗░░░██╗
██╔══██╗██║░░██║██╔════╝████╗░████║██║██╔════╝╚══██╔══╝██╔══██╗╚██╗░██╔╝░░░██╔══██╗╚██╗░██╔╝
██║░░╚═╝███████║█████╗░░██╔████╔██║██║╚█████╗░░░░██║░░░██████╔╝░╚████╔╝░░░░██████╔╝░╚████╔╝░
██║░░██╗██╔══██║██╔══╝░░██║╚██╔╝██║██║░╚═══██╗░░░██║░░░██╔══██╗░░╚██╔╝░░░░░██╔═══╝░░░╚██╔╝░░
╚█████╔╝██║░░██║███████╗██║░╚═╝░██║██║██████╔╝░░░██║░░░██║░░██║░░░██║░░░██╗██║░░░░░░░░██║░░░
░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚═╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░░╚═╝░░░╚═╝╚═╝░░░░░░░░╚═╝░░░""")

    periodic_table = make_periodic_table()

    while True:
        formula = input("Enter the chemical formula (or 'q' to quit): ")
        if formula.lower() == "q":
            print("Goodbye!")
            break

        try:
            sample_mass = float(input("Enter the sample mass in grams: "))

            compound_list = parse_formula(formula)
            validate_formula(compound_list, periodic_table)

            molar_mass = compute_molar_mass(compound_list, periodic_table)
            moles = sample_mass / molar_mass

            print(f"Molar mass: {molar_mass:.3f} g/mol")
            print(f"Number of moles: {moles:.4f} mol\n")

        except ValueError as error:
            print(f"Error: {error}\n")


if __name__ == "__main__":
    main()
