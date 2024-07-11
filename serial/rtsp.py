import cv2
 
# RTSP URL格式为: rtsp://username:password@ip:port/path
rtsp_url = 'rtsp://192.168.31.183:8554/unicast'
 
# 打开默认的摄像头
cap = cv2.VideoCapture(0)
 
# 设置视频编码器和输出视频的帧率
fourcc = cv2.VideoWriter_fourcc(*'XVID')
frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = 30.0
 
# 创建VideoWriter对象
out = cv2.VideoWriter(rtsp_url, fourcc, fps, (frame_width, frame_height))
 
while(True):
    ret, frame = cap.read()
    if ret:
        # 将帧写入到RTSP服务器
        out.write(frame)
 
        # 显示帧
        cv2.imshow('frame',frame)
 
        # 按'q'退出循环
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break
 
# 释放资源
cap.release()
out.release()
cv2.destroyAllWindows()