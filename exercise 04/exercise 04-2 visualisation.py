import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv("fibonacci.dat", sep = ",", encoding= "utf-16")

index = df['index']
fn = df['fn']

phi = 1.618033988749894848204586834
phi_ratio = np.zeros(len(index) - 1)


for i in range(len(index) - 1):
    phi_ratio[i] = fn[i + 1] / fn[i]

plt.plot(index[:len(index) - 1], phi_ratio, color = 'blue', label = r"$\frac{f(n+1)}{f(n)}$", marker = ".")
plt.xlabel(r"Index $n$")
plt.ylabel("Ratio of consecutive elements of the fibonacci sequence")
plt.axhline(y = phi, label = r"literature value of $\phi$", linestyle = "--", color = "red")
plt.legend()
plt.savefig("fibonacci-plot.png", dpi = 400)
