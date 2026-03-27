
#I've added a feature to select the payment method (credit, debit or cash).

if __name__ == "__main__":

    childmeal = float(input("What is the price of a child's meal? "))
    adultmeal = float(input("What is the price of an adult's meal? "))
    num_children = int(input("How many children are there? "))
    num_adults = int(input("How many adults are there? "))

    subtotal = (childmeal * num_children) + (adultmeal * num_adults)
    print(f"\nSubtotal: ${subtotal:.2f}")

    tax = float(input("\nWhat is the sales tax rate?"))
    tax = subtotal * (tax / 100)
    print(f"Sales Tax: ${tax:.2f}")

    total = subtotal + tax
    print(f"Total: ${total:.2f}")
    print("\nWhat is the payment method? ") 

    print("1 - Credit\n2 - Debit\n3 - Cash\n")
    if(method := int(input("Select the payment method (1-3): "))):

        if method == 1:
            print("You selected Credit Card.")
            if(approved := input("Is the payment approved? (yes/no) ")) == "yes":
                print("Payment approved.")
            else:
                print("Payment denied.")

        elif method == 2:
            print("You selected Debit Card.")
            if(approved := input("Is the payment approved? (yes/no) ")) == "yes":
                print("Payment approved.")
            else:
                print("Payment denied.")

        else:
            print("You selected Cash.")
            payment = float(input("What is the payment amount? "))
            if (change := payment - total) > 0:
                print(f"Change: ${change:.2f}")

#giving Tips is not really common in my country, so I didn't add that feature. kkk
    print("Thank you for your payment, have a great day!")



