import matplotlib.pyplot as plt
import pandas as pd

# Path to the data file
file_path = 'geometric-series_N100.dat'

# Reading the file
df = pd.read_csv(file_path, delimiter=',', encoding='utf-16')

# Access the columns
index = df['index']
series = df['sum']

# Asymptotic value for the series
q = 8 / 9
series_asymp = 1 / (1 - q)

# Create the plot
plt.xlabel(r'Index $n$')
plt.ylabel(r'Summation $s_n$')
plt.plot(index, series, label=r'Series approximation of $s_n$ for increasing $n$')
plt.axhline(y=series_asymp, color='red', linestyle='--', label='Asymptotic behavior')
plt.legend()

# Save the plot before showing it
plt.savefig('plot-geom-series.png', dpi=400)