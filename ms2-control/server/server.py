from argparse import ArgumentParser
from logging import info, INFO, basicConfig as basic_config
from mouse import get_position, drag, click, RIGHT
from serial import Serial
from sys import argv

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

def parse_args():
    parser = ArgumentParser()

    parser.add_argument(
        '-v',
        '--verbose',
        default=False,
        action='store_true',
        help=''
    )
    parser.add_argument(
        '-p',
        '--port',
        default='/dev/ttyUSB0',
        nargs=1,
        help=''
    )

    # no arguments provided.
    if not len(argv):
        parser.print_help()
        return None

    return parser.parse_args()

def main(port):
    with Serial(port) as p:
        actions = {
            b'u': lambda: to_up(),
            b'd': lambda: to_down(),
            b'l': lambda: to_left(),
            b'r': lambda: to_right(),
            b'1': lambda: click(),
            b'2': lambda: click(button=RIGHT)
        }

        info('listening port %s...' % port)
        while True:
            data = p.read(size=1)

            info('byte received: %s' % data)
            if data in actions:
                action = actions[data]
                info('running mapped action...')
                action()

if __name__ == "__main__":
    args = parse_args()

    if args:
        if args.verbose:
            basic_config(level=INFO, format='[%(asctime)s] %(message)s')

        main(args.port)
