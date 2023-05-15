import numpy as np
from sklearn.linear_model import LinearRegression
x = np.array([124, 253, 382, 510, 639]).reshape((-1, 1))
y = np.array([1, 2, 3, 4, 5])
model = LinearRegression()
model.fit(x, y)
model = LinearRegression().fit(x, y)
print(f"intercept: {model.intercept_}")
print(f"slope: {model.coef_}")

# Energy 1
f = model.intercept_ + model.coef_ * 538.67
print(661.657/f)
y = y * 661.657/f
model.fit(x, y)
model = LinearRegression().fit(x, y)
print(f"intercept: {model.intercept_}")
print(f"slope: {model.coef_}")

f = model.intercept_ + model.coef_ * 26.65
print(f"Erro sistemático: {f-32} kEv")