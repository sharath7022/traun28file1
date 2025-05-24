def print_board(board):
    print("\n  0   1   2")
    for i in range(3):
        print(i, end=" ")
        for j in range(3):
            print(board[i][j], end=" ")
            if j < 2:
                print("|", end=" ")
        print()
        if i < 2:
            print("  ---|---|---")
    print()

def check_win(board, player):
    # Check rows and columns
    for i in range(3):
        if all([spot == player for spot in board[i]]):
            return True
        if all([board[j][i] == player for j in range(3)]):
            return True
    # Check diagonals
    if all([board[i][i] == player for i in range(3)]):
        return True
    if all([board[i][2 - i] == player for i in range(3)]):
        return True
    return False

def check_draw(board):
    for row in board:
        if ' ' in row:
            return False
    return True

def switch_player(player):
    return 'O' if player == 'X' else 'X'

def play_game():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    current_player = 'X'
    while True:
        print_board(board)
        try:
            row, col = map(int, input(f"Player {current_player}, enter row and column (0-2): ").split())
            if row not in range(3) or col not in range(3) or board[row][col] != ' ':
                print("Invalid move! Try again.")
                continue
        except ValueError:
            print("Invalid input! Please enter two numbers separated by space.")
            continue

        board[row][col] = current_player

        if check_win(board, current_player):
            print_board(board)
            print(f"Player {current_player} wins!")
            break
        if check_draw(board):
            print_board(board)
            print("It's a draw!")
            break
        current_player = switch_player(current_player)

if __name__ == "__main__":
    play_game()
