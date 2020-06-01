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

class Transition: #Transition class handles any exception errors
    def Listen(self):
        print("Error! Cannot Transition to listen")
        return False
    def Established(self):
        print("Error! Cannot Transition to established!")
        return False
    def synRec(self):
        print("Error! Cannot Transition to synRec!")
        return False
    def Closed(self):
        print("Error! Cannot Transition to closed!")
        return False
    def closeWait(self):
        print("Error! Cannot Transition to close wait!")
        return False
    def lastAck(self):
        print("Error! Cannot Transition to last ack!")
        return False

class Closed(State, Transition):  #This class initiates the closing of a socket
    def __init__(self,Context):
        State.__init__(self,Context)
    def Listen(self):
        self.CurrentContext.setState("LISTEN")
    def trigger(self):
        try:
            print("[CLOSED]")
            self.CurrentContext.socket.close()
            self.CurrentContext.connection_address = 0
            print ("Connection Ended!")
            self.CurrentContext.Listen()
            return True
        except:
            return False

class Listen(State, Transition): #listens for any connections made on same address/port
    def __init__(self,Context):
        State.__init__(self,Context)
    def trigger(self):
        print("[LISTEN]")
        print("Attempting New Connection!")
        self.CurrentContext.socket = socket()
        try:
            self.CurrentContext.socket.bind((self.CurrentContext.host, self.CurrentContext.port))
            self.CurrentContext.socket.listen(1)
            self.CurrentContext.connection, self.CurrentContext.connection_address = self.CurrentContext.socket.accept()
            self.synAck()
            return True
        except Exception as err:
            print(err)
            exit()
    def synRec(self):
        self.CurrentContext.setState("SYN_RECIEVED")
    def synAck(self):
        inbound = self.CurrentContext.connection.recv(1024)
        if inbound.decode() == "SYN":
            print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
            self.CurrentContext.synRec()
            return True
        else:
            return False

class Syn_Recvd(State, Transition): #once the correct flag has been received this state transitions to the established
    def __init__(self,Context):
        State.__init__(self,Context)
    def trigger(self):
        print("[SYNREC]")
        self.CurrentContext.connection.send("SYN+ACK".encode())
        inbound = self.CurrentContext.connection.recv(1024)
        if inbound.decode() == "ACK":
            print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
            self.CurrentContext.Established()
            return True
        else:
            return False
    def Established(self):
        self.CurrentContext.setState("ESTABLISHED")

class Established(State, Transition): #This class initializes communication between the server and client
    def __init__(self,Context):
        State.__init__(self,Context)
    def closeWait(self):
        self.CurrentContext.setState("CLOSE_WAIT")
    def trigger(self):
        print("[ESTABLISHED]")
        print("Connection Established!")
        while True:
            textToClient = input("Please enter what you'd like to send to the client: ")
            self.CurrentContext.connection.send(textToClient.encode())
            inbound = self.CurrentContext.connection.recv(1024)
            if inbound.decode() == "FIN":
                print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
                self.CurrentContext.closeWait()
                return True
            else:
                print ("The client responded: ", inbound.decode())
                

class Close_Wait(State, Transition): #once the client initializes closure this state sends acknowledgement and checks the flag
    def __init__(self,Context):
        State.__init__(self,Context)   
    def trigger(self):
        print("[CLOSEWAIT]")
        print("Severing Connection!")
        self.CurrentContext.connection.send("ACK".encode())
        inbound = self.CurrentContext.connection.recv(1024)
        if inbound.decode() == "FIN":
            print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
            self.CurrentContext.lastAck()
            return True
        else:
            return False
    def lastAck(self):
        self.CurrentContext.setState("LAST_ACK")

class Last_Ack(State, Transition): #sends one last acknowledgement to the client and transitions to closed
    def __init__(self,Context):
        State.__init__(self,Context)   
    def trigger(self):
        print("[LASTACK]")
        self.CurrentContext.connection.send("FIN".encode())
        inbound = self.CurrentContext.connection.recv(1024)
        if inbound.decode() == "ACK":
            print(inbound.decode() + " received~~~~~~~~~~~~~~~~~~")
            self.CurrentContext.Closed()
            return True
        else:
            return False
    def Closed(self):
        self.CurrentContext.setState("CLOSED")
                   

class TCPserver(StateContext,Transition):
    def __init__(self):
        self.host = ""
        self.port = 5001
        self.connection_address = 0
        self.socket = None
        self.availableStates["CLOSED"] = Closed(self)
        self.availableStates["LISTEN"] = Listen(self)
        self.availableStates["SYN_RECIEVED"] = Syn_Recvd(self)
        self.availableStates["ESTABLISHED"] = Established(self)
        self.availableStates["CLOSE_WAIT"] = Close_Wait(self)
        self.availableStates["LAST_ACK"] = Last_Ack(self)
        self.setState("CLOSED")



    def Closed(self):
        return self.CurrentState.Closed()
    def Listen(self):
        return self.CurrentState.Listen()
    def synRec(self):
        return self.CurrentState.synRec()
    def Established(self):
        return self.CurrentState.Established()
    def lastAck(self):
        return self.CurrentState.lastAck()
    def closeWait(self):
        return self.CurrentState.closeWait()

if __name__ == "__main__":
    server = TCPserver() #sets server equal to the TCPserver class
    server.Listen() #calls Listen class