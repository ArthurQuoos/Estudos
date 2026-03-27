#as always i like to add the ASCI art, i also tried doing the challengem i've marked on the code with comments to show the parts that are about the challenge.


import csv
from datetime import datetime

SALES_TAX_RATE = 0.06
DISCOUNT_PRODUCT_ID = "D083"  # --- CHALLENGE: product with BOGO 50% discount ---


def read_dictionary(filename, key_column_index):
    dictionary = {}

    with open(filename, "r", newline="", encoding="utf-8") as file:
        reader = csv.reader(file)
        next(reader)

        for row in reader:
            key = row[key_column_index]
            dictionary[key] = row

    return dictionary


def main():
    try:
        products = read_dictionary("products.csv", 0)

        print("""
██████╗░░█████╗░██╗░░░██╗  ██╗░░░░░███████╗░██████╗░██████╗  ░██████╗████████╗░█████╗░██████╗░███████╗
██╔══██╗██╔══██╗╚██╗░██╔╝  ██║░░░░░██╔════╝██╔════╝██╔════╝  ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔════╝
██████╔╝███████║░╚████╔╝░  ██║░░░░░█████╗░░╚█████╗░╚█████╗░  ╚█████╗░░░░██║░░░██║░░██║██████╔╝█████╗░░
██╔═══╝░██╔══██║░░╚██╔╝░░  ██║░░░░░██╔══╝░░░╚═══██╗░╚═══██╗  ░╚═══██╗░░░██║░░░██║░░██║██╔══██╗██╔══╝░░
██║░░░░░██║░░██║░░░██║░░░  ███████╗███████╗██████╔╝██████╔╝  ██████╔╝░░░██║░░░╚█████╔╝██║░░██║███████╗
╚═╝░░░░░╚═╝░░╚═╝░░░╚═╝░░░  ╚══════╝╚══════╝╚═════╝░╚═════╝░  ╚═════╝░░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝╚══════╝""")
        print("------------------------------------------------------------------------------")

        total_items = 0
        subtotal = 0

        with open("request.csv", "r", newline="", encoding="utf-8") as file:
            reader = csv.reader(file)
            next(reader)

            for row in reader:
                product_id = row[0]
                quantity = int(row[1])

                product = products[product_id]
                name = product[1]
                price = float(product[2])

                total_items += quantity

                # --- CHALLENGE: Buy One Get One Half Off logic ---
                if product_id == DISCOUNT_PRODUCT_ID:
                    discounted_items = quantity // 2   # number of items at 50% off
                    full_price_items = quantity - discounted_items

                    item_total = (full_price_items * price) + \
                                 (discounted_items * price * 0.5)

                    discount_amount = discounted_items * price * 0.5

                    subtotal += item_total

                    print(f"{name}: {quantity} @ {price:.2f}")
                    print(f"  Discount applied: -{discount_amount:.2f}")  # --- CHALLENGE ---
                else:
                    subtotal += price * quantity
                    print(f"{name}: {quantity} @ {price:.2f}")

        sales_tax = subtotal * SALES_TAX_RATE
        total = subtotal + sales_tax

        print(f"Number of Items: {total_items}")
        print(f"Subtotal: {subtotal:.2f}")
        print(f"Sales Tax: {sales_tax:.2f}")
        print(f"Total: {total:.2f}")
        print("Thank you for shopping at the Inkom Emporium.")

        current_date = datetime.now()
        print(current_date.strftime("%a %b %d %H:%M:%S %Y"))

    except FileNotFoundError as error:
        print("Error: missing file")
        print(error)
    except PermissionError as error:
        print("Error: permission denied")
        print(error)
    except KeyError as error:
        print("Error: unknown product ID in the request.csv file")
        print(error)


if __name__ == "__main__":
    main()
