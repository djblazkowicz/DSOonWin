import socket
import re
class EMBEDDED_UDPCLIENT():
    UDP_IP = "127.0.0.1"
    UDP_PORT = 50000
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP

    def get_list(self, _unused_, max_time):
        MESSAGE = str(max_time)
        #for some reason DSO will have multiple white spaces between the useful data..
        MESSAGE = re.sub('\s+',' ',MESSAGE)

        self.sock.sendto(bytes(MESSAGE, "utf-8"), (self.UDP_IP, self.UDP_PORT))
        print("[PYTHON] " + MESSAGE)
