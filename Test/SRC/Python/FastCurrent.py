currentRange=0.001
sampleTime=.00002
numSamples=50000

from pyvxi11 import Vxi11, Vxi11Error
import time
MM = Vxi11(host="192.168.1.21",name="inst0")
MM.open()
MM.write("SENS:CURR") #Set the meter to measure DC current
MM.write("SENS:CURR:RANGE %f"%currentRange) #Set the meter to its 100uA range
MM.write("SENS:CURR:APER %f"%sampleTime) #Measurement aperture 20us
MM.write("SENS:CURR:ZERO:AUTO ONCE") #Zero the meter, then disable autoranging, necessary for fastest measurement speed
MM.write("SAMP:SOUR TIM") #Set the sampler to run off the sample timer
MM.write("SAMP:TIM %f"%sampleTime) #Set the sample timer to 20us
MM.write("SAMP:COUN %d"%numSamples) #Set the meter to capture 1000 samples
MM.write("TRIG:COUN 1") #Only trigger once
MM.write("TRIG:SOUR IMM") #But trigger immediately on init
MM.write("INIT") #Begin the measurement

t0=time.time()
res=int(MM.ask("STAT:OPER:COND?"))
while (res&16)>0:
  res=int(MM.ask("STAT:OPER:COND?"))
tEnd=time.time()-t0
print "Elapsed time =",tEnd
dat=MM.ask("FETC?")
print dat[-15:]
d2=dat.split(',')
print len(d2)
for reading in d2:
  print reading