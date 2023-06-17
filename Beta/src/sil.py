from star import ProtonSTARCalculator, ProtonMaterials

import matplotlib.pyplot as plt
import numpy as np

material = ProtonMaterials.SILICON 
#ALUMINUM; IRON; POLYETHILENE; SILICON
calculator = ProtonSTARCalculator(material)
print(dir(ProtonSTARCalculator))

for i in range(1, 11):
    print(calculator.calculate_total_stopping_powers(i))
    print(calculator.calculate_csda_ranges(i))



