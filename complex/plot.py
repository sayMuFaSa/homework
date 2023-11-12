import matplotlib.pyplot as plt

x = float(input())
y = float(input())

fig, ax = plt.subplots()



# Draw an arrow from (0, 0) to (x, y)
ax.arrow(0, 0, x, y, head_width=0.05, head_length=0.1, fc='blue', ec='blue')

ax.set_xlabel('Real')
ax.set_ylabel('Imaginary')

# Set axis limits
# ax.set_xlim(0, 10)
# ax.set_ylim(0, 10)

# Show the plot
plt.show()
