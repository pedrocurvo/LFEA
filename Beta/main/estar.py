from star import electron
hydrogen = electron.PredefinedMaterials.HYDROGEN
data = electron.calculate_stopping_power(hydrogen, energy=[1e2,2e2,3e2]) # Energy in MeV
for data_points in data:
    print(data_points)