from socket import socket #provides access to the BSD socket interface
from sys import argv #command line arguments
from time import sleep #allow the use of time and sleep

class State:
    CurrentContext = None
    def __init__(self, Context):
        self.CurrentContext = Context
    def trigger(self):
        return True

class StateContext:
    state = None
    CurrentState = None
    availableStates = {}

    def setState(self, newstate):
        try:
            self.CurrentState = self.availableStates[newstate]
            self.state = newstate
            self.CurrentState.trigger()
            return True
        except KeyError: #incorrect state key specified
            return False

    def getStateIndex(self):
        return self.state

class Transition:  #Transition class handles any exception errors
    def Closed(self):
        print("Error! Cannot Transition to Closed")
        return False
    def synSent(self):
        print("Error! Cannot Transition to synSent")
        return False
    def Established(self):
        print("Error! Cannot Transition to Established")
        return False
    def finWait1(self):
        print("Error! Cannot Transition to FinWait1")
        return False
    def finWait2(self):
        print("Error! Cannot Transition to FinWait2")
        return False
    def timedWait(self):
        print("Error! Cannot Transition to timedWait")
        return False

class Closed(State, Transition): #This class initiates the closing of a socket
    def __init__(self,Context):
        State.__init__(self,Context)
    def synSent(self):
        self.CurrentContext.setState("SYN_SENT")
    def trigger(self):
        try: 
            self.CurrentContext.socket.close()
            self.CurrentContext.connection_address = 0
            print("[CLOSED]")
            print ("Connection Ended.")
            activeOpen = input("Would you like to find another connection? (y/n)") #asks the client if they want to make another connection
            if activeOpen == "Y" or activeOpen == "y": #if they do...
                self.CurrentContext.synSent() #...transition to synsent
                return True
            else: #otherwise end program
                exit("User said no")

        except:
            return False

class synSent(State, Transition): #sends syn and expects to recieve syn and ack, if it does transition to established
    def __init__(self,Context):
        State.__init__(self,Context)
    def rst(self):
        print("Wrong flag received, resetting...")
        self.CurrentContext.setState("CLOSED")
    def timeout(self):
        print("Wrong flag received, timing out...")
        time.sleep(2)
        self.CurrentContext.setState("CLOSED")
    def Established(self):
        self.CurrentContext.setState("ESTABLISHED")
    def trigger(self):
        print("[SYNSENT]")
        print("Attempting New Connection!")
        try:
            self.CurrentContext.socket = socket()
            self.CurrentContext.socket.connect((self.CurrentContext.host, self.CurrentContext.port))
            self.CurrentContext.connection_address = self.CurrentContext.host
            self.CurrentContext.socket.send("SYN".encode())
            inbound = self.CurrentContext.socket.recv(1024)
            if inbound.decode() == "SYN+ACK":
                print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
                self.CurrentContext.Established()
                return True
            elif inbound.decode() != "SYN+ACK":
                self.CurrentContext.rst()
                return True
            else:
                self.CurrentContext.timeout()
                return False

        except:
            return False
        


class Established(State, Transition): #This class initializes communication between the server and client
    def __init__(self,Context):
        State.__init__(self,Context)
    def finWait1(self):
        self.CurrentContext.setState("FIN_WAIT1")
    def trigger(self): 
        self.CurrentContext.socket.send("ACK".encode())
        print("[ESTABLISHED]")
        print("Connection Established!")
        while True:
            inbound = self.CurrentContext.socket.recv(1024)
            print ("The server said: ", inbound.decode())
            textToServer = input("Please enter what you'd like to send to the server: ")
            if textToServer == "FIN":
                self.CurrentContext.socket.send(textToServer.encode())
                self.CurrentContext.finWait1()
                return True

            self.CurrentContext.socket.send(textToServer.encode())


class finWait1(State, Transition):  #once the client initializes closure this state sends FIN and checks the flag
    def __init__(self,Context):
        State.__init__(self,Context)
    def finWait2(self):
        self.CurrentContext.setState("FIN_WAIT2")
    def trigger(self):
        print("[FINWAIT1]")
        print("Attempting to Sever Connection...")
        self.CurrentContext.socket.send("FIN".encode())
        inbound = self.CurrentContext.socket.recv(1024)
        if inbound.decode() == "ACK":
            print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
            self.CurrentContext.finWait2()
            return True
        else:
            return False


class finWait2(State, Transition): #once the client initializes closure this state sends FIN
    def __init__(self,Context):
        State.__init__(self,Context)
    def timedWait(self):
        self.CurrentContext.setState("TIMED_WAIT")
    def trigger(self):
        print("[FINWAIT2]")
        inbound = self.CurrentContext.socket.recv(1024)
        if inbound.decode() == "FIN":
            print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
            self.CurrentContext.timedWait()
            return True
        else:
            return False
         

class timedWait(State, Transition): #sends one last acknowledgement to the server, waits and transitions to closed
    def __init__(self,Context):
        State.__init__(self,Context)
    def Closed(self):
        self.CurrentContext.setState("CLOSED")
    def trigger(self):
        print("[TIMEDWAIT]")
        self.CurrentContext.socket.send("ACK".encode())
        self.CurrentContext.Closed()


class TCPclient(StateContext,Transition):
    def __init__(self):
        self.host = "127.0.0.1"
        self.port = 5001
        self.connection_address = 0
        self.socket = None
        self.availableStates["CLOSED"] = Closed(self)
        self.availableStates["SYN_SENT"] = synSent(self)
        self.availableStates["ESTABLISHED"] = Established(self)
        self.availableStates["FIN_WAIT1"] = finWait1(self)
        self.availableStates["FIN_WAIT2"] = finWait2(self)
        self.availableStates["TIMED_WAIT"] = timedWait(self)
        self.setState("CLOSED")


    def Closed(self):
        return self.CurrentState.Closed()
    
    def timedWait(self):
        return self.CurrentState.timedWait()

    def finWait1(self):
        return self.CurrentState.finWait1()

    def finWait2(self):
        return self.CurrentState.finWait2()

    def Established(self):
        return self.CurrentState.Established()

    def synSent(self):
        return self.CurrentState.synSent()

    def rst(self):
        return self.CurrentState.rst()

    def timeout(self):
        return self.CurrentState.timeout()

if __name__ == "__main__":
    client = TCPclient() #sets client equal to the TCPclient class
    client.synSent() #calls synSent class

