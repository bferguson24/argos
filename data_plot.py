import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np

# Serial port configuration
COM_PORT = 'COM6'
BAUD_RATE = 115200

# Initialize the serial connection
ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)

# Data storage for plotting
data = []

# Function to update the plot
def update(frame):
    global data
    # Read a line from the serial port
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        try:
            # Convert the line to a float and append to data
            value = float(line)
            data.append(value)
        except ValueError:
            # Skip lines that cannot be converted to float
            pass
    
    # Keep only the last 100 data points
    if len(data) > 100:
        data = data[-100:]
    
    # Update the plot
    ax.clear()
    ax.plot(data, label='Serial Data')
    ax.set_ylim(-10, 10)  # Adjust range based on your data
    ax.set_title("Live Serial Data")
    ax.set_xlabel("Time")
    ax.set_ylabel("Value")
    ax.legend()

# Set up the plot
fig, ax = plt.subplots()
ani = FuncAnimation(fig, update, interval=100)

# Show the plot
try:
    plt.show()
except KeyboardInterrupt:
    print("Exiting...")
finally:
    ser.close()
