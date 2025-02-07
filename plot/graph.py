import pandas as pd
import matplotlib.pyplot as plt
import os
# Read CSV file
df = pd.read_csv("sorting_results.csv")

# Plot the data
plt.figure(figsize=(8,5))
plt.plot(df["Size"], df["Time"], marker='o', linestyle='-', color='b', label="Sorting Time")

# Labels and title
plt.xlabel("Array Size")
plt.ylabel("Time (Microseconds)")
plt.title("Sorting Performance in C++")
plt.legend()
plt.grid()

# Show plot
plt.show()
