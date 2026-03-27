#I've added a cool "shopping cart" print art at the beginning of the program, and error handling for removing items from an empty cart.

if __name__ == "__main__":
    print("""
█▀ █░█ █▀█ █▀█ █▀█ █ █▄░█ █▀▀   █▀▀ ▄▀█ █▀█ ▀█▀
▄█ █▀█ █▄█ █▀▀ █▀▀ █ █░▀█ █▄█   █▄▄ █▀█ █▀▄ ░█░""")

    print("You have entered the shopping cart program.\n")
    cart = []
    prices = []
    while True:
        print("What would you like to do?")
        print("1 - Add item to cart\n2 - View cart\n3 - Remove item from cart\n4 - Compute the total\n5 - Exit")
        choice = int(input("Select an option (1-5): "))
        if choice == 1:
            item = input("Enter the item name: ")
            item_price = float(input("Enter the item price: "))
            cart.append(item)
            prices.append(item_price)
            print(f"{item} has been added to the cart.")
        elif choice == 2:
            print("Items in your cart:")
            for i, item in enumerate(cart):
                print(f"{i + 1}. {item} - ${prices[i]:.2f}")
        elif choice == 3:
            if not cart:
                print("Your cart is empty. Nothing to remove.")
                continue
            item_index = int(input("Enter the item number to remove: ")) - 1
            if 0 <= item_index < len(cart):
                removed_item = cart.pop(item_index)
                removed_price = prices.pop(item_index)
                print(f"{removed_item} has been removed from the cart.")
            else:
                print("Invalid item number.")
        elif choice == 4:
            total = sum(prices)
            print(f"The total price of the items in your cart is: ${total:.2f}")
        elif choice == 5:
            print("Exiting the shopping cart program.")
            break
        else:
            print("Invalid option. Please select a number between 1 and 5.")