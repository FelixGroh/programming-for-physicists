import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_csv("bisection-method.dat", delimiter=",", encoding="utf-16")
a = df["a"]
b = df["b"]
p = df["p"]

def g(t):
    return t**3

def h(t):
    return np.log(t) + 5

x = np.linspace(0.25, 2.5, 400)
g_x = g(x)
h_x = h(x)

plt.plot(x, g_x, label = r"$g(x) = x^3$", color = "green")
plt.plot(x, h_x, label = r"$h(x) = \ln (x) + 5$", color = "red")

N = 11
y_int = np.linspace(max(g_x[-1], h_x[-1]), g(p.iloc[-1]), N)
for i in range(N):
    plt.plot([a[i], b[i]], [y_int[i], y_int[i]], color = "blue")
    plt.scatter(p[i], y_int[i], marker='*', color="black", s=25)

plt.title("Search for intersection using bisection method")
plt.xlabel(r"$x$")
plt.ylabel(r"$y(x)$")
plt.legend()
plt.savefig("bisection-method-visualization.png", dpi=600)