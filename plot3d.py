from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt
 
 
# Creating dataset
data = np.genfromtxt("points.txt")

colors = np.sin(data[:,0])
x = data[:,1]
y = data[:,2]
z = data[:,3]


# Creating figure
fig = plt.figure(figsize = (15, 10))
# Creating plot
ax = plt.axes(projection ="3d")

ax.scatter3D(x, z, y, c=colors)

ax.set_xlabel("X (cm)")
ax.set_ylabel("Z (cm)")
ax.set_zlabel("Y (cm)")
plt.title("A simulated ProtoDUNE event")
plt.tight_layout()
plt.savefig("points.pdf")
plt.savefig("points.png")
plt.show()
