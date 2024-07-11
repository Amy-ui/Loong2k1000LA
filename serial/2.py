import cv2

# 创建一个VideoCapture对象
cap = cv2.VideoCapture(0)

while True:
    # 读取一帧图像
    ret, frame = cap.read()

    # 如果读取成功，显示图像
    if ret:
        cv2.imshow('frame', frame)

    # 如果按下'q'键，退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放摄像头资源
cap.release()

# 关闭所有窗口
cv2.destroyAllWindows()
