from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.cm as mcm
import matplotlib.pyplot as plt
 
 
# Creating dataset
data = np.genfromtxt("points.txt")

colors = np.sin(data[:,0])
x = data[:,1]
y = data[:,2]
z = data[:,3]
id = data[:,0]

# Creating figure
fig = plt.figure(figsize = (15, 15))
ax1 = plt.subplot(2,2,1, projection="3d")
# Creating plot
#axs[0,0] = plt.axes(projection ="3d")
ax1.scatter3D(x, z, y, c=colors, cmap="RdYlGn")
ax1.set_xlabel("X (cm)")
ax1.set_ylabel("Z (cm)")
ax1.set_zlabel("Y (cm)")
plt.title("A simulated ProtoDUNE event")
#plt.tight_layout()

ax2 = plt.subplot(2,2,2)
ax2.scatter(x,y, c=np.sin(id), cmap="RdYlGn")
ax2.set_xlabel("X (cm")
ax2.set_ylabel("Y (cm")

ax3 = plt.subplot(2,2,3)
ax3.scatter(z,x, c=np.sin(id), cmap="RdYlGn")
ax3.set_xlabel("Z (cm")
ax3.set_ylabel("X (cm")

ax4 = plt.subplot(2,2,4)
ax4.scatter(z,y, c=np.sin(id), cmap="RdYlGn")
ax4.set_xlabel("Z (cm")
ax4.set_ylabel("Y (cm")

plt.savefig("points.pdf")
plt.savefig("points.png")
plt.show()
