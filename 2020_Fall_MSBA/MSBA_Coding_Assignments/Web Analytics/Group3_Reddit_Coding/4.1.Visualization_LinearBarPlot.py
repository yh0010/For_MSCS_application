import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
#I use the seaborn and matplotlib to create the linear + bar plot

df = pd.read_csv('201509-202011_polarity_scores.csv')

#to convert the dataframe that's suitable to graph
plotting_df = df.melt(id_vars="date", var_name="Polarity", value_name="number of comments")

#print(plotting_df)

sns.set(style='darkgrid', context='talk', palette='Set2')
fig, ax = plt.subplots(figsize=(30, 12))
plt.xticks(rotation=45)
sns.barplot(x="date", y="number of comments", ax=ax, hue="Polarity", data=plotting_df)
sns.lineplot(data=plotting_df, x="date", y="number of comments", hue="Polarity", style="Polarity", markers=True, dashes = False)
plt.show()
