
#enhance lvl > 0-14
#base > enhance lvl 0

class ElementalCalculator:
    def __init__(self, currentElementalDMG, enhanceLvl) -> float:
        self.currentElementalDMG = currentElementalDMG
        self.enhanceLvl = enhanceLvl
        
    def calculate(self):
        baseDamage = self.currentElementalDMG/(1 + self.enhanceLvl * 0.1)
        for i in range(15):
            enhancedDamage = baseDamage * (1 + i * 0.1)
            print(f"E[{i}], elemental damage: {int(enhancedDamage)}")
            

# currentELEDMG = int(input("Input your current elemental damage: "))
# enhanceLVL = int(input("Input your current enhance lvl [0-14]: "))

# res = ElementalCalculator(currentELEDMG, enhanceLVL)
# res.calculate()
ElementalCalculator(131, 0).calculate()
