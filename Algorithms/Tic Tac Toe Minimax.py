def evaluate(board):
    # Check rows
    for i in range(0, 9, 3):
        if board[i] == board[i+1] == board[i+2] != '-':
            return 1 if board[i] == 'X' else -1
    # Check columns
    for i in range(3):
        if board[i] == board[i+3] == board[i+6] != '-':
            return 1 if board[i] == 'X' else -1
    # Check diagonals
    if board[0] == board[4] == board[8] != '-' or board[2] == board[4] == board[6] != '-':
        return 1 if board[4] == 'X' else -1
    return 0

def minimax(board, depth, alpha, beta, maximizingPlayer):
    score = evaluate(board)
    if score == 1:
        return score - depth
    if score == -1:
        return score + depth
    if '-' not in board:
        return 0

    if maximizingPlayer:
        maxEval = -2
        for i in range(0, 9):
            if board[i] == '-':
                board[i] = 'X'
                eval = minimax(board, depth + 1, alpha, beta, False)
                board[i] = '-'
                maxEval = max(maxEval, eval)
                alpha = max(alpha, eval)
                if beta <= alpha:
                    break
        return maxEval
    else:
        minEval = 2
        for i in range(0, 9):
            if board[i] == '-':
                board[i] = 'O'
                eval = minimax(board, depth + 1, alpha, beta, True)
                board[i] = '-'
                minEval = min(minEval, eval)
                beta = min(beta, eval)
                if beta <= alpha:
                    break
        return minEval

def bestMove(board, player):
    value = -2
    move = -1
    for i in range(0, 9):
        if board[i] == '-':
            board[i] = player
            moveValue = minimax(board, 0, -2, 2, 'O')
            board[i] = '-'
            if moveValue > value:
                value = moveValue
                move = i
    return move


def print_board(board):
    print(board[0:3])
    print(board[3:6])
    print(board[6:9])

# Test the functions with a game
# Test the functions with a game
board = ['-' for _ in range(9)]
player = 'X'
while True:
    print_board(board)
    if '-' not in board:
        print("Draw!")
        break
    if player == 'X':  # AI's turn
        move = bestMove(board, player)
        board[move] = player
        if evaluate(board) != 0:
            print(f"{player} wins!")
            break
    else:  # User's turn
        move = int(input("Enter your move (0-8): "))
        while board[move] != '-':
            print("Invalid move. Try again.")
            move = int(input("Enter your move (0-8): "))
        board[move] = player
        if evaluate(board) != 0:
            print(f"{player} wins!")
            break
    player = 'O' if player == 'X' else 'X'