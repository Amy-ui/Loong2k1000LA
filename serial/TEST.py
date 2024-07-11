import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/rfcomm0', 9600,timeout=0.1) 
    ser1=serial.Serial('/dev/ttyUSB0', 9600,timeout=1) 
    #ser2=serial.Serial('/dev/ttyUSB1', 9600,timeout=0.1) 
    if ser.isOpen():
        ser1.write(b"E1X")#使能PWM输出
        print("E1X")
        time.sleep(3)

        #ser2.write(b"P1X")
    else:
        print("error")

    while True:

        ser1.write(b"SP19X")
        print("SP19X")
