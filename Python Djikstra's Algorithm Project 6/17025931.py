infinity = 1000000
# set infinity to one million 
invalid_node = -1
# set invalid node to minus one 

class Node:
    previous = invalid_node
    # set previous equal to minus one 
    distancefromsource = infinity
    # set distancefromsource to one million 
    visited = False
    # set default for visited to false 

class Dijkstra:

    def __init__(self): # define intialise function for class 
        '''initialise class'''
        self.startnode = 0
        self.endnode = 0
        self.network = []
        self.nodetable = []
        self.network_populated = False
        self.currentnode = 0

    def populate_network(self, filename): # define populate network function with the two parameters self and filename
        '''populate network data structure'''
        self.network_populated = False # declares self.network is not populated
        # load in file contents line by line
        try:
            file = open(filename, 'r') # tries to open the file to read
        except IOError:
            print("Network file does not exist!") # if the file can't be found then exception error message shows
            return
        for line in file: # for every line in the file
            self.network.append(list(map(int, line.strip().split(',')))) # splits the file up and strips certain characters
        self.network_populated = True # set network to populated
        file.close() # closes the file so no editing occurs
        
    def parse_route(self,filename): # method that parses the route text file and..
        self.route_populated = False # ..sets the route variables
        try:
            routefile = open(filename, 'r') # tried to open the file to read
        except IOError:
            print("Route file does not exist!") # if the file can't be found then exception erro message shows
            return
        for line in routefile: # for every line in the file
            self.route = line.strip().split('>') # splits the file up and seperates each node identifier by stripping >
        self.startnode = (ord(self.route[0]) - 65) # set variables based on the route file 
        self.currentnode = self.startnode # sets currentnode equal to startnode to begin
        self.endnode = (ord(self.route[1]) - 65) #set variables based on route file
        self.route_populated = True # sets route_populated to true
        routefile.close() #closes routefile
        
    def populate_node_table(self): 
        self.nodetable_populated = False #sets nodetable_populated to false as fedault meaning its empty
        for line in self.network: #for every line in the network 
            self.nodetable.append(Node()) # append a node everytime
        self.nodetable[self.startnode].distancefromsource = 0 # as we're on the source node we are 0 distance away from source
        self.nodetable[self.startnode].visited = True # set the node to visited so we don't go back
        self.nodetable_populated = True # set nodetable_populated to true meaning it contains things
    
    def return_near_neighbour(self):
        output_list = [] # declare empty array output_list
        for index, line in enumerate(self.network): # for every line and index in self.network
            if (self.network[self.currentnode][index]>0 and self.nodetable[index].visited==False):#only flags if they haven't been visited and are nearby
                output_list.append(index)#appends to list to be used
        return output_list

    def calculate_tentative (self):
        neighbour = self.return_near_neighbour() #declares neighbour equal to near_neighbour for ease of use
        for index,line in enumerate(neighbour):  #for every line and index is
            newdist = self.nodetable[self.currentnode].distancefromsource + self.network[self.currentnode][neighbour[index]] #calculates newdist by adding the current node and new node
            if self.nodetable[neighbour[index]].distancefromsource > newdist: # is newdist smaller?
                self.nodetable[neighbour[index]].distancefromsource = newdist #make distancefrom source equal to newdist if it is
                self.nodetable[neighbour[index]].previous = self.currentnode #set previous to current node

    def determine_next_node (self):
        lowest = infinity #set lowest equal to infinity
        lowest_index = invalid_node #set lowest_index equal to invalid_node
        self.nodetable[self.currentnode].visited = True #sets current node to visited
        for index, line in enumerate(self.nodetable): #checks every node
            if self.nodetable[index].distancefromsource < lowest and self.nodetable[index].visited == False: #finds lowest distancefromsource to be next current node
                lowest = self.nodetable[index].distancefromsource #set lowest now equal to distancefromsource
                lowest_index = index #set lowest_index now to index
        if lowest_index != invalid_node: #if lowest_index != invalid_node
            self.currentnode = lowest_index #set currentnode equal to lowest_index
            
             #sets current node to lowest distance
            print("New node is",self.currentnode,"with distance of",self.nodetable[self.currentnode].previous) #prints to keep user informed
        else:
            print("There are no possible paths left") #prints to keep user informed
            return False
            
        
    def calculate_shortest_path(self):
        while self.currentnode != self.endnode:#while current node is not endnode
            self.calculate_tentative() # call calculate tenatative
            if self.determine_next_node() == False: #if determine next node returns false
                return False #return false

    def return_shortest_path(self):
        route1 =[] #declare route1 with empty array
        if self.calculate_shortest_path() == False: #if calculateshortestpath returns false
            return #return false
        dist = self.nodetable[self.currentnode].distancefromsource #set dist as equal to distancefromsource
        while self.currentnode != self.startnode: #while currentnode doesnt equal the startnode
            route1.insert(0,chr(self.currentnode+65)) #insert node into route1
            self.currentnode = self.nodetable[self.currentnode].previous#lbuilds path by looping backawards
        route1.insert(0,chr(self.startnode+65))#adds startnode to path
        print(route1) #prints the route
        print("distance from the start is: ",dist) #prints distance

if __name__ == '__main__':
    Djik = Dijkstra() #make Djik equal to Djikstra method for ease of use
    Djik.populate_network("network.txt") #call populate network with network txt
    Djik.parse_route("route.txt") #call parse route with route.txt
    Djik.populate_node_table() #call populate node table
    print("Network Table:") #print nodetable title
    for line in Djik.network:
        print(line) #print every line in network
    print(f"Startnode = {Djik.startnode}, Endnode = {Djik.endnode}") #print start and endnode
    Djik.calculate_shortest_path() #call calculate shortest path
    Djik.return_shortest_path() #call return shortest path
    

