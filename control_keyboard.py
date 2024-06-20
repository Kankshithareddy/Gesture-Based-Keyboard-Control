import serial
import pyautogui

ser = serial.Serial('COM5', 9600, timeout=1)

while True:
    line = ser.readline().decode('utf-8').strip()
    if line == 'down':
        pyautogui.press('down')
    elif line == 'up':
        pyautogui.press('up')
    elif line == 'left':
        pyautogui.press('left')
    elif line == 'right':
        pyautogui.press('right')