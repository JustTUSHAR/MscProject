import numpy as np
import matplotlib.pyplot as plt

#x=[10,20,30,40,50,60,70,80,90,100]
#y=[0.979,0.981,1.014,0.999,0.995,0.998,0.991,0.996,1.003,1]
x=[10,20,30,40,80,100]
y=[0.979,0.981,1.014,0.999,0.996,1]
plt.plot(x,y,'g^')
font1 = {'family':'serif','color':'blue','size':20}
plt.xlabel("Centraility",fontdict = font1)
plt.ylabel("$R_{AA}$",fontdict = font1)

plt.axhline(y=1, color='r', linestyle='-')
plt.legend(['$R_{AA}$ points','Reference line'])
plt.ylim(0, 2)
plt.show()
