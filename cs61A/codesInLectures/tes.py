import pandas as pd
import matplotlib.pyplot as plt
from scipy import stats
# Defining the data from the second table in the image
data_2 = {
    'Im (A)': [0.050, 0.100, 0.150, 0.200, 0.250, 0.300, 0.350, 0.400, 0.450],
    'U1 (mV)': [-1.69, -3.02, -4.31, -5.65, -6.95, -8.27, -9.58, -10.86, -12.13],
    'U2 (mV)': [1.54, 2.82, 4.14, 5.48, 6.78, 8.13, 9.41, 10.69, 11.97],
    'U3 (mV)': [-1.17, -2.45, -3.76, -5.06, -6.38, -7.71, -9.03, -10.23, -11.64],
    'U4 (mV)': [1.12, 2.39, 3.70, 5.00, 6.32, 7.63, 8.92, 10.19, 11.49],
}

# Creating a DataFrame
df_2 = pd.DataFrame(data_2)

# Calculating UH for each row using absolute values
df_2['UH (mV)'] = (df_2['U1 (mV)'].abs() + df_2['U2 (mV)'].abs() + df_2['U3 (mV)'].abs() + df_2['U4 (mV)'].abs()) / 4

# Display the dataframe

# Extract data for the plot
Im = df_2['Im (A)']
UH_2 = df_2['UH (mV)']

# Perform a linear regression for the second table data
slope_2, intercept_2, _, _, _ = stats.linregress(Im, UH_2)

# Create a figure and plot the data points
plt.figure(figsize=(8, 6))
plt.scatter(Im, UH_2, color='blue', label='Data points', marker='x')

# Plot the fitted line for the second table data
plt.plot(Im, intercept_2 + slope_2 * Im, 'r', label=f'Fitted line: y = {slope_2:.2f}x + {intercept_2:.2f}')

# Labeling the axes and title
plt.xlabel('Im (A)')
plt.ylabel('UH (mV)')
plt.title('UH - Im')
plt.legend()

# Display the plot
plt.show()
