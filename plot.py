import matplotlib.pyplot as plt
import numpy as np
import csv


points = []
with open('data.csv', 'r') as file:
    reader = csv.reader(file)
    for line in reader:
        x, y = map(float, line)  
        points.append((x, y))


points = np.array(points)
x_vals = points[:, 0]
y_vals = points[:, 1]


m = 2.01255  
b =  3.0641 


y_pred = m * x_vals + b


plt.scatter(x_vals, y_vals, color='blue', label='Data points')
plt.plot(x_vals, y_pred, color='red', label=f'Linear Regression: y = {m}x + {b}')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Linear Regression with OLS')
plt.legend()
plt.show()
