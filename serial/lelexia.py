import serial

if __name__ == '__main__':
    ser = serial.Serial('/dev/rfcomm0', 9600,timeout=0.1) # 打开串口，COM1是串口名，9600是波特率
    if ser.isOpen():
        print('串口打开成功')
        print("P1X")#使能PWM输出
    else:
        print("error")
    while True:
        
            data = ser.readline() # 读取一行数据
            
            data_use=data.decode()
            data_list=data_use.split("\r")
            try:
                x=int(float(data_list[0]))
                y=int(float(data_list[1]))
                z=int(float(data_list[2]))

            
                d_x=x-12
                d_y=y-12
                if d_x==0 and d_y==0:
                    print("停止")
                    if z==0:
                        print("喷水")
                elif d_x<0 and d_y<0:
                    print("左转前进")
                    print(d_x,d_y)
                elif d_x>0 and d_y<0:
                    print("右转前进")
                    print(d_x,d_y)
                elif d_x<0 and d_y>0:
                    print("左转后退")
                    print(d_x,d_y)
                elif d_x>0 and d_y>0:
                    print("右转后退")
                    print(d_x,d_y)
                elif d_x<0 and d_y==0:
                    print("左转")
                    print(d_x,d_y)
                elif d_x>0 and d_y==0:
                    print("右转")                    
                    print(d_x,d_y)
                elif d_x==0 and d_y>0:
                    print("后退")                    
                    print(d_x,d_y)
                elif d_x==0 and d_y<0:
                    print("前进")                    
                    print(d_x,d_y)
            except:
                pass

