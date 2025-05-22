import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv("lagrange-polynomial.dat", sep= ",", encoding="utf-16")

Px_val = df["x"]
Py_val = df["Pn"]

x_points = np.array([2, 10.1, 15, 20, 40, 60, 90])
y_points = np.array([2.1, 41, 43, 40.2, 12, 5, 17.5])

plt.plot(Px_val, Py_val, color = "red", label = r"Lagrange polynomial $P_6(x)$")
plt.scatter(x_points, y_points, marker = ".", label = "Original Points")
plt.title("Lagrange polynomial interpolation")
plt.xlabel('x')
plt.ylabel(r'$P_6(x)$')
plt.grid()
plt.legend()
plt.tight_layout()
plt.savefig("lagrange-polynomials-plot.png", dpi = 400)