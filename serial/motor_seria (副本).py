import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/rfcomm0', 9600,timeout=0.1) 
    ser1=serial.Serial('/dev/ttyUSB0', 115200,timeout=0.2) 
    #ser2=serial.Serial('/dev/ttyUSB1', 9600,timeout=0.1) 
    if ser.isOpen():
        print('串口打开成功')
        ser1.write(b"E1X")#使能PWM输出
        #ser2.write(b"P1X")
    else:
        print("error")
    while True:
            ser1.write(b"E1X")#使能PWM输出
            data = ser.readline() # 读取一行数据
            
            #ser1.write(b"ok")
            data_use=data.decode()
            data_list=data_use.split("\r")
            try:
                x=int(float(data_list[0]))
                y=int(float(data_list[1]))
                z=int(float(data_list[2]))

                
                d_x=x-11
                d_y=y-11
                speed_x=abs(d_x)
                speed_y=abs(d_y)
                if speed_x > 10: 
                    speed_x = 9
                if speed_y > 10: 
                    speed_y = 9
                if d_x==0 and d_y==0:
                    print("停止")
                    ser1.write(b"SP10X")
                    if z==0:
                        print("喷水")
                elif d_x<0 and d_y<0:
                    print("左转前进")
                    print(d_x,d_y)
                    ser1.write(b"IS1X")
                    #ser2.write(b"IN1X")
                    lele="SP1"+str(speed_x)+"X"
                    ser1.write(lele.encode())
                    #ser2.write(b"SP1"+str(speed_y)+"X")
                elif d_x>0 and d_y<0:
                    print("右转前进")
                    ser1.write(b"IN1X")
                   # ser2.write(b"IS1X")
                    lele="SP1"+str(speed_x)+"X"
                    ser1.write(lele.encode())
                    #ser2.write(b"SP1"+str(speed_y)+"X")
                    print(d_x,d_y)
                elif d_x<0 and d_y>0:
                    print("左转后退")
                    ser1.write(b"IN1X")
                    lele="SP1"+str(speed_x)+"X"
                   # ser2.write(b"IN1X")
                    ser1.write(lele.encode())
                    #ser2.write(b"SP1"+str(speed_y)+"X")
                elif d_x>0 and d_y>0:
                    print("右转后退")
                    ser1.write(b"IN1X")
                    #ser2.write(b"IN1X")
                    lele="SP1"+str(speed_x)+"X"
                    ser1.write(lele.encode())
                    #ser2.write(b"SP1"+str(speed_y)+"X")
                elif d_x<0 and d_y==0:
                    print("左转")
                    ser1.write(b"IS1X")
                    #ser2.write(b"IN1X")
                    ser1.write(b"SP19X")
                    #ser2.write(b"SP19X")
                elif d_x>0 and d_y==0:
                    print("右转")                    
                    print(d_x,d_y)
                    ser1.write(b"IS1X")
                    #ser2.write(b"IN1X")
                    ser1.write(b"SP19X")
                    #ser2.write(b"SP19X")
                elif d_x==0 and d_y>0:
                    print("后退")                    
                    print(d_x,d_y)
                    ser1.write(b"IN1X")
                    #ser2.write(b"IN1X")
                    ser1.write(b"SP19X")
                    #ser2.write(b"SP19X")
                elif d_x==0 and d_y<0:
                    print("前进")                    
                    print(d_x,d_y)
                    ser1.write(b"IS1X")
                    #ser2.write(b"IS1X")
                    ser1.write(b"SP19X")
                    #ser2.write(b"SP19X")
            except:
                print("error")
                pass
              
