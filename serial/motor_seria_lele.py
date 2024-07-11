import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/rfcomm1', 9600,timeout=0.1) 
    ser1=serial.Serial('/dev/ttyUSB0', 115200,timeout=0.1)  
    if ser.isOpen():
        print('串口打开成功')
        ser1.write(b"E1X")#使能PWM输出
        time.sleep(0.01)
        ser1.write(b"E2X")#使能PWM输出
        time.sleep(0.01)
    else:
        print("error")
    if ser1.isOpen():
        while True:
                ser1.write(b"E1X")#使能PWM输出
                time.sleep(0.01)
                ser1.write(b"E2X")#使能PWM输出
                time.sleep(0.01)
                data = ser.readline() # 读取一行数据
                
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
                        print(d_x,d_y)
                        ser1.write(b"SP10X")
                        ser1.write(b"SP20X")
                        if z==0:
                            print("喷水")
                            water="OPX"                    
                            ser1.write(water.encode())
                    elif d_x<0 and d_y<0:
                        print("左转前进")
                        print(d_x,d_y)
                        motor1_start="IS1X"
                        motor1_speed="SP1"+str(speed_y)+"X"
                        motor2_start="IS2X"
                        motor2_speed="SP2"+str(speed_x)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)
                    elif d_x>0 and d_y<0:
                        print("右转前进")
                        print(d_x,d_y)
                        motor1_start="IS1X"
                        motor1_speed="SP1"+str(speed_y)+"X"
                        motor2_start="IS2X"
                        motor2_speed="SP2"+str(speed_x)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)
                    elif d_x<0 and d_y>0:
                        print("左转后退")
                        print(d_x,d_y)
                        motor1_start="IN1X"
                        motor1_speed="SP1"+str(speed_y)+"X"
                        motor2_start="IN2X"
                        motor2_speed="SP2"+str(speed_x)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)
                    elif d_x>0 and d_y>0:
                        print("右转后退")                    
                        print(d_x,d_y)
                        motor1_start="IN1X"
                        motor1_speed="SP1"+str(speed_y)+"X"
                        motor2_start="IN2X"
                        motor2_speed="SP2"+str(speed_x)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)
                    elif d_x<0 and d_y==0:
                        print("左转")                    
                        print(d_x,d_y)
                        motor1_start="IS1X"
                        motor1_speed="SP1"+str(speed_x)+"X"
                        motor2_start="IN2X"
                        motor2_speed="SP2"+str(speed_x)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)
                    elif d_x>0 and d_y==0:
                        print("右转")                    
                        print(d_x,d_y)
                        motor1_start="IN1X"
                        motor1_speed="SP1"+str(speed_x)+"X"
                        motor2_start="IS2X"
                        motor2_speed="SP2"+str(speed_x)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)                  
                    elif d_x==0 and d_y>0:
                        print("后退")                    
                        print(d_x,d_y)
                        motor1_start="IN1X"
                        motor1_speed="SP1"+str(speed_y)+"X"
                        motor2_start="IN2X"
                        motor2_speed="SP2"+str(speed_y)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)  
                    elif d_x==0 and d_y<0:
                        print("前进")                    
                        print(d_x,d_y)
                        motor1_start="IS1X"
                        motor1_speed="SP1"+str(speed_x)+"X"
                        motor2_start="IS2X"
                        motor2_speed="SP2"+str(speed_x)+"X"
                        time.sleep(0.01)
                        ser1.write(motor1_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor1_speed.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_start.encode())
                        time.sleep(0.01)
                        ser1.write(motor2_speed.encode())
                        time.sleep(0.01)                      
                except:
                    print("error")
                    pass
                
