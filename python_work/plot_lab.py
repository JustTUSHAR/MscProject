import numpy as np
import matplotlib.pyplot as plt

#x=[10,20,30,40,50,60,70,80,90,100]
#y=[0.979,0.981,1.014,0.999,0.995,0.998,0.991,0.996,1.003,1]
#x=[10,40,50,60,80]
#y=[1.19,0.67,1.02,1.17,0.82]


#my_xticks = ['0%-20%','20%-40%','40%-80%','80%-100%']
my_xticks = ['0%-20%','20%-40%','40%-80%']
#x=[1,2,3,4]
x=[1,2,3]
y1=[0.5081,0.1636,0.1901]
y2=[0.3198,0.0332,0.0446]
y3=[0.828,0.1968,0.2347]
#y=[1.99,0.202,1.529,0.041]
#y=[0.066,0.103,0.235,0.070]
#x=[10,20,30,40,80,100]
#y=[0.979,0.981,1.014,0.999,0.996,1]
plt.plot(x,y1,'g^')
plt.plot(x,y2,'r^')
plt.plot(x,y3,'b^')

font1 = {'family':'serif','color':'blue','size':20}
plt.xlabel("Centraility",fontdict = font1)
plt.xticks(x, my_xticks)
plt.ylabel("$R_{AA}$ for W bosons",fontdict = font1)
plt.ylim(0, 2)
plt.axhline(y=1, color='r', linestyle='-',marker='D')
plt.legend(['$R_{AA}$ for $W^{-}$','$R_{AA}$ for $W^{+}$','$R_{AA}$ for $W^{-}$+$W^{+}$','Reference line'])
plt.show()
