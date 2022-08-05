import serial
from os import popen

OS = popen("arduino-cli board list | grep tty | awk '{print $1}'").readline()
OS = OS.replace("\n", "")
if OS != "":
    out = popen("lsb_release -a | grep Description | awk '{print $2\" \"$3}'").readline()
    # out = input(">. ")
    # out = popen(out).readline()
    arduino = serial.Serial(OS, 115200)
    arduino.write(out.encode())
    print(OS + ": " + out)
    arduino.close()
    time.sleep(2)
