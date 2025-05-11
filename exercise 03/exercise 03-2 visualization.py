import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df = pd.read_csv("bernoulli-map.dat", delimiter=",", encoding="utf-16")
x_t0f = df["x_0f"]
x_t1f = df["x_1f"]
x_t2f = df["x_2f"]
x_t3f = df["x_3f"]

x_t0d = df["x_0d"]
x_t1d = df["x_1d"]
x_t2d = df["x_2d"]
x_t3d = df["x_3d"]

t = np.linspace(0, len(x_t0f) - 1, len(x_t0f))
fig, ax = plt.subplots(2, 2, figsize = (10, 10))
fig.suptitle("Bernoulli map for float and double precision")
ax[0,0].plot(t, x_t0f, color = "red", label = "float") 
ax[0,1].plot(t, x_t1f, color = "red")    
ax[1,0].plot(t, x_t2f, color = "red")
ax[1,1].plot(t, x_t3f, color = "red")

ax[0,0].plot(t, x_t0d, color = "green", label = "double")
ax[0,1].plot(t, x_t1d, color = "green")
ax[1,0].plot(t, x_t2d, color = "green")
ax[1,1].plot(t, x_t3d, color = "green")

ax[0,0].set_title(r"$x_0 = \frac{1}{3}$")     
ax[0,1].set_title(r"$x_0 = \frac{1}{7}$")     
ax[1,0].set_title(r"$x_0 = \frac{1}{11}$")    
ax[1,1].set_title(r"$x_0 = \frac{1}{2^{20}}$")

fig.supxlabel(r"$t$")
fig.supylabel(r"$x_t$")
fig.legend()
fig.savefig("bernoulli-map-visualization.png", dpi=600)