from cs50 import get_float
from math import floor


def main():
    while True:
        dollars = get_float("Change owed: ")
        change = floor(dollars * 100)

        if change > 0:
            break

    quarters = change // 25
    dimes = (change % 25) // 10
    nickels = ((change % 25) % 10) // 5
    pennies = ((change % 25) % 10) % 5

    print(f"{quarters + dimes + nickels + pennies}")


if __name__ == "__main__":
    main()