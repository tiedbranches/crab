import serial
from tkinter import *
import time

#works with increments two steppers.ino

serPort = "COM4"
baudRate = 115200
ser = serial.Serial(serPort, baudRate)
print("Serial port " + serPort + " opened  Baudrate " + str(baudRate))

def inputkey(event):

    print ("pressed", event.char)

    char=(event.char) #assigning pressed character to char variable
    sorter(char)


    charvariable.set(char) #assigning char to StringVar to be displayed

    if char == "*":
        stepperposition = "q"
        print("Sending q directly to stepper")
        ser.write(stepperposition.encode("utf-8"))
    elif char == "-":
        #stepperposition = "<11."
        stepperposition = "a"
        print("Sending a directly to stepper")
        ser.write(stepperposition.encode("utf-8"))
    else:
        stepperposition = "<" + char + "."
        stepperposition = char
        print("Sending to stepper: ", stepperposition)
        ser.write(stepperposition.encode('utf-8'))

def gotozero():
    global vm1pos, vm2pos, vm3pos, hm1pos, hm2pos, hm3pos
    zero = "<0,0,0,0,0,0>"
    ser.write(zero.encode("utf-8"))
    vm1pos=vm2pos=vm3pos=hm1pos=hm2pos=hm3pos=0
    vmotor1.set("Vmotor1: " + str(vm1pos))
    vmotor2.set("Vmotor2: " + str(vm2pos))
    vmotor3.set("Vmotor3: " + str(vm3pos))
    hmotor1.set("Hmotor1: " + str(hm1pos))
    hmotor2.set("Hmotor2: " + str(hm2pos))
    hmotor3.set("Hmotor3: " + str(hm3pos))


def zeroing():
    global vm1pos, vm2pos, vm3pos, hm1pos, hm2pos, hm3pos

    zeroMarker = "<0)"
    ser.write(zeroMarker.encode("utf-8"))
    time.sleep(0.5)
    vm1pos = vm2pos = vm3pos = hm1pos = hm2pos = hm3pos = 0
    position0 = "<0,0,0,0,0,0>"
    #ser.write(position0.encode("utf-8"))

    vmotor1.set("Vmotor1: " + str(vm1pos))
    vmotor2.set("Vmotor2: " + str(vm2pos))
    vmotor3.set("Vmotor3: " + str(vm3pos))
    hmotor1.set("Hmotor1: " + str(hm1pos))
    hmotor2.set("Hmotor2: " + str(hm2pos))
    hmotor3.set("Hmotor2: " + str(hm3pos))
    

def poscaller(whichpos):
    global vm1pos, vm2pos, vm3pos, hm1pos, hm2pos, hm3pos
    pos = posrep(whichpos)

    position = "<" + str(pos[0]) + "," + str(pos[1]) + "," + str(pos[2]) + "," + str(pos[3]) + "," + str(pos[4]) + str(pos[5]) + ">"
    print(position)
    ser.write(position.encode("utf-8"))

    vm1pos = pos[0]; vm2pos = pos[1]; vm3pos = pos[2]; hm1pos = pos[3]; hm2pos = pos[4]; hm3pos = pos[5]

    vmotor1.set("Vmotor1: " + str(vm1pos))
    vmotor2.set("Vmotor2: " + str(vm2pos))
    vmotor3.set("Vmotor3: " + str(vm3pos))
    hmotor1.set("Hmotor1: " + str(hm1pos))
    hmotor2.set("Hmotor2: " + str(hm2pos))
    hmotor3.set("Hmotor3: " + str(hm3pos))



def sorter(inchar):
    global vm1pos, vm2pos, vm3pos, hm1pos, hm2pos, hm3pos

    if inchar == "7":
        vm1pos += 100
        vmotor1.set("Vmotor1: " + str(vm1pos))

    elif inchar == "4":
        vm1pos -= 100
        vmotor1.set("Vmotor1: " + str(vm1pos))

    elif inchar == "8":
        vm2pos += 100
        vmotor2.set("Vmotor2: " + str(vm2pos))

    elif inchar == "5":
        vm2pos -= 100
        vmotor2.set("Vmotor2: " + str(vm2pos))

    elif inchar == "9":
        vm3pos += 100
        vmotor3.set("Vmotor3: " + str(vm3pos))

    elif inchar == "6":
        vm3pos -= 100
        vmotor3.set("Vmotor3: " + str(vm3pos))

    elif inchar == "2":
        hm1pos += 100
        hmotor1.set("Hmotor1: " + str(hm1pos))

    elif inchar == "3":
        hm1pos -= 100
        hmotor1.set("Hmotor1: " + str(hm1pos))

    elif inchar == "1":
        hm2pos += 100
        hmotor2.set("Hmotor2: " + str(hm2pos))

    elif inchar == "0":
        hm2pos -= 100
        hmotor2.set("Hmotor2: " + str(hm2pos))

    elif inchar == "*":
        hm3pos -= 100
        hmotor3.set("Hmotor3: " + str(hm3pos))

    elif inchar == "-":
        hm3pos -= 100
        hmotor3.set("Hmotor3: " + str(hm3pos))

def possetter(whichpos):
    global pos1,pos2,pos3,pos4

    pos = posrep(whichpos)
    pos[0] = vm1pos; pos[1] = vm2pos; pos[2] = vm3pos; pos[3] = hm1pos ; pos[4] = hm2pos; pos[5] = hm3pos


###############################################################

pos1 = [-6700,3000,-4900,0,0]
pos2 = [-700,3700,-3400,0,0]
pos3 = [6400,3000,1300,0,0]
pos4 = [7000,-3500,1300,0,0]
pos45 = [-6700,6000,-4900,0,0]
pos9 = [-6300, 7200, 4500, 0, 0]
pos11 = [0,6000,0,0,0]
###############################################################

def posrep(pos):
    if pos == 1:
        return pos1
    elif pos == 2:
        return pos2
    elif pos == 3:
        return pos3
    elif pos == 4:
        return pos4
    elif pos == 45:
        return pos45
    elif pos== 9:
        return pos9
    elif pos== 11:
        return pos11


def mover():
    pos1 = posrep(1)
    position1 = "<" + str(pos1[0]) + "," + str(pos1[1]) + "," + str(pos1[2]) + "," + str(pos1[3]) + "," + str(pos1[4]) + ">"
    pos2 = posrep(2)
    position2 = "<" + str(pos2[0]) + "," + str(pos2[1]) + "," + str(pos2[2]) + "," + str(pos2[3]) + "," + str(pos2[4]) + ">"
    pos3 = posrep(3)
    position3 = "<" + str(pos3[0]) + "," + str(pos3[1]) + "," + str(pos3[2]) + "," + str(pos3[3]) + "," + str(pos3[4]) + ">"
    pos4 = posrep(4)
    position4 = "<" + str(pos4[0]) + "," + str(pos4[1]) + "," + str(pos4[2]) + "," + str(pos4[3]) + "," + str(pos4[4]) + ">"

    position0 = "<0,0,0,0,0,0>"

    for i in range(1):
        stepperposition = position1
        ser.write(stepperposition.encode('utf-8'))
        print("Position1: ", stepperposition)

        time.sleep(5)

        stepperposition = position2
        ser.write(stepperposition.encode('utf-8'))

        time.sleep(3)

        stepperposition = position3
        ser.write(stepperposition.encode('utf-8'))

        time.sleep(4)

        stepperposition = position4
        ser.write(stepperposition.encode('utf-8'))

        time.sleep(3)


    ser.write(position0.encode('utf-8'))

def move():


    for i in range(1):

        time.sleep(4)
        poscaller(11)
        time.sleep(6)


        """poscaller(2)
        time.sleep(3)

        poscaller(3)
        time.sleep(6)

        poscaller(4)
        time.sleep(4.5)

        poscaller(45)
        time.sleep(6.7)"""


    gotozero()

def snapshot():

    image_name = str(vm1pos) + "," + str(vm2pos) + "," + str(vm3pos)

root = Tk()
canvas = Canvas(root)
#canvas.grid()
canvas.focus_set()
canvas.bind("<Key>", inputkey)

#Zero variables Button
b = Button(root, bg = "#fc6949", text="zero variables", command=zeroing)
b.grid(row=0,column=0, sticky=W+E)

b.focus_set()
b.bind("<Key>",inputkey)

#Going to zero Button
b0 = Button(root, bg = "#fc6949", text="go to zero", command=gotozero)
b0.grid(row=0,column=1, sticky=W+E)

#Out of the way Button
bway = Button(root, bg = "#fc6949", text="out of way", command= lambda : poscaller(9))
bway.grid(row=0,column=3, sticky=W+E)

#pos1 Button
b1 = Button(root, bg = "#a04836", text="Position 1", command = lambda: poscaller(11))
b1.grid(row=1,column=0, sticky=N+S+W+E)

b1s=Button(root, bg = "#de5c5c", text="Set Position 1", command= lambda:possetter(1)).grid(row=3,column=0, sticky=W+E)

#pos2 Button
b2 = Button(root, bg = "#a04836", text="Position 2", command= lambda:poscaller(2))
b2.grid(row=1,column=1, sticky=W+E, rowspan = 2)

b2s=Button(root, bg = "#de5c5c", text="Set Position 2", command= lambda:possetter(2)).grid(row=3,column=1, sticky=W+E)

#pos3 Button
b3 = Button(root, bg = "#a04836", text="Position 3", command= lambda:poscaller(3))
b3.grid(row=1,column=2, sticky=W+E, rowspan = 2)

b3s=Button(root, bg = "#de5c5c", text="Set Position 3", command= lambda : possetter(3)).grid(row=3,column=2, sticky=W+E)

#pos4 Button
b4 = Button(root, bg = "#a04836", text="Position 4", command= lambda : poscaller(4))
b4.grid(row=1,column=3, sticky=W+E, rowspan = 2)

b4s=Button(root, bg = "#de5c5c", text="Set Position 4", command= lambda : possetter(4)).grid(row=3,column=3, sticky=W+E)



#Mover Button
m = Button(root, bg = "#fc694b", text="move", command=move)
m.grid(row=0, column=2, sticky=W+E,columnspan=1)

"""JUST PRESSED"""
charvariable=StringVar()
charvariable.set("none")

"""Initialising motor position variables"""
vm1pos = vm2pos = vm3pos = hm1pos = hm2pos = hm3pos = 0

vmotor1 = StringVar()
vmotor1.set("Vmotor1: " + str(vm1pos))
vmotor2 = StringVar()
vmotor2.set("Vmotor2: " + str(vm2pos))
vmotor3 = StringVar()
vmotor3.set("Vmotor3: " + str(vm3pos))
hmotor1 = StringVar()
hmotor1.set("Hmotor1: " + str(hm1pos))
hmotor2 = StringVar()
hmotor2.set("Hmotor2: " + str(hm2pos))
hmotor3 = StringVar()
hmotor3.set("Hmotor3: "+ str(hm3pos))

justpressed = Label(root, textvariable = charvariable,font=("Courier",14))
justpressed.grid()

"""LABELS FOR MOTOR POSITIONS"""

vmotor1_l = Label(root, text = "vmotor1", textvariable = vmotor1,font=("Courier",14))
vmotor1_l.grid()
vmotor2_l = Label(root, text = "vmotor2", textvariable = vmotor2,font=("Courier",14))
vmotor2_l.grid()
vmotor3_l = Label(root, text = "vmotor3", textvariable = vmotor3,font=("Courier",14))
vmotor3_l.grid()
hmotor1_l = Label(root, text = "hmotor1", textvariable = hmotor1,font=("Courier",14))
hmotor1_l.grid()
hmotor2_l = Label(root, text = "hmotor2", textvariable = hmotor2,font=("Courier",14))
hmotor2_l.grid()
hmotor3_l =Label(root, text = "hmotor3", textvariable =hmotor3, font=("Courier",14))





while True:


    root.update()


    #print("STEPPERPOSITION: ", stepperposition)
    #ser.write(stepperposition.encode('utf-8'))
