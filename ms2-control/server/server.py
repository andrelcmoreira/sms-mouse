from mouse import get_position, drag, click, RIGHT
from serial import Serial

def to_left():
    pos = get_position()
    drag(pos[0], pos[1], pos[0] - 10, pos[1])

def to_right():
    pos = get_position()
    drag(pos[0], pos[1], pos[0] + 10, pos[1])

def to_up():
    pos = get_position()
    drag(pos[0], pos[1], pos[0], pos[1] - 10)

def to_down():
    pos = get_position()
    drag(pos[0], pos[1], pos[0], pos[1] + 10)

with Serial('/dev/ttyUSB0') as port:
    actions = {
        b'u': lambda: to_up(),
        b'd': lambda: to_down(),
        b'l': lambda: to_left(),
        b'r': lambda: to_right(),
        b'1': lambda: click(),
        b'2': lambda: click(button=RIGHT)
    }

    while True:
        data = port.read(size=1)

        if data in actions:
            actions[data]()
