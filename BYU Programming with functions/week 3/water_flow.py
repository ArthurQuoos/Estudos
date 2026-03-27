# I added a cool ASCII art title to the main function, and used constants for gravity and water properties.

EARTH_ACCELERATION_OF_GRAVITY = 9.8066500
WATER_DENSITY = 998.2000000  # kg/m³
WATER_DYNAMIC_VISCOSITY = 0.0010016  # Pa·s

def water_column_height(tower_height, tank_height):
    return tower_height + (3 * tank_height) / 4

def pressure_gain_from_water_height(height):
    return WATER_DENSITY * EARTH_ACCELERATION_OF_GRAVITY * height / 1000


def pressure_loss_from_pipe(pipe_diameter, pipe_length,
                            friction_factor, fluid_velocity):
    return (-friction_factor * pipe_length * WATER_DENSITY *
            fluid_velocity ** 2) / (2000 * pipe_diameter)

def pressure_loss_from_fittings(fluid_velocity, quantity_fittings):
    return -0.04 * WATER_DENSITY * fluid_velocity ** 2 * quantity_fittings / 2000

def reynolds_number(hydraulic_diameter, fluid_velocity):
    return (WATER_DENSITY * hydraulic_diameter * fluid_velocity) / WATER_DYNAMIC_VISCOSITY

def pressure_loss_from_pipe_reduction(larger_diameter, fluid_velocity, reynolds_number, smaller_diameter):
    k = (0.1 + (50 / reynolds_number)) * ((larger_diameter / smaller_diameter) ** 4 - 1)
    
    return -k * WATER_DENSITY * fluid_velocity ** 2 / 2000


def main():
    print("""
░██╗░░░░░░░██╗░█████╗░████████╗███████╗██████╗░  ██████╗░██████╗░███████╗░██████╗░██████╗██╗░░░██╗██████╗░███████╗
░██║░░██╗░░██║██╔══██╗╚══██╔══╝██╔════╝██╔══██╗  ██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║░░░██║██╔══██╗██╔════╝
░╚██╗████╗██╔╝███████║░░░██║░░░█████╗░░██████╔╝  ██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░██║░░░██║██████╔╝█████╗░░
░░████╔═████║░██╔══██║░░░██║░░░██╔══╝░░██╔══██╗  ██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗██║░░░██║██╔══██╗██╔══╝░░
░░╚██╔╝░╚██╔╝░██║░░██║░░░██║░░░███████╗██║░░██║  ██║░░░░░██║░░██║███████╗██████╔╝██████╔╝╚██████╔╝██║░░██║███████╗
░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░░╚═════╝░╚═╝░░╚═╝╚══════╝""")
    
    tower_height = float(input("Height of water tower (meters): "))
    tank_height = float(input("Height of water tank walls (meters): "))
    pipe_length1 = float(input("Length of supply pipe from tank to lot (meters): "))
    fittings = int(input("Number of 90° angles in supply pipe: "))
    pipe_length2 = float(input("Length of pipe from supply to house (meters): "))

    # Constantes do sistema
    pipe_diameter_large = 0.28687
    pipe_diameter_small = 0.048692
    friction_factor_large = 0.013
    fluid_velocity = 1.65
    friction_factor_small = 0.018

    # Cálculos
    height = water_column_height(tower_height, tank_height)
    pressure = pressure_gain_from_water_height(height)

    pressure += pressure_loss_from_pipe(
        pipe_diameter_large,
        pipe_length1,
        friction_factor_large,
        fluid_velocity
    )

    pressure += pressure_loss_from_fittings(
        fluid_velocity,
        fittings
    )

    re = reynolds_number(pipe_diameter_large, fluid_velocity)

    pressure += pressure_loss_from_pipe_reduction(
        pipe_diameter_large,
        fluid_velocity,
        re,
        pipe_diameter_small
    )

    pressure += pressure_loss_from_pipe(
    pipe_diameter_small,
    pipe_length2,
    friction_factor_small,
    fluid_velocity
    )

    print(f"Pressure at house: {pressure:.1f} kilopascals")


main()