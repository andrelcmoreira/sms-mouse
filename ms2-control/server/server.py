from mouse import get_position, drag, click, RIGHT, LEFT
from serial import Serial

def to_left():
    print(to_left.__name__)

    pos = get_position()
    drag(pos[0], pos[1], pos[0] - 10, pos[1])

def to_right():
    print(to_right.__name__)

    pos = get_position()
    drag(pos[0], pos[1], pos[0] + 10, pos[1])

def to_up():
    print(to_up.__name__)

    pos = get_position()
    drag(pos[0], pos[1], pos[0], pos[1] - 10)

def to_down():
    print(to_down.__name__)

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
