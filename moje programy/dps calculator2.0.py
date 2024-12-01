
import time
filename = "CalculatedDPS.txt"


class DPSCalculator:
    def __init__(self, 
                 itemName, 
                 baseElementalDMG, 
                 baseAtkSpeed, 
                 baseAtkSpdRed, 
                 shieldBasicBonus,
                 shieldRuneword,
                 itemPrice,
                 filename="CalculatedDPS.txt"):
        self.itemName = itemName
        self.baseElementalDMG = baseElementalDMG
        self.baseAtkSpeed = baseAtkSpeed
        self.baseAtkSpdRed = baseAtkSpdRed
        self.shieldBasicBonus = shieldBasicBonus
        self.shieldRuneword = shieldRuneword
        self.filename = filename
        self.itemPrice = itemPrice
        self.dpsfile = {}

    def calculate_atkspd(self):
        AtkSpd = (self.baseAtkSpeed * (1 - self.baseAtkSpdRed) - self.shieldBasicBonus) * (1 - self.shieldRuneword)
        return AtkSpd
    
    def calculate_dps(self):
        AtkSpd = self.calculate_atkspd()
        DPS = self.baseElementalDMG / AtkSpd
        return DPS
    
    def save_file(self):
        AtkSpd = self.calculate_atkspd()
        DPS = self.calculate_dps()
        print(f"{DPS}")
        
        with open(self.filename, 'a') as file:
            file.write(f"{self.itemName}: DPS: {DPS}(edmg:{self.baseElementalDMG}), AtkSpd: {AtkSpd}  |  PRICE: {self.itemPrice}\n")

        last_position = 0
        with open(filename, 'r') as file:
            file.seek(last_position)  # Przejdź do ostatniej pozycji
            new_data = file.read()  # Czytaj nowe dane
            if new_data:
                print(new_data, end='')  # Wyświetl nowe dane
                last_position = file.tell()  # Zaktualizuj pozycję końca pliku

# itemName = "Titan Slayer"
# itemName = "Nightguard"
itemName = input("Input weapon name: ")
baseElementalDMG = float(input("Input eDMG: "))
baseAtkSpeed = float(input("Input base attack speed: "))
itemPrice = input("Input price of the item: ")

baseAtkSpdRed = 0.1  # wyrażone w %
shieldBasicBonus = 0.44
shieldRuneword = 0.40  # wyrażone w %


dps_calculator = DPSCalculator(itemName, baseElementalDMG, baseAtkSpeed, baseAtkSpdRed, shieldBasicBonus, shieldRuneword, itemPrice)
dps_calculator.save_file()

