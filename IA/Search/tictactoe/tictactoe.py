"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    counter_X = 0
    counter_O = 0
    for line in board:
        for block in line:
            if block == X:
                counter_X += 1
            if block == O:
                counter_O += 1
    if counter_O == counter_X:
        return X
    return O


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    possible_actions = set()
    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                possible_actions.add((i, j))
    return possible_actions


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action not in actions(board):
        raise Exception("Not valid action")
    new_board = copy.deepcopy(board)
    new_board[action[0]][action[1]] = player(board)
    return new_board
    

def checkRow(board, player):
    for row in range(3):
        if board[row][0] == player and board[row][1] == player and board[row][2] == player:
            return True
    return False


def checkCol(board, player):
    for col in range(3):
        if board[0][col] == player and board[1][col] == player and board[2][col] == player:
            return True
    return False



def checkDiagonals(board, player):
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    elif board[2][0] == player and board[1][1] == player and board[0][2] == player:
        return True
    else:
        return False

def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    if checkCol(board, X) or checkDiagonals(board, X) or checkRow(board, X):
        return X
    elif checkCol(board, O) or checkDiagonals(board, O) or checkRow(board, O):
        return O
    else:
        return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    if winner(board) == X or winner(board) == O:
        return True
    
    if len(actions(board)) == 0:
        return True
    else:
        return False


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    win = winner(board)
    if win == X:
        return 1
    elif win == O:
        return -1
    else:
        return 0


def max_value(board):
    v = -math.inf
    if(terminal(board)):
        return utility(board)
    for action in actions(board):
        v = max(v , min_value(result(board, action)))
        if v == 1:
            # print(f"Max: {v}")
            return v
    # print(f"Max: {v}")
    return v


def min_value(board):
    v = math.inf
    if(terminal(board)):
        return utility(board)
    for action in actions(board):
        v = min(v , max_value(result(board, action)))
        if v == -1:
            # print(f"Min: {v}")
            return v        
    # print(f"Min: {v}")
    return v    


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    # print("New play")
    if terminal(board):
        return None
    
    else:
        if player(board) == X:
            plays = []
            for action in actions(board):
                plays.append([min_value(result(board, action)), action])
            return sorted(plays, key=lambda x: x[0], reverse=True)[0][1]
        elif player(board) == O:
            plays = []
            for action in actions(board):
                plays.append([max_value(result(board, action)), action])
            return sorted(plays, key=lambda x: x[0], reverse=False)[0][1]

    
    
        
