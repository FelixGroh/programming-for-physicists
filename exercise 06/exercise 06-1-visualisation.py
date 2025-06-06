import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv(
    "logistic-map.dat",
    sep=' ',
    comment='#',
    header=None,
    encoding='utf-16'
)

transient = 200
a_vals = df.iloc[:, 0]
x_vals = df.iloc[:, transient:]

zooms = [
    (3.52, 3.66, 0.3, 0.4, r"Zoom 1: $a \in [3.52,\ 3.66],\ x_n \in [0.3,\ 0.4]$"),
    (3.62, 3.64, 0.3, 0.31, r"Zoom 2: $a \in [3.62,\ 3.64],\ x_n \in [0.3,\ 0.31]$"),
    (3.835, 3.86, 0.45, 0.54, r"Zoom 3: $a \in [3.835,\ 3.86],\ x_n \in [0.45,\ 0.54]$")
]

fig, axes = plt.subplots(2, 2, figsize=(12, 8))
axes = axes.flatten()

for i in x_vals.columns:
    axes[0].plot(a_vals, x_vals[i], ',', color='black', alpha=0.25)
axes[0].set_title(r"Feigenbaum-Diagramm: $a \in [2.8,\ 4.0],\ x_n \in [0,\ 1]$")
axes[0].set_xlabel("a")
axes[0].set_ylabel("$x_n$")
axes[0].grid(True)

for ax, (a_min, a_max, x_min, x_max, title) in zip(axes[1:], zooms):
    for i in x_vals.columns:
        mask = (a_vals >= a_min) & (a_vals <= a_max)
        ax.plot(
            a_vals[mask],
            x_vals.loc[mask, i],
            '.',
            color='black',
            alpha=0.6,
            markersize=3
        )
    ax.set_xlim(a_min, a_max)
    ax.set_ylim(x_min, x_max)
    ax.set_title(title)
    ax.set_xlabel("a")
    ax.set_ylabel("$x_n$")
    ax.grid(True)

plt.tight_layout()
plt.savefig("logistic-map.png", dpi=300)