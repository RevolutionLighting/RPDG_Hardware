from pyvxi11 import Vxi11, Vxi11Error
import time
period=1
MM = Vxi11(host="192.168.1.70",name="inst0")
MM.open()
MM.write("SENS:VOLT") #Set the meter to measure DC voltage
#print MM.ask("*IDN?") #Set the meter to measure DC current
lastTime=0
i=0
t0=time.time()
while True:
  t=time.time()
  if t>(lastTime+period):
    lastTime=float(t)
    dat=float(MM.ask("READ?"))
    print "%f,%f" % (t-t0,dat)
    i=i+1