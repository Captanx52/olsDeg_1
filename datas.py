import numpy as np
import csv

# regDeg1
m = 2
b = 3

# valeus
x_vals = np.random.uniform(-10, 10, 100)

# noising
noise = np.random.normal(0, 1, 100)  
y_vals = m * x_vals + b + noise


with open('data.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    for x, y in zip(x_vals, y_vals):
        writer.writerow([x, y])

print("100 points have been saved to 'data.csv'")
