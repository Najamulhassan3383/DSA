winning_combination = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0,3,6], [1,4,7], [2,5,8], [0,4,8], [2,4,6]]

initial_state = [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']

look_up_table = {'X': 1, 'O': -1, 'tie': 0}

iteration = 0

def print_board(state):
    print('-------------')
    print('| ' + state[0] + ' | ' + state[1] + ' | ' + state[2] + ' |')
    print('-------------')
    print('| ' + state[3] + ' | ' + state[4] + ' | ' + state[5] + ' |')
    print('-------------')
    print('| ' + state[6] + ' | ' + state[7] + ' | ' + state[8] + ' |')
    print('-------------')
    
def check_winner(state):
    for combination in winning_combination:
        if state[combination[0]] == state[combination[1]] == state[combination[2]] != ' ':
            return look_up_table[state[combination[0]]]
        if ' ' not in state:
            return look_up_table['tie']
        
    return None

def user_turn(state):
    
    while True:
        pos = int(input("enter position for O (0-8):"))
        
        #check if that postion is empty
        if pos >=0 and pos <=8 and state[pos] == ' ':
            state[pos] = 'O'
            break
        else:
            print("invalid position is given")
    return state


def minimax(board,player):
    winner = check_winner(board)
    global iteration
    # The `iteration` variable is used to keep track of the number of iterations or recursive calls
    # made in the `minimax` function. It is initially set to 0 and is incremented by 1 each time the
    # `minimax` function is called. The value of `iteration` can be printed at the end of the game to
    # see how many iterations were performed during the AI's decision-making process.
    iteration  = iteration +1
    if(winner):
        return winner
    
    if(player == 'X'):
        pos = -1
        value = -10000
        for i in range(0,9):
            if board[i] == ' ':
                board[i] = 'X'
                score = minimax(board, 'O')
                board[i] = ' '
                if(score > value):
                    value = score
                    pos = i
        return value
    if player == 'O':
        pos = -1
        value = 10000
        for i in range(0,9):
            if board[i] == ' ':
                board[i] = 'O'
                score = minimax(board, 'X')
                board[i] = ' '
                if(score < value):
                    value = score
                    pos = i
        return value

#deciding move for the AI
def best_move(state):
    state_copy = state.copy()
    value = -100000
    pos = -1
    for i in range(0,9):
        #check if it is an empty state
        if(state_copy[i] == ' '):
            state_copy[i] = "X"
            local_cost = minimax(state_copy,"O")
            state_copy[i] = ' '
            
            if value <= local_cost:
                value = local_cost
                pos = i
                
    return pos
             
    


def game(state):
    while True:
        print_board(state)
        state = user_turn(state)
        print_board(state)
        if(check_winner == 0):
            print("Tie")
            break
        winning_state = (check_winner(state))
        if winning_state == -1:
            print(winning_state)
            print("O wins the game")
            break
        
        ai_pos = best_move(state)
        state[ai_pos] = "X"
        
        print_board(state)
        
        winning_state = (check_winner(state))
        if winning_state == 1:
            print("X has won")
            break
    return None


game(initial_state)
print(iteration)
    