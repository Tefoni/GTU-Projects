import random

def generate(row,column):
    board = []
    cell_value = 0
    for i in range(row):
        board.append([])
        for j in range(column):
            board[i].append(cell_value)
            cell_value+=1
    
    return board 


def shuffle(board, times=20):
    moves = "\0" * times
    counter = 0
    copyOf_times = times

    while(times>0):
        print(move_random(board),end=" ") # yapılan hareketi returnleyemedim stringe char atamayı bulamadım
        times-=1
        counter+=1

        if(times==0 and is_solved(board)):   
            times = copyOf_times
            counter = 0
    
    print("\n")
    return moves


def print_board(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            print(board[i][j],end="\t")

        print("\n")
    
    return None


def reset(board):
    cell_value = 0

    for i in range(len(board)):
        for j in range(len(board[i])):
            board[i][j]= cell_value
            cell_value+=1

    return None


def is_valid(board):
    counter = ( len(board) * len(board[0]) ) -1

    while(counter!=-1):
        copy_counter = counter
        for i in range(len(board)):
            for j in range(len(board[0])):
                if(board[i][j]==counter):   counter-=1
        
        if(counter==copy_counter):  return False # It means i could not find right element

    return True

def is_solved(board):
    cell_value = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if(board[i][j]!= cell_value):
                return False

            cell_value+=1
    
    return True


def get_board_size(board):
    row = len(board) 
    column = len(board[0])
    return (row,column)


def move_right(board):
    rowOf_zero = 0
    columnOf_zero = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if(board[i][j]==0):
                rowOf_zero = i
                columnOf_zero = j
    
    if(columnOf_zero < len(board[0])-1):
        temp = board[rowOf_zero][columnOf_zero+1]
        board[rowOf_zero][columnOf_zero+1] = 0
        board[rowOf_zero][columnOf_zero] = temp
        return 1
    else :
        return 0


def move_left(board):
    rowOf_zero = 0
    columnOf_zero = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if(board[i][j]==0):
                rowOf_zero = i
                columnOf_zero = j
    
    if(columnOf_zero > 0):
        temp = board[rowOf_zero][columnOf_zero-1]
        board[rowOf_zero][columnOf_zero-1] = 0
        board[rowOf_zero][columnOf_zero] = temp
        return 1
    else :
        return 0


def move_up(board):
    rowOf_zero = 0
    columnOf_zero = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if(board[i][j]==0):
                rowOf_zero = i
                columnOf_zero = j
    
    if(rowOf_zero > 0):
        temp = board[rowOf_zero-1][columnOf_zero]
        board[rowOf_zero-1][columnOf_zero] = 0
        board[rowOf_zero][columnOf_zero] = temp
        return 1
    else :
        return 0


def move_down(board):
    rowOf_zero = 0
    columnOf_zero = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if(board[i][j]==0):
                rowOf_zero = i
                columnOf_zero = j
    
    if(rowOf_zero < len(board)-1):
        temp = board[rowOf_zero+1][columnOf_zero]
        board[rowOf_zero+1][columnOf_zero] = 0
        board[rowOf_zero][columnOf_zero] = temp
        return 1
    else :
        return 0    


def move_random(board):
    did_movement_happen=0# 1 means movement happened , 0 means movement not happened
    
    while(did_movement_happen!=1):#Do loop if movement not happened
        random_direction = random.randint(1,4)

        if(random_direction==1):#Right movement
            did_movement_happen = move_right(board)
            if(did_movement_happen==1): return "R"

        elif(random_direction==2):#Left movement
            did_movement_happen = move_left(board)
            if(did_movement_happen==1): return "L"

        elif(random_direction==3):#Up movement
            did_movement_happen = move_up(board)
            if(did_movement_happen==1): return "U"

        elif(random_direction==4):#Down movement
            did_movement_happen = move_down(board)
            if(did_movement_happen==1): return "D"


def move(board,moves):
    counter = 0
    for step in moves:
        did_movement_happen = 0

        if(step == 'r' or step =='R'):
            did_movement_happen = move_right(board)
            if(did_movement_happen==1): counter+=1

        if(step == 'l' or step =='L'):
            did_movement_happen = move_left(board)
            if(did_movement_happen==1): counter+=1

        if(step == 'u' or step =='U'):
            did_movement_happen = move_up(board)
            if(did_movement_happen==1): counter+=1

        if(step == 'd' or step =='D'):
            did_movement_happen = move_down(board)
            if(did_movement_happen==1): counter+=1

    return counter


def play(board,moves):
    counter = 0

    if(is_valid(board)==False):    return -2
    if(is_solved(board)):   return 0

    for step in moves:
        did_movement_happen = 0

        if(step == 'r' or step =='R'):
            did_movement_happen = move_right(board)
            if(did_movement_happen==1): counter+=1

        if(step == 'l' or step =='L'):
            did_movement_happen = move_left(board)
            if(did_movement_happen==1): counter+=1

        if(step == 'u' or step =='U'):
            did_movement_happen = move_up(board)
            if(did_movement_happen==1): counter+=1

        if(step == 'd' or step =='D'):
            did_movement_happen = move_down(board)
            if(did_movement_happen==1): counter+=1

    if(is_solved(board)):   return counter
    else : return -1


def play_interactive(board=None):
    step_counter = 0
    step_input = "\0"
    if(board==None):
        print("Enter row:",end=" ")
        row = int(input())
        print("Enter column:",end=" ")
        column = int(input())
        board = generate(row,column)
        shuffle(board)#burda çözülmüş board gelemez ona göre ayarladım ondan kontrol etmiyorm tekrar

    if(is_valid(board)==False): return ('', -2)
    print("Current board is:")
    print_board(board)

    while(is_solved(board)!=True and step_input!="Q"):
        did_movement_happen = 0
        print("Where do you want to move:",end=" ")
        step_input = str(input())

        if(step_input == 'r' or step_input =='R'):
            did_movement_happen = move_right(board)
            if(did_movement_happen==1): step_counter+=1

        elif(step_input == 'l' or step_input =='L'):
            did_movement_happen = move_left(board)
            if(did_movement_happen==1): step_counter+=1

        elif(step_input == 'u' or step_input =='U'):
            did_movement_happen = move_up(board)
            if(did_movement_happen==1): step_counter+=1

        elif(step_input == 'd' or step_input =='D'):
            did_movement_happen = move_down(board)
            if(did_movement_happen==1): step_counter+=1
        
        elif(step_input == 'm' or step_input =='M'):
            move_random(board)
            step_counter+=1
        elif(step_input=='q' or step_input== 'Q'):  print("Exiting.")

        else:   print("Wrong move.")

        print("After move apply,Current board is:")
        print_board(board)

    if(is_solved(board)==False):    return -1 #move listi nasıl returnlicem
    elif(is_solved(board)==True):
        print("Congrats! You solved the board in ",step_counter," moves.")
        return step_counter #move listi nasıl returnlicem
        

#def rotate(board):
#    new_board = []
#
#    for i in range(len(board[0])):
#        new_board.append([])
#        for j in range(len(board)):
#            new_board[i].append(0)
#
#    for i in range(len(new_board)):
#        for j in range(len(new_board[0])):
#            print(1)
#    return new_board


board = generate(5,4)
reset(board)
#print(shuffle(board))
#print_board(board)
#print(is_valid(board))
play_interactive()





