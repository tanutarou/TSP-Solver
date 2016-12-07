import numpy as np
import matplotlib.pyplot as plt

data = open('./input', 'r')
result = open('./output', 'r')

n = 0
x = []
y = []
for i, line in enumerate(data):
    if i == 0:
        n = int(line)
    elif i <= n+1:
        pass
    else:
        pos = line.split()
        x.append(float(pos[0]))
        y.append(float(pos[1]))

for i, line in enumerate(result):
    if i == 0:
        path = line.split()
        break
path = [int(i) for i in path]

last = len(path) - 1
for i in xrange(last):
    plt.plot([x[path[i]], x[path[i+1]]], [y[path[i]], y[path[i+1]]], "b") 
plt.plot([x[path[last]], x[path[0]]], [y[path[last]], y[path[0]]], "b") 

plt.scatter(x, y) 
plt.show()

