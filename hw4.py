class Shopidify:
    def __init__(self, name=""):
        self.name = name
        self.item = {}
        if self.name == "":
            print(f'Welcome to Shopidify 1 ')
        else:
            print(f"Welcome {self.name} to Shopidify ")

    def add_to_cart(self, *item):
        if len(item) == 1 and type(item[0]) != list:
            self.item[item[0]] = 1
        elif len(item) == 1 and type(item[0]) == list:
            for i in range(0,len(item[0]), 2):
                print(item[0][i], item[0][i+1])
                self.item[item[0][i]] = item[0][i+1]
                
                
        elif len(item) == 2:
            self.item[item[0]] = item[1]

    def display_cart(self):
        if self.name == "":
            print(f'Items in the cart for Guest:')
            for k, v in self.item.items():
                print(f'- {k}: {v}x')
        else:
            print(f'Items in the cart for {self.name}:')
            for k, v in self.item.items():
                print(f'- {k}: {v}x')
guest_account = Shopidify()
print("1xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
john_account = Shopidify("John")
print("2xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
guest_account.add_to_cart("Air Jordan", 2)
guest_account.add_to_cart("Luffy Action Figure")
guest_account.display_cart()
print("3xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
john_account.add_to_cart(["Chocolate Chip Cookies", 3,"Goku Action Figure",2,"Dumbbells-5kg",2])
john_account.display_cart()
print("4xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
guest_account.add_to_cart("Air Jordan")
guest_account.display_cart()
print("5xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
# guest_account.checkout()
# print("6xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
# guest_account.display_history()
# print("7xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
# john_account.checkout()
# print("8xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")
# john_account.display_history()
# print("9xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")