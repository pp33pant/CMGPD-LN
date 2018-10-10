# This document shows how I generate the distance matrix of villages. 
# the la1 and la2 representatively denote the latitude of village 1 and village 2, while the long1 and long2 representatively denote the longitude. 
import numpy as np
import pandas as pd 
def distance(la1,long1,la2,long2):
    la1,long1,la2,long2=map(np.radians,[la1,long1,la2,long2])
    dlong=long1-long2
    dla=la1-la2
    a = np.sin(dla/2)**2 + np.cos(la1) * np.cos(la2) * np.sin(dlong/2)**2
    c = 2 * np.arcsin(np.sqrt(a))
    r = 6371
    distance = c* r *1000
    return distance 

# I record the latitude and longitude of the villages in this dataset (the restricted dataset).
#and then we calculate the distance decay: 

def decay(distance):
    if distance<=1:
        distance=1   #generally, this is the case when the village is itself. 
    decay=(1/(distance**2))
    return decay

# after constructing the distance-decay matrix, we could transfer the distance-decay matrix into the distance weight matrix. 
df=pd.read_csv("distance_matrix.csv")
df1=df
for i in range(0,df.iloc[:,0].size):
    for j in range(0,df.iloc[0,:].size):
        df1[i,j]=df[i,j]*(1/ df.iloc[i,0：].sum())  # to get it weighted: for every array, the sum of the elements is 1. 
df1.to_csv("spatial_weight.csv")


        
    
    
