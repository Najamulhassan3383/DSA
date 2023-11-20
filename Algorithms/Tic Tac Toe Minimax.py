Winning_combinations = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[6,4,2],[0,4,8]]

Initial_board = ['-', '-', '-',
                '-', '-', '-',
                '-', '-', '-']


def print_board(board):
    for i in range(0, 9, 3):
        print(board[i]," | ", board[i+1]," | ", board[i+2]," | ")
    
        
        
def checkWin(board):
    for combination in Winning_combinations:
        if board[combination[0]] == board[combination[1]] == board[combination[2]] != '-':
            return True
    return False

def neighbours(board, player):
    boards = []
    for i in range(9):
        if board[i] == '-':
            new_board = board.copy()
            new_board[i] = player
            boards.append(new_board)
    return boards


def minimax(board, depth, alpha, beta, player):
    result = checkWin(board)
    if result:
        return result
    if '-' not in board:
        return 0
    
    if player == 'X':
        best = -1000
        for neighbour in neighbours(board, player):
            best = max(best, minimax(neighbour, depth+1, alpha, beta, 'O'))
            alpha = max(alpha, best)
            if beta <= alpha:
                break
        return best
    else:
        best = 1000
        for neighbour in neighbours(board, player):
            best = min(best, minimax(neighbour, depth+1, alpha, beta, 'X'))
            beta = min(beta, best)
            if beta <= alpha:
                break
        return best

    
def bestMove(board, player):
    best_val = -1000
    best_move = -1
    for i, neighbour in enumerate(neighbours(board, player)):
        move_val = minimax(neighbour, 0, -1000, 1000, player)
        if move_val > best_val:
            best_move = i
            best_val = move_val
    
    available_moves = [i for i, cell in enumerate(board) if cell == '-']
    return available_moves[best_move]



def take_input(board):
    while True:
        try:
            pos = int(input("Enter the position: "))
            if pos < 0 or pos > 8:
                print("Enter a valid position")
                continue
            if board[pos] != '-':
                print("Position already taken")
                continue
            break
        except ValueError:
            print("Enter a valid position")
    return pos

# player one is computer using minimax
def user1Move(board):
    pos = bestMove(board, 'X')
    board[pos] = 'X'
    return board

def user2Move(board):
    pos = take_input(board)
    board[pos] = 'O'
    return board

print_board(Initial_board)
while True:
    Initial_board = user1Move(Initial_board)
    print_board(Initial_board)
    if checkWin(Initial_board):
        print("User 1 wins")
        break
    if '-' not in Initial_board:
        print("Draw")
        break
    
    Initial_board = user2Move(Initial_board)
    print_board(Initial_board)
    if checkWin(Initial_board):
        print("User 2 wins")
        break
    if '-' not in Initial_board:
        print("Draw")
        break
